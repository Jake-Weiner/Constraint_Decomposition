
#include "Hypergraph.h"
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
    Hypergraph HG;
    HG.initHypergraph("/home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/test_input");

    //HG.printEdges();

    vector<double> constraints = {0,0,0,0,0};
    vector<double> constraints2 = {1,1,1,1,1};
    vector<double> constraints3 = {0,0,0,0,0};
    
   
    cout << "Largest Partition is size - " << HG.getLargestPartition(constraints,true) << endl;
    HG.partitionWithRelaxation(constraints2);
  
    cout << "Largest Partition is size - " << HG.getLargestPartition(constraints2,true) << endl;
    HG.partitionWithRelaxation(constraints3);
   
    cout << "Largest Partition is size - " << HG.getLargestPartition(constraints3,true) << endl;
   
   
    Decomp udp = Decomp(HG.getNumEdges(),HG);
    problem prob{udp};


    //;Decomp
    // problem prob{Decomp(HG.getNumEdges(),HG)};

    // 2 - Instantiate a pagmo algorithm
    algorithm algo{nsga2(100)};

    population pop{prob, 64};

    // 4 - Evolve the population
    pop = algo.evolve(pop);

    // 5 - Output the population
    std::cout << "The population: \n" << pop;

    return 0;
}