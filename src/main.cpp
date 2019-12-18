#include "ConDecomp_LaPSO_Connector.h"
#include "Decomp.hpp"
#include "DecompMIP.h"
#include "Hypergraph.h"
#include "MIP_Fileparser.h"
#include "MIP_to_Hypergraph.h"
#include "Random.h"
#include <fstream>
#include <iostream>
#include <pagmo/algorithm.hpp>
#include <pagmo/algorithms/nsga2.hpp>
#include <pagmo/archipelago.hpp>
#include <pagmo/problem.hpp>
#include <pagmo/utils/multi_objective.hpp>
#include <string>
#include <vector>
using namespace pagmo;

struct MIP_problems_to_solve {
    int max_subprobem_size;
    int max_num_subproblems;
    const char* output_file;
    int solver_time;
};

struct NSGA_ii_characteristics {
    int number_generations;
    int population_size;
    bool greedy;
};

void solve_generic_MIP(const char* MIP_filename)
{
    IloEnv env;
    IloModel model(env);
    IloCplex cplex(env);
    IloObjective obj;
    IloNumVarArray var(env);
    IloRangeArray rng(env);
    cplex.importModel(model, MIP_filename, obj, var, rng);
    cplex.setParam(IloCplex::Threads, 4); // solve using 1 thread only
    cplex.setParam(IloCplex::TiLim, 3600);
    cplex.extract(model);
    if (!cplex.solve()) {
        env.error() << "Failed to optimize LP" << endl;
        throw(-1);
    }

    IloNumArray vals(env);
    cplex.getValues(vals, var);
    env.out() << "Solution status = " << cplex.getStatus() << endl;
    env.out() << "Solution value  = " << cplex.getObjValue() << endl;
    env.out() << "Solution vector = " << vals << endl;
}

int main(int argc, const char** argv)
{
    MIP_Fileparser MIP_FP;
    MIP_FP.parse(file_type::MPS, "/home/jake/PhD/Decomposition/Constraint_Decomposition/test_input/neos-2657525-crna (1).mps");
    MIP_FP.printConstraints();
    MIP_FP.printVariables();
    MIP_Problem MP = MIP_FP.getMIPProblem();
    cout << "Number of constraints is " << MP.getNumConstraints() << endl;
    cout << "Number of variables is " << MP.getNumVariables() << endl;
    MIP_to_Hypergraph MTH;
    MTH.convertToHypergraph(MP);

    //HGFP.parse(file_type::USER, "/home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/test_input/test_input");

    Hypergraph HG(MTH.getHGEdges(), MTH.getHGNodes());

    // // solve decomposition using MIP
    // DecompMIP DM;
    // DecompInfo DI;

    // vector<MIP_problems_to_solve> instances;

    // instances.push_back({100,10,"/home/jake/PhD/Decomposition/Constraint_Decomposition/output/100.log",3600});
    // instances.push_back({150,10,"/home/jake/PhD/Decomposition/Constraint_Decomposition/output/150.log",3600});
    // instances.push_back({200,10,"/home/jake/PhD/Decomposition/Constraint_Decomposition/output/200.log",3600});
    // instances.push_back({250,10,"/home/jake/PhD/Decomposition/Constraint_Decomposition/output/250.log",3600});
    // instances.push_back({300,10,"/home/jake/PhD/Decomposition/Constraint_Decomposition/output/300.log",3600});
    // instances.push_back({350,10,"/home/jake/PhD/Decomposition/Constraint_Decomposition/output/350.log",3600});
    // instances.push_back({400,10,"/home/jake/PhD/Decomposition/Constraint_Decomposition/output/400.log",3600});

    // for(auto& instance : instances){
    //     DI = DM.solveMIP(HG.getHGEdges(),HG.getHGNodes(), instance.max_subprobem_size,
    //     instance.max_num_subproblems, true, instance.output_file, instance.solver_time);
    // }

    // // assume vector... is chosen

    // vector<double> decision_vector;

    //solve the generic MIP problem
    //solve_generic_MIP("/home/jake/PhD/Decomposition/Constraint_Decomposition/test_input/neos-2657525-crna (1).mps");

    //solve decomposition using NSGAii

    Decomp udp = Decomp(HG.getNumEdges(), HG);
    problem prob{ udp };

    // sort edges based on number of nodes contained

    // NSGA_ii_characteristics test = {100,100, true};

    // for multiple instances
    // vector<NSGA_ii_characteristics> nsga_instances;
    // for (auto& instance : nsga_instances){

    //     algorithm algo{nsga2(instance.number_generations)};

    //     algo.set_verbosity(1);

    //     population pop;

    //     if (instance.greedy == true){
    //         vector<vector<double>> greedy_population = udp.greedy_seeding();
    //         int pop_size_wo_greedy = instance.population_size - greedy_population.size();
    //         population pop_greedy{prob, pop_size_wo_greedy};
    //         for (auto& individual : greedy_population){
    //             pop_greedy.push_back(individual);

    //         }
    //         pop = pop_greedy;
    //     }
    //     else{
    //         population non_greedy{prob, instance.population_size};
    //         pop = non_greedy;
    //     }

    //     string output_filename_root = "/home/jake/PhD/Decomposition/Constraint_Decomposition/output/nsgaii_";
    //     string gen_num = to_string(instance.number_generations);
    //     string pop_size = to_string(instance.population_size);
    //     string greedy;
    //     if (instance.greedy == true){
    //         greedy = "greedy";
    //     }
    //     else{
    //         greedy = "";
    //     }
    //     string output_filename = output_filename_root + gen_num + "_" + pop_size + "_" + greedy + ".csv";
    //     // 4 - Evolve the population
    //     pop = algo.evolve(pop);

    //     std::vector<vector<double>> x_vals =  pop.get_x();
    //     std::vector<vector<double>> f_vals = pop.get_f();
    //     // std::ofstream outfile;
    //     // outfile.open(output_filename);
    //     // for (auto& idx : front1){
    //     //     outfile << f_vals[idx][1] << "," << f_vals[idx][0] << endl;
    //     // }
    //     // 5 - Output the population
    //     std::cout << "The population: \n" << pop;
    // }

    algorithm algo{nsga2(50)};

    algo.set_verbosity(1);

    population pop{prob, 8};
    pop = algo.evolve(pop);
    std::vector<vector<double>> x_vals = pop.get_x();
    vector<double> x1 = x_vals[0];

    HG.partition(x1);
    HG.printPartitions();
    

    // print partitions to see what they look like...

    ConDecomp_LaPSO_Connector CLC(MP, HG.getPartitionStruct(), false);
    LaPSO::Problem solver(HG.getNumNodes(), HG.getNumEdges()); // number of variables & (relaxed) constraints
    //-------- set default parameter values
    solver.param.absGap = 0.999; // any two solutions must differ by at least 1
    solver.param.printFreq = 1;
    solver.param.printLevel = 1;
    solver.param.heurFreq = 1;
    solver.param.localSearchFreq = 3;
    solver.param.maxIter = 200;
    solver.param.subgradFactor = 0.01; // start with a small step size
    solver.param.subgradFmin = 0.0001; // allow very small steps
    // override defaults with command line arguments
    // solver.param.parse(argc, argv);

    bool printing = solver.param.printLevel > 0;
    CLC.setPrinting(printing);
    CLC.maxsolves = solver.param.maxIter;

    solver.best.lb = 0; // no path left out
    solver.dualUB = 0; // all constraints are <= so lagrange multipliers are <= 0

    Uniform rand;
    if (solver.param.randomSeed == 0)
        rand.seedTime();
    else
        rand.seed(solver.param.randomSeed);
    double max_initial_dual = 1.0;
    double initial_dual = 0.0;
    for (int i = 0; i < solver.param.nParticles; ++i) {
        ConDecomp_LaPSO_ConnectorParticle* p = new ConDecomp_LaPSO_ConnectorParticle(HG.getNumNodes(), HG.getNumEdges());
        for (int j = 0; j < solver.dsize; ++j) {
            initial_dual = -rand(0, 1);

            p->dual[j] = initial_dual; // random initial point
            // if (initial_dual < max_initial_dual) {
            //     max_initial_dual = initial_dual;
            // }
        }
        solver.swarm.push_back(p);
    }
    std::cout << "set up solver with " << solver.param.nParticles
              << " particles"
              << " using veloctiy factor of " << solver.param.velocityFactor << endl;

    solver.solve(CLC);

    //if (printing == true) { // always show the final result
    std::cout << "Best solution missing " << solver.best.ub
              << " paths, lower bound " << solver.best.lb
              << std::endl
              << "CPU time = " << solver.cpuTime()
              << " elapsed = " << solver.wallTime() << " sec"
              << " primal cpu time " << solver.primal_cpu_time
              << " dual cpu time " << solver.dual_cpu_time
              << std::endl;

    // auto fnds_res = fast_non_dominated_sorting(pop.get_f());
    // auto ndf = std::get<0>(fnds_res); // non dominated fronts [[0,3,2],[1,5,6],[4],...]

    // auto front1 = ndf[0];

    // }

    return 0;
}