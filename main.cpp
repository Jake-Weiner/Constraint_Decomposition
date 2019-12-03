#include "Hypergraph.h"
#include "Hypergraph_Fileparser.h"
#include "Decomp.hpp"
#include "DecompMIP.h"
#include <fstream>
#include <iostream>
#include <string>
#include <pagmo/algorithm.hpp>
#include <pagmo/algorithms/nsga2.hpp>
#include <pagmo/archipelago.hpp>
#include <pagmo/problem.hpp>
#include <vector>
using namespace pagmo;

int main(int argc, const char** argv)
{
    Hypergraph_Fileparser HGFP;
    HGFP.parse(file_type::MPS, "/home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/test_input/air05.mps");
    //HGFP.parse(file_type::USER, "/home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/test_input/test_input");

    Hypergraph HG(HGFP.getHGEdges(),HGFP.getHGNodes());
    
    // solve decomposition using MIP
    DecompMIP DM;
    DecompInfo DI = DM.solveMIP(HGFP.getHGEdges(),HGFP.getHGNodes(), 4000, 10);
    
     // solve decomposition using NSGAii

    // int total_num_nodes = HGFP.getHGNodes().size();
    // int total_num_edges = HGFP.getHGEdges().size();
    // vector<double> percentages = { 0.05, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    // vector<vector<double>> initial_population;
    // for (int i =0; i<percentages.size(); i++){
    //     vector<double> individual;
    //     individual.resize(total_num_edges, 0);
    //     initial_population.push_back(individual);
    // }


    // std::vector<HG_Edge> edges = HGFP.getHGEdges();
    // std::vector<HG_Edge> edges_copy;
    // for (auto& edge : edges){
    //     edges_copy.push_back(HG_Edge{edge.getEdgeIdx(), edge.getNodeIdxs()});
    // }

   
    // std::sort(edges_copy.begin(),edges_copy.end(), greater <HG_Edge>());

    // int individual_idx = 0;
    // for (auto& percentage : percentages){
    //     //assign 1's
    //     int count = 0;
    //     while(count < (percentage*total_num_edges)){
    //         int idx_to_set_to_1 = edges_copy[count].getEdgeIdx();
    //         initial_population[individual_idx][idx_to_set_to_1] = 1;
    //         count++;
    //     }
    //     individual_idx++;
    // }

//     Decomp udp = Decomp(HG.getNumEdges(),HG);
//     problem prob{udp};

//         // sort edges based on number of nodes contained


//     // // 2 - Instantiate a pagmo algorithm
//     algorithm algo{nsga2(10)};

//     algo.set_verbosity(1);

//     population pop{prob, 18};
//     for (auto& individual : initial_population){
//         pop.push_back(individual);
//     }

//     // 4 - Evolve the population
//     pop = algo.evolve(pop);

//     // 5 - Output the population
//     std::cout << "The population: \n" << pop;

//     std::vector<vector<double>> x_vals =  pop.get_x();
//    std::vector<vector<double>> f_vals = pop.get_f();

//     for (auto& individuals_x : x_vals){
//         for (auto& x_val : individuals_x){
//             cout << x_val << " ";
//         }
//         cout << endl;
//     }
   

    return 0;
}