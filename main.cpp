
#include "Hypergraph.h"
#include "Hypergraph_Fileparser.h"
#include "Decomp.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <pagmo/algorithm.hpp>
#include <pagmo/algorithms/nsga2.hpp>
#include <pagmo/archipelago.hpp>
#include <pagmo/problem.hpp>

using namespace pagmo;

int main(int argc, const char** argv)
{
    Hypergraph_Fileparser HGFP;
    HGFP.parse(file_type::MPS, "/home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/air05.mps");
    // HGFP.parse(file_type::USER, "/home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/test_input");

    Hypergraph HG(HGFP.getHGEdges(),HGFP.getHGNodes());
    //HG.printEdges();


    //HG.printEdges();


    
   
    // cout << "Largest Partition is size - " << HG.getLargestPartition(constraints,true) << endl;
   
  
    // cout << "Largest Partition is size - " << HG.getLargestPartition(constraints2,true) << endl;
  
   
    // cout << "Largest Partition is size - " << HG.getLargestPartition(constraints3,true) << endl;
   
   
    Decomp udp = Decomp(HG.getNumEdges(),HG);
    problem prob{udp};




    // // 2 - Instantiate a pagmo algorithm
    algorithm algo{nsga2(200)};

    population pop{prob, 32};

    // 4 - Evolve the population
    pop = algo.evolve(pop);

    // 5 - Output the population
    std::cout << "The population: \n" << pop;

    std::vector<vector<double>> x_vals =  pop.get_x();
   std::vector<vector<double>> f_vals = pop.get_f();

    for (auto& individuals_x : x_vals){
        for (auto& x_val : individuals_x){
            cout << x_val << " ";
        }
        cout << endl;
    }
   

    return 0;
}