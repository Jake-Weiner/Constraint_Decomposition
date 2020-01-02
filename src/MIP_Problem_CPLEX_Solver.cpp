#include "MIP_Problem_CPLEX_Solver.h"
#include <ilcplex/ilocplex.h>
#include <algorithm>


using namespace std;


void MIP_Problem_CPLEX_Solver::solve()
{
    IloEnv env;
    IloModel model(env);
    IloNumVarArray subproblem_vars_cplex(env);
    IloRangeArray subproblem_constraints_cplex(env);
    // add all variables in original problem to CPLEX environment
    cout << "number of variables in mip are " << MP.getNumVariables() << endl;


    //ensure that variables are ordered before adding to model
    vector<Variable> variables = MP.variables;
    sort(variables.begin(),variables.end());

    for (auto& var : variables) {
        cout << "var idx is " << var.getVarIndx() << endl;
        double var_lb = var.getLB();
        double var_ub = var.getUB();
        IloNumVar x(env, var_lb, var_ub, ILOINT);
        subproblem_vars_cplex.add(x);        
    }

    //add all constraints to the model
    int constraints_added = 0;
    for (auto& constraint : MP.constraints) {
        IloNumExpr constraint_exp(env);
        for(auto& term: constraint.getConTerms()){
            int var_idx = term.first;
            double var_coeff = term.second;
            constraint_exp += (var_coeff * subproblem_vars_cplex[var_idx]);
        }

        cout << "const exp is " << constraint_exp << " : RHS is " << constraint.getRHS() << endl;

        double RHS = constraint.getRHS();

        if (constraint.getBoundType() == Greater) {
            IloRange r1(env, RHS, constraint_exp, 99999999999999);
            subproblem_constraints_cplex.add(r1);
            constraints_added++;
        } else if (constraint.getBoundType() == Equal) {
            IloRange r1(env, RHS, constraint_exp, RHS);
            subproblem_constraints_cplex.add(r1);
            constraints_added++;
        } else if (constraint.getBoundType() == Less) {
            IloRange r1(env, -999999999999,constraint_exp, RHS);
            subproblem_constraints_cplex.add(r1);
            constraints_added++;
        }
      
    }
    cout << "number of constraints added is " << constraints_added << endl;
    model.add(subproblem_constraints_cplex);
    
    // add objective function to cplex model
    IloNumExpr obj_exp(env);
    int obj_term_count = 0;
    for (auto& obj_term : MP.objective_fn){
        int var_idx = obj_term.first;
        double coeff = obj_term.second;
        obj_exp += (coeff * subproblem_vars_cplex[var_idx]);
        obj_term_count++;
    }
    cout << "number of objective function terms is " << obj_term_count << endl;
    IloObjective obj_fn = IloMinimize(env, obj_exp);
    model.add(obj_fn);

    IloCplex cplex(model);
    cplex.exportModel("mps_test.lp");
    cplex.setParam(IloCplex::Threads, 4); // solve using 1 thread only
    // cplex.setOut(env.getNullStream());
    if (!cplex.solve()) {
        cout << "Failed to optimize LP" << endl;
        throw(-1);
    }
    cout << "Solution status = " << cplex.getStatus() << endl;
    cout << "Solution value  = " << cplex.getObjValue() << endl;
}

