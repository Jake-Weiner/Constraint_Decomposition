#include "ConDecomp_LaPSO_Connector.h"
#include "Random.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <list>
#include <map>

#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif
#include <cstdlib>
#include <memory>
#include <string>

using namespace boost;
using namespace std;

ConDecomp_LaPSO_Connector::ConDecomp_LaPSO_Connector(MIP_Problem& original_problem, const vector<Partition_Struct>& partitions, 
    const bool& printing)
{   
    this->OP = original_problem;
    this->printing = printing;
    initOriginalCosts();
    initSubproblems(partitions);
   
    
}

void ConDecomp_LaPSO_Connector::initOriginalCosts()
{
    original_costs.resize(OP.getNumVariables(), 0);
    for (auto& objective_term : OP.objective_fn){
        int var_idx = objective_term.first;
        double var_coeff = objective_term.second;
        original_costs[var_idx] = var_coeff;
    }
}




void ConDecomp_LaPSO_Connector::initSubproblems(const vector<Partition_Struct>& partitions)
{
    for (auto& partition : partitions) {
        CPLEX_MIP_Subproblem sp;

        IloEnv env;
        IloModel model(env);
        IloNumVarArray subproblem_vars_cplex(env);
        IloRangeArray subproblem_constraints_cplex(env);
        unordered_map<int, int> subproblemVarIdx_to_originalVarIdx;
        unordered_map<int, int> originalVarIdx_to_subproblemVarIdx;

        // add all variables in partition to subproblem model
        vector<Variable> var_in_partition;
        for (const auto& var_idx : partition.node_idxs) {
            var_in_partition.push_back(OP.getVariable(var_idx));
        }
        int subproblem_var_idx = 0;
        for (auto& variable : var_in_partition) {
            int orig_var_idx = variable.getVarIndx();
            double var_lb = variable.getLB();
            double var_ub = variable.getUB();
            originalVarIdx_to_subproblemVarIdx[orig_var_idx] = subproblem_var_idx;
            subproblemVarIdx_to_originalVarIdx[subproblem_var_idx] = orig_var_idx;
            IloNumVar x(env, var_lb, var_ub, ILOINT);
            subproblem_vars_cplex.add(x);
            subproblem_var_idx++;
            
        }

        //add constraints to subproblem
        vector<Constraint> subproblem_constraints;
        if (!partition.edge_idxs.empty()) {
            for (auto& constraint_idx : partition.edge_idxs) {
                subproblem_constraints.push_back(OP.constraints[constraint_idx]);
                // test - variables in the constraints should appear in the subproblem...
                // for (auto& var_idx : OP.constraints[constraint_idx].getVarIndxs()) {
                //     if (originalVarIdx_to_subproblemVarIdx.find(var_idx) == originalVarIdx_to_subproblemVarIdx.end()) {
                //         cout << "error, variable " << var_idx << " does not exist in model " << endl;
                //         cout << "constraint idx is " << constraint_idx << endl;
                //         cout << "variable should be found in one/more of constraints: ";
                //         for (auto& temp_part : partitions) {
                //             for (auto& temp_var_idx : temp_part.node_idxs) {
                //                 if (temp_var_idx == var_idx) {
                //                     for (auto& temp_con_idx : temp_part.edge_idxs) {
                //                         cout << temp_con_idx << " ";
                //                     }
                //                 }
                //             }
                //         }
                //         cout << endl;
                //     }
                // }
            }

            //add constraints to the model
            for (auto& constraint : subproblem_constraints) {
                IloExpr constraint_exp(env);

                for(auto& term: constraint.getConTerms()){
                    int var_idx = term.first;
                    double var_coeff = term.second;
                    int var_idx_in_sp = originalVarIdx_to_subproblemVarIdx[var_idx];
                    constraint_exp += (var_coeff * subproblem_vars_cplex[var_idx_in_sp]);
                }
            
                if (constraint.getBoundType() == Greater) {
                    IloRange r1(env, constraint.getRHS(), constraint_exp, INF);
                    subproblem_constraints_cplex.add(r1);
                } else if (constraint.getBoundType() == Equal) {
                    IloRange r1(env, constraint.getRHS() , constraint_exp, constraint.getRHS() );
                    subproblem_constraints_cplex.add(r1);
                } else if (constraint.getBoundType() == Less) {
                    IloRange r1(env, -INF,constraint_exp ,constraint.getRHS());
                    subproblem_constraints_cplex.add(r1);
                }
            }

            model.add(subproblem_constraints_cplex);
        }

        // save model and dictionaries to subproblem structure and save these to the MIP_subproblems vector
        sp.env = env;
        sp.model = model;
        sp.variables = subproblem_vars_cplex;
        sp.subproblemVarIdx_to_originalVarIdx = subproblemVarIdx_to_originalVarIdx;
        sp.originalVarIdx_to_subproblemVarIdx = originalVarIdx_to_subproblemVarIdx;
        sp.num_subproblem_vars = subproblem_var_idx;
        MS.push_back(sp);
    }
    return;
}

