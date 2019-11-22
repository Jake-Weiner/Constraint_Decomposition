#ifndef __HG__
#define __HG__

#include <vector>
#include <string>
#include "HG_Node.h"
#include "HG_Edge.h"

using namespace std;

class Hypergraph {
public:

    Hypergraph(){};
    Hypergraph(vector<HG_Edge> HG_edges, vector<HG_Node> HG_nodes){
        this->HG_edges = HG_edges;
        this->HG_nodes = HG_nodes;
    };

    Hypergraph(int num_edges, int num_nodes){
        this->num_nodes = num_nodes;
        this->num_edges = num_edges;
        this->HG_nodes.resize(num_nodes);
        this->HG_edges.resize(num_edges);
    };
    
    void printEdges();
    void printNodes();
    void initHypergraph(string filename);
    int getLargestPartition(const vector<double>& constraints_selected, bool print = false);
    int getLargestPartition(bool print = false);
    
    void partitionWithRelaxation(vector<double> constraints_selected);
    void partitionWithoutRelaxation();
    int getNumEdges(){
        return num_edges;
    };
    
private:
    vector<int> findPartition(const vector<HG_Edge>& edges_considered, const vector<HG_Node>& nodes_considered, 
    HG_Node starting_node, vector<bool>& node_idx_seen);
    int num_nodes;
    int num_edges;
    vector<HG_Edge> HG_edges;
    vector<HG_Node> HG_nodes;
    void printPartitions(vector<vector<int>> partitions);
    void setNumEdges(int num_edges);
    bool constraintCheck(HG_Edge constraint_to_check);
    void setHGEdgesSize(int size);
    void setHGNodesSize(int size);
    void initNodes(int size);
    void initNonRelaxedEdges();
    vector<vector<int>> identifyPartitions(const vector<HG_Edge>& edges, const vector<HG_Node>& nodes);


};


#endif