#ifndef __HG_Node__
#define __HG_Node__


#include <vector>

using namespace std;



class HG_Node {
public:

    HG_Node(){};
    HG_Node(int node_idx){
        this->node_idx = node_idx;
    };

    HG_Node(int node_idx, vector<int> edge_idxs){
        this->node_idx = node_idx;
        this->edge_idxs = edge_idxs;
    };

    void addEdgeIdx(int edge_idx);
    int getNodeIdx();
    vector<int> getEdgeIdxs();
    void removeEdgeIdx(int edge_idx);
private:
    int node_idx;
    vector<int> edge_idxs;
    
};


#endif