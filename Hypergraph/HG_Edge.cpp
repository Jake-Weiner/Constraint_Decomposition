#include "HG_Edge.h"
#include <iostream>
using namespace std;



vector<int> HG_Edge::getNodeIdxs(){
    return node_idxs;
}

int HG_Edge::getEdgeIdx(){
    return edge_idx;
}

void HG_Edge::printNodes(){
    cout << "Edge Contains Nodes - "; 
    for (auto& node : node_idxs){
        cout << node << " ";
    }
    cout << endl;
}