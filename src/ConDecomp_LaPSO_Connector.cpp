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

ConDecomp_LaPSO_Connector::ConDecomp_LaPSO_Connector(MIP_Problem& original_problem, const vector<Partition_Struct>& partitions, const bool& printing)
{
    initOriginalCosts(original_problem);
    initSubproblems(original_problem, partitions);
    this->printing = printing;
}

void ConDecomp_LaPSO_Connector::initOriginalCosts(MIP_Problem& original_problem)
{

    cout << "number of objects in obj fn = " << original_problem.coeff_obj_fn.size() << endl;
    for (int i = 0; i < original_problem.coeff_obj_fn.size(); i++) {
        original_costs.push_back(original_problem.coeff_obj_fn[i]);
    }
}

//generate variable information for subproblem

void ConDecomp_LaPSO_Connector::initSubproblems(MIP_Problem& original_problem, const vector<Partition_Struct>& partitions)
{
    for (auto& partition : partitions) {
        CPLEX_MIP_Subproblem sp;

        IloEnv env;
        IloModel model(env);
        IloNumVarArray subproblem_vars_cplex(env);
        IloRangeArray subproblem_constraints_cplex(env);
        unordered_map<int, int> subproblemVarIdx_to_originalVarIdx;
        unordered_map<int, int> originalVarIdx_to_subproblemVarIdx;

        //variables involved in subproblem
        if (partition.node_idxs.empty()){
            cout << "error, empty var vector " << endl;
        }
        if (partition.edge_idxs.empty()){
            cout << "error, empty edge vector " << endl;
        }
        vector<Variable> original_variables_in_constraint;
        for (const auto& var_idx : partition.node_idxs) {
            original_variables_in_constraint.push_back(original_problem.getVariable(var_idx));
        }

        // add each variable to cplex model, if it hasn't been added previously
        int subproblem_var_idx = 0;
        for (auto& variable : original_variables_in_constraint) {
            int orig_var_idx = variable.getVarIndx();
            if (originalVarIdx_to_subproblemVarIdx.find(orig_var_idx) == originalVarIdx_to_subproblemVarIdx.end()) {
                double var_lb = variable.getLB();
                double var_ub = variable.getUB();
                originalVarIdx_to_subproblemVarIdx[orig_var_idx] = subproblem_var_idx;
                subproblemVarIdx_to_originalVarIdx[subproblem_var_idx] = orig_var_idx;
                IloNumVar x(env, var_lb, var_ub, ILOINT);
                subproblem_vars_cplex.add(x);
                subproblem_var_idx++;
            }
        }

        //constraints involved in subproblem
        vector<Constraint> subproblem_constraints;
        for (auto& constraint_idx : partition.edge_idxs) {
            cout << "constraint_idx is " << constraint_idx << endl;
            cout << "vector size is " << original_problem.constraints.size() << endl;
            subproblem_constraints.push_back(original_problem.constraints[constraint_idx]);
            // test - variables in the subproblem should appear in the constraints...
            for (auto& var_idx : original_problem.constraints[constraint_idx].getVarIndxs()){
                cout << "var index in model are " << var_idx << endl; 
                if (originalVarIdx_to_subproblemVarIdx.find(var_idx) == originalVarIdx_to_subproblemVarIdx.end()){
                    cout << "error, variable does not exist in model " << endl;
                }
            }
        }

        

        //add constraints to the model
        for (auto& constraint : subproblem_constraints) {
            IloExpr constraint_exp(env);

            for (int i = 0; i < constraint.getVarIndxs().size(); i++) {
                double var_coeff = (constraint.getVarCoeffs())[i];
                int sp_var_idx = originalVarIdx_to_subproblemVarIdx[(constraint.getVarIndxs())[i]];
                constraint_exp += (var_coeff * sp_var_idx);
            }

            if (constraint.getBoundType() == Greater) {
                IloRange r1(env, constraint_exp >= constraint.getRHS());
                subproblem_constraints_cplex.add(r1);
            } else if (constraint.getBoundType() == Equal) {
                IloRange r1(env, constraint_exp == constraint.getRHS());
                subproblem_constraints_cplex.add(r1);
            } else if (constraint.getBoundType() == Less) {
                IloRange r1(env, constraint_exp <= constraint.getRHS());
                subproblem_constraints_cplex.add(r1);
            }
        }
        model.add(subproblem_constraints_cplex);

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
    redCost += p.dual;
    return OK;
}

void solveSubproblemCplex(CPLEX_MIP_Subproblem& sp, DblVec& rc, IntVec& x)
{

    cout << "variables size is " << sp.variables.getSize() << endl;
    cout << "num variables is " << sp.num_subproblem_vars << endl;

    IloExpr obj_exp(sp.env);
    for (int i = 0; i < sp.variables.getSize(); i++) {
        //original index -- get coeff
        int original_var_idx = sp.subproblemVarIdx_to_originalVarIdx[i];
        double coeff = rc[original_var_idx];
        obj_exp += coeff * sp.variables[i];
    }

    IloObjective obj_fn = IloMinimize(sp.env, obj_exp);
    sp.model.add(obj_fn);

    IloCplex cplex(sp.model);
    cplex.setParam(IloCplex::Threads, 1); // solve using 1 thread only
    if (!cplex.solve()) {
        sp.env.error() << "Failed to optimize LP" << endl;
        throw(-1);
    }
    IloNumArray vals(sp.env);
    cout << "Solution status = " << cplex.getStatus() << endl;
    cout << "Solution value  = " << cplex.getObjValue() << endl;

    try {
        cplex.getValues(vals, sp.variables);
    } catch (IloException& e) {
        cout << e << endl;
    } catch (...) {
        cout << "Unknown exception caught" << endl;
    }

    sp.model.remove(obj_fn);
    //update x based on values;

    // create IloObjective based on RC
    // solve cplex...
    // update x...
}

Status ConDecomp_LaPSO_Connector::solveSubproblem(Particle& p_)
{

    ++nsolves;
    ConDecomp_LaPSO_ConnectorParticle& p(static_cast<ConDecomp_LaPSO_ConnectorParticle&>(p_));

    //clear previous primal sol
    p.x = 0; // clear would resize the array

    // p.ub = p.commodities.size();
    p.lb = 0;
    // // double max_perturb = 0.0;

    // for each subproblem, feed in new objective function, solve and update x

    for (auto& subproblem : MS) {

        // objective
        solveSubproblemCplex(subproblem, p.rc, p.x);
    }

    // // for (size_t i = 0; i < p.perturb.size(); i++) {
    // //     if (p.perturb[i] > max_perturb) {
    // //         max_perturb = p.perturb[i];
    // //         continue;
    // //     }
    // //     if (-1 * p.perturb[i] > max_perturb)
    // //         max_perturb = -1 * p.perturb[i];
    // // }

    // //solve subproblem selecting commodity iteration order randomly

    // p.viol = 1; // sets every violation to 1
    // for (size_t i = 0; i < p.x.size(); i++) {
    //     p.viol[] -= p.x[i]; // sum over all commodites
    // }

    // // is feasible if no edges are violated
    // p.isFeasible = (p.viol.min() >= 0);
    // p.lb = (total_paths_cost + p.dual.sum()) - num_edges * max_perturb;
    // //update particles best local solution
    // if (p.lb > p_.best_lb) {
    //     p_.best_lb = p.lb;
    //     double sum_viol = 0;
    //     for (int i = 0; i < p.viol.size(); i++) {
    //         // count every violation
    //         if (p.viol[i] < 0) {
    //             sum_viol += p.viol[i];
    //         }
    //     }
    //     p_.best_lb_viol = sum_viol;
    //     p_.best_lb_sol.resize(p.commodities.size());
    //     for (vector<Commodity>::iterator itr = p.commodities.begin(); itr < p.commodities.end(); ++itr) {
    //         p_.best_lb_sol[itr->comm_idx] = itr->solution_edges_nodes;
    //     }
    // }

    // if (p.isFeasible && (p.ub < p_.best_ub)) {
    //     p_.best_ub_sol.resize(p.commodities.size());
    //     for (vector<Commodity>::iterator itr = p.commodities.begin(); itr < p.commodities.end(); ++itr) {
    //         p_.best_ub_sol[itr->comm_idx] = itr->solution_edges_nodes;
    //     }

    //     p_.best_ub = p.ub;
    // }

    // if (printing == true) {
    //     std::cout << "Subproblem solve " << nsolves << "/" << maxsolves << ": "
    //               << " lb=" << p.lb << " ub=" << p.ub
    //               << "\trange of dual = " << p.dual.min() << " to " << p.dual.max() << std::endl
    //               << "\trange of viol = " << p.viol.min() << " to " << p.viol.max() << std::endl;
    //     if (!p.perturb.empty())
    //         std::cout << "\trange of perturb = " << p.perturb.min() << " to " << p.perturb.max() << std::endl;
    //     std::cout << "\tpath edge counts:";
    //     for (auto c = p.commodities.begin(); c != p.commodities.end(); ++c)
    //         std::cout << " " << c->solution_edges.size();
    //     std::cout << std::endl;
    // }

    return (nsolves < maxsolves) ? OK : ABORT;
}

Status ConDecomp_LaPSO_Connector::fixConstraint(const int constraint,
    const Particle& p,
    SparseVec& feas) { return OK; }

Status ConDecomp_LaPSO_Connector::heuristics(Particle& p_)
{

    return (nsolves < maxsolves) ? OK : ABORT;
}

Status ConDecomp_LaPSO_Connector::updateBest(Particle& p_)
{
    ConDecomp_LaPSO_ConnectorParticle& p(static_cast<ConDecomp_LaPSO_ConnectorParticle&>(p_));

    // if (printing == true)
    //     cout << "################## " << solution_cost << " ############\n";
    return OK;
}
