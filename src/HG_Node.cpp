#include "HG_Node.h"

using namespace std;


vector<int> HG_Node::getEdgeIdxs(){
    return edge_idxs;
}

void HG_Node::addEdgeIdx(int edge_idx){
    edge_idxs.push_back(edge_idx);
}

int HG_Node::getNodeIdx(){
    return node_idx;
}

void HG_Node::removeEdgeIdx(int edge_idx_remove){
    int idx = 0;
    int idx_edge_idx_remove = -1;
    for (auto& edge_idx : edge_idxs){
        if (edge_idx == edge_idx_remove){
            idx_edge_idx_remove = idx;
        }
        idx++;
    }
    if (idx_edge_idx_remove != -1){
        edge_idxs.erase(edge_idxs.begin() + idx_edge_idx_remove);
    }
}