Status ConDecomp_LaPSO_Connector::reducedCost(const Particle& p, DblVec& redCost)
{
    
    redCost = original_costs;
    // DblVec red_cost_temp = original_costs;
    // redCost = original_costs;
    // for each constraint, update the red cost by dual[i] * coeff in constraint
    for (auto& constraint : OP.constraints){
        int constraint_idx = constraint.getConIdx();
        for (auto& con_term : constraint.getConTerms()){
            int var_idx = con_term.first;
            double var_coeff = con_term.second;
            redCost[var_idx] += p.dual[constraint_idx] *(-1 * var_coeff);
        }
    }
    return OK;
}

void ConDecomp_LaPSO_Connector::solveSubproblemCplex(CPLEX_MIP_Subproblem& sp, DblVec& rc, IntVec& x)
{

    // cout << "variables size is " << sp.variables.getSize() << endl;
    // cout << "num variables is " << sp.num_subproblem_vars << endl;
    
    //if subproblem size is 1 solve without cplex
    if (sp.variables.getSize() == 1){
        int original_var_idx = sp.subproblemVarIdx_to_originalVarIdx[0];
        double coeff = rc[original_var_idx];
        // if negative coeff, set to max var bound
        Variable var = OP.getVariable(original_var_idx);
        double upper_bound = var.getUB();
        double lower_bound = var.getLB();

        if (coeff < 0){
            x[original_var_idx] = upper_bound;
        }
        else if (coeff > 0){
            x[original_var_idx] = lower_bound;
        }
        else{
            x[original_var_idx] = 0;
        }
        return;
    }
    // add in objective function to the model...
    IloExpr obj_exp(sp.env);
    for (int i = 0; i < sp.variables.getSize(); i++) {
        //original index -- get coeff
        int original_var_idx = sp.subproblemVarIdx_to_originalVarIdx[i];
        double coeff = rc[original_var_idx];
        // if (coeff == 0){
        //     cout << "0 coefficient detected" << endl;
        // }
        obj_exp += (coeff * sp.variables[i]);
    }

    IloObjective obj_fn = IloMinimize(sp.env, obj_exp);
    sp.model.add(obj_fn);

    IloCplex cplex(sp.model);
    cplex.setParam(IloCplex::Threads, 1); // solve using 1 thread only
    cplex.setOut(sp.env.getNullStream());
    if (!cplex.solve()) {
        cout << "Failed to optimize LP" << endl;
        throw(-1);
    }
    
    // cout << "Solution status = " << cplex.getStatus() << endl;
    // cout << "Solution value  = " << cplex.getObjValue() << endl;

    for (int i = 0; i< sp.variables.getSize(); i++){
        int orig_idx = sp.subproblemVarIdx_to_originalVarIdx[i];
        try{
            IloNum val = cplex.getValue(sp.variables[i]);
            // cout << "index " << i << "has value of " << val << endl;
            int x_val = int(val);
            x[orig_idx] = x_val;
        }
        catch (IloException& e) {
            int x_val = 0;
            x[orig_idx] = x_val;
            // cout << e << endl;
            // cout << "number of variables is " << sp.variables.getSize() << endl;
        } catch (...) {
            cout << "Unknown exception caught" << endl;
        }
    }
    sp.model.remove(obj_fn);
    //update x based on values;

    // create IloObjective based on RC
    // solve cplex...
    // update x...
}

void ConDecomp_LaPSO_Connector::updateParticleLB(ConDecomp_LaPSO_ConnectorParticle& p){
    //(the reduced costs * x ) +  1b  +  2 e +  3 g
    double lb = 0;
    for (int var_idx = 0; var_idx < p.x.size(); var_idx++){
        lb += (p.x[var_idx] * p.rc[var_idx]);
    }
    for (int dual_idx = 0; dual_idx < p.dual.size(); dual_idx++){
        double constraint_bound = OP.constraints[dual_idx].getRHS();
        lb += (p.dual[dual_idx] * constraint_bound);
    }
    p.lb = lb;
    
    // double lb_test = 0;
    // for (int var_idx = 0; var_idx < p.x.size(); var_idx++){
    //     lb_test += (p.x[var_idx] * original_costs[var_idx]);
    // }

    // for (int dual_idx = 0; dual_idx < p.dual.size(); dual_idx++){
    //     double constraint_bound = OP.constraints[dual_idx].getRHS();
    //     lb_test += (p.dual[dual_idx] * p.viol[dual_idx]);
    // }

    // cout << "reduced costs lb = " << p.lb << " : violation lb = " << lb_test << endl ;
    // check that ~cx + \lambda(bounds) = cx + \lambda(viol)
}

// loop through all constraints, calculate Ax, viol = bound - Ax
void ConDecomp_LaPSO_Connector::updateParticleViol(ConDecomp_LaPSO_ConnectorParticle& p){
    p.viol = 0;
    for (int constraint_idx = 0; constraint_idx < OP.getNumConstraints(); constraint_idx++){
        Constraint con = OP.constraints[constraint_idx];
        double constraint_bound = con.getRHS();
        //calculate constraint value
        double constraint_value = 0;

        for (auto& con_term : con.getConTerms()){
            int var_idx = con_term.first;
            double var_coeff = con_term.second;
            constraint_value += (var_coeff * p.x[var_idx]);
        }
        // cout << "constraint value is "<< constraint_value << " constraint bound is " << constraint_bound << endl;
        p.viol[constraint_idx] = constraint_bound - constraint_value;
    }
}

Status ConDecomp_LaPSO_Connector::solveSubproblem(Particle& p_)
{

    ++nsolves;
    ConDecomp_LaPSO_ConnectorParticle& p(static_cast<ConDecomp_LaPSO_ConnectorParticle&>(p_));

    //reset previous primal sol
    p.x = 0; 
   
    // for each subproblem, feed in new objective function, solve and update x

    for (auto& subproblem : MS) {
        // objective
        solveSubproblemCplex(subproblem, p.rc, p.x);
    }

    updateParticleViol(p);
    updateParticleLB(p);
    //update best particle
    if (p.lb > p_.best_lb) {
        p_.best_lb = p.lb;
    }

    if (printing == true) {
        std::cout << "Subproblem solve " << nsolves << "/" << maxsolves << ": "
                  << " lb=" << p.lb << " ub=" << p.ub
                  << "\trange of dual = " << p.dual.min() << " to " << p.dual.max() << std::endl
                  << "\trange of viol = " << p.viol.min() << " to " << p.viol.max() << std::endl;
        if (!p.perturb.empty())
            std::cout << "\trange of perturb = " << p.perturb.min() << " to " << p.perturb.max() << std::endl;
        std::cout << std::endl;
    }
    return (nsolves < maxsolves) ? OK : ABORT;
}

Status ConDecomp_LaPSO_Connector::fixConstraint(const int constraint,
    const Particle& p,
    SparseVec& feas) { return OK; }

Status ConDecomp_LaPSO_Connector::heuristics(Particle& p_)
{
    nsolves++;
    return (nsolves < maxsolves) ? OK : ABORT;
}

Status ConDecomp_LaPSO_Connector::updateBest(Particle& p_)
{
    ConDecomp_LaPSO_ConnectorParticle& p(static_cast<ConDecomp_LaPSO_ConnectorParticle&>(p_));

    // if (printing == true)
    //     cout << "################## " << solution_cost << " ############\n";
    return OK;
}
