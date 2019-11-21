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


