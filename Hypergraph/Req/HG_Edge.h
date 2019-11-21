#ifndef __HG_Edge__
#define __HG_Edge__


#include <vector>

using namespace std;



class HG_Edge {
public:
    HG_Edge(){};
    HG_Edge(int edge_idx, vector<int> node_idxs){
        this->edge_idx = edge_idx;
        this->node_idxs = node_idxs;
    }

    int getEdgeIdx();
    vector<int> getNodeIdxs();
    void printNodes();

private:
    int edge_idx;
    vector<int> node_idxs;
};


#endif