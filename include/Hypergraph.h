#ifndef __HG__
#define __HG__

#include <vector>
#include <string>
#include "HG_Node.h"
#include "HG_Edge.h"

using namespace std;

struct Partition_Struct{
    vector<int> node_idxs;
    vector<int> edge_idxs;
};

class Hypergraph {
public:
 
    Hypergraph(){};
    Hypergraph(vector<HG_Edge> HG_edges, vector<HG_Node> HG_nodes){

        this->HG_edges = HG_edges;
        this->HG_nodes = HG_nodes;
        this->num_nodes = HG_nodes.size();
        this->num_edges = HG_edges.size();
    };

    Hypergraph(int num_edges, int num_nodes){
        this->num_nodes = num_nodes;
        this->num_edges = num_edges;
        this->HG_nodes.resize(num_nodes);
        this->HG_edges.resize(num_edges);
    };
    
    void printEdges();
    void printNodes();
    void printPartitions();

    int getLargestPartition();
    void partition(const vector<double>& constraints_selected);
    
    vector<vector<int>> getPartitions(){
        return partitions;
    }

    vector<Partition_Struct> getPartitionStruct(){
        return PS;
    }
    
    int getNumEdges(){
        return HG_edges.size();
    };
    int getNumNodes(){
        return HG_nodes.size();
    };
    vector<HG_Edge> getHGEdges(){
        return HG_edges;
    };
    vector<HG_Node> getHGNodes(){
        return HG_nodes;
    };
    
private:
    vector<int> findPartition(const vector<HG_Edge>& edges_considered, const vector<HG_Node>& nodes_considered, 
    HG_Node starting_node, vector<bool>& node_idx_seen);
    int num_nodes;
    int num_edges;
    vector<HG_Edge> HG_edges;
    vector<HG_Node> HG_nodes;
    void printPartitions(vector<vector<int>> partitions);
    vector<vector<int>> identifyPartitions(const vector<HG_Edge>& edges, const vector<HG_Node>& nodes);
    vector<vector<int>> partitions;
    int largest_partition;
    vector<Partition_Struct> PS;
};


#endif