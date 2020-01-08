#include "Decomp.hpp"
#include <cmath>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <utility>
#include <random>

#include <pagmo/exceptions.hpp>
#include <pagmo/problem.hpp>
#include <pagmo/problems/schwefel.hpp>
#include <pagmo/s11n.hpp>
#include <pagmo/types.hpp>

using namespace std;

namespace pagmo {


double sum(const vector_double& input)
{

    double sum = 0;
    for (auto& var_val : input) {
        sum += var_val;
    }
    return sum;
}

Decomp::Decomp(int dim, const Hypergraph& hypergraph) : m_dim(dim), HG(hypergraph)
{
    if (dim < 1u) {
        pagmo_throw(std::invalid_argument,
                    "Decomp Function must have minimum 1 dimension, " + std::to_string(dim) + " requested");
    }
    num_nodes = HG.getHGNodes().size();
    num_edges = HG.getHGEdges().size();
}

vector_double Decomp::fitness(const vector_double& dv) const
{

    vector_double objective;
    // updateHG(dv);
    HG.partition(dv);
    double largest_partition = double(HG.getLargestPartition());
    double sum_x = sum(dv);
    objective.push_back(largest_partition);
    objective.push_back(sum_x);
    // double c1;
    // for (int i =0; i<dv.size(); i++){
    //     c1 += dv[i];
    // }
    // c1 = c1 - (343);

    // objective.push_back(c1); // sum(dv) <= 0.7 * no. of constraints
    //objective.push_back(largest_partition - (0.5*(HG.getHGNodes().size())));
    return objective;
}

vector<vector<double>> Decomp::greedy_seeding(){
    
    int total_num_nodes = HG.getHGNodes().size();
    int total_num_edges = HG.getHGEdges().size();
    vector<double> percentages = {0.05, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    vector<vector<double>> initial_population;
    for (int i =0; i<percentages.size(); i++){
        vector<double> individual;
        individual.resize(total_num_edges, 0);
        initial_population.push_back(individual);
    }

    std::vector<HG_Edge> edges = HG.getHGEdges();
    std::vector<HG_Edge> edges_copy;
    for (auto& edge : edges){
        edges_copy.push_back(HG_Edge{edge.getEdgeIdx(), edge.getNodeIdxs()});
    }

    std::sort(edges_copy.begin(),edges_copy.end(), greater <HG_Edge>());
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    int individual_idx = 0;
    for (auto& percentage : percentages){
        //assign 1's
        int count = 0;
        while(count < (percentage*total_num_edges)){
            for (auto& edge : edges_copy){
                if (count > (percentage*total_num_edges)){
                    break;
                }
                int edge_idx = edge.getEdgeIdx();
                int num_nodes_in_edge = edges_copy[edge_idx].getNodeIdxs().size();
                // cout << "total number of nodes =  " << total_num_nodes << endl;
                // cout << "total number of nodes in edge " << edge_idx << " = " << num_nodes_in_edge << endl;
                // cout << "percentage * total_num_edges = " << percentage * total_num_edges << endl;
                double probability = (num_nodes_in_edge/ double(total_num_nodes)) * (percentage * total_num_edges);
                double random_num = dis(gen);
                // cout << "probability = " << probability << " random number = " << random_num << endl;
                if (random_num < probability){
                    initial_population[individual_idx][edge_idx] = 1;
                    count++;
                }
            }
        }
        individual_idx++;
    }
    return initial_population;
}

std::pair<vector_double, vector_double> Decomp::get_bounds() const
{
    vector_double lb(m_dim, 0);
    vector_double ub(m_dim, 1);
    return {lb, ub};
}

vector_double::size_type Decomp::get_nix() const
{
    return size_t(m_dim);
}

template <typename Archive>
void Decomp::serialize(Archive& ar, unsigned)
{
    ar& m_dim;
}

} // namespace pagmo



