#include "Hypergraph.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

void Hypergraph::identifyPartitions(const vector<HG_Node>& nodes)
{

    // // test for empty edges
    // if (HG_edges.empty()) {
    //     cout << "no edges selected to identify partitions" << endl;
    //     return;
    // }

    // List keeping track of seen edges
    vector<bool> edge_idx_seen;
    edge_idx_seen.resize(HG_edges.size(), false);
    // List keeping track of nodes seen
    vector<bool> node_idx_seen;
    node_idx_seen.resize(nodes.size(), false);
    //perform BFS on Hypergraph - stop when all nodes have been considered
    while (count(node_idx_seen.begin(), node_idx_seen.end(), true) != node_idx_seen.size()){

        // pick first unseen node iff it has an edge attached
        int node_idx_selected;
        for (int i = 0; i < node_idx_seen.size(); i++) {
            if (node_idx_seen[i] == false) {
                // if (nodes[i].getEdgeIdxsSize() == 0){
                //     node_idx_seen[i] = true;
                //     continue;
                // }
                node_idx_selected = i;
                break;
            }
        }

        HG_Node node_selected = nodes[node_idx_selected];
        node_idx_seen[node_idx_selected] = true;
        // find the partition with the the selected node belongs to
        findPartition(nodes, node_selected, node_idx_seen);
    }
    return;
}




void Hypergraph::findPartition(const vector<HG_Node>& nodes_considered,
 HG_Node starting_node,  vector<bool>& node_idx_seen)
{
    vector<bool> edge_idx_seen;
    edge_idx_seen.resize(HG_edges.size(), false);
    vector<int> node_partition;
    vector<int> edge_partition;
    
    node_partition.push_back(starting_node.getNodeIdx());
    queue<HG_Edge> Q;
    
    
    // add edges attached to node which haven't been seen before
    for (auto& edge_idx : starting_node.getEdgeIdxs()) {
        
        if (edge_idx_seen[edge_idx] == false) {
            Q.push(HG_edges[edge_idx]);
            // cout << "edge idx to be added " << edge_idx << endl;
            edge_partition.push_back(edge_idx);
            edge_idx_seen[edge_idx] = true;
        }
    }

    while (!Q.empty()) {
        HG_Edge current_edge = Q.front();
        // for each node in the hyperedge, add the node to the node_partition if it hasn't already been added
        for (auto& node_idx : current_edge.getNodeIdxs()) {
            if (node_idx_seen[node_idx] == false) {
                node_idx_seen[node_idx] = true;
                HG_Node new_node = nodes_considered[node_idx];
                int current_edge_idx = current_edge.getEdgeIdx();
                node_partition.push_back(new_node.getNodeIdx());
                bool edge_idx_exists = false;
                for (auto& edge_idx : edge_partition){
                    if (edge_idx == current_edge_idx){
                        edge_idx_exists = true;
                    }
                }
                if (edge_idx_exists == false){
                    edge_partition.push_back(current_edge_idx);
                }
                
                // add edges attached to the node to the queue if they haven't been seen previously
                for (auto& edge_idx : new_node.getEdgeIdxs()) {
                    if (edge_idx_seen[edge_idx] == false) {
                        Q.push(HG_edges[edge_idx]);
                        edge_idx_seen[edge_idx] = true;
                    }
                }
            }
        }
        Q.pop();
    }

    // if (edge_partition.empty()){
    //     cout << "empty edge partition" << endl;
    // }
    if (node_partition.empty()){
        cout << "empty node partition" << endl;
    }

    Partition_Struct ps = {node_partition, edge_partition};
    PS.push_back(ps);
    return;
}

void Hypergraph::printEdges()
{
    
    for (auto& edge : HG_edges) {
        cout << "edge no. " << edge.getEdgeIdx() << " ";
        edge.printNodes();
    }
}

void Hypergraph::printPartitions()
{

    for (auto& partition : PS) {
        cout << "Edges in partition: " << endl;
        for (auto& edge_idx : partition.edge_idxs){
            cout << edge_idx << " ";
        }
        cout << endl;

        cout << "Nodes in partition: " << endl;
        for (auto& node_idx : partition.node_idxs){
            cout << node_idx << " ";
        }
        cout << endl;
    }
}

void Hypergraph::partitionValidity(){

    vector<bool> nodes_seen;
    nodes_seen.resize(HG_nodes.size(),false);
    for (auto& partition : PS) {
        for (auto& node_idx : partition.node_idxs){
            if (nodes_seen[node_idx] == true){
                cout << "node idx " << node_idx << " appears in multiple partitions " << endl;
            }
            nodes_seen[node_idx] = true;
        }
    }
}

/* Reduce the graph by removing edges based on the constraints relaxed */


void Hypergraph::updateNodes(const vector<double>& constraints_selected, vector<HG_Node>& updated_nodes)
{
    // copy the original node information
    for (auto& node : HG_nodes){
        updated_nodes[node.getNodeIdx()] = HG_Node{node.getNodeIdx(),node.getEdgeIdxs()};
    }
    // ensure constraint vector input matches number of edges in HG
    if (constraints_selected.size() != HG_edges.size()) {
        cout << "incorrect input vector size of relaxed constraints" << endl;
    }
    int edge_idx = 0;
    for (auto& constraint_decision : constraints_selected) {
        HG_Edge current_edge = HG_edges[edge_idx];
        // 1 is edge relaxation
        if (constraint_decision == 1) {
            for (auto& node_idx : current_edge.getNodeIdxs()){
                //remove edge idx attached to node
                updated_nodes[node_idx].removeEdgeIdx(current_edge.getEdgeIdx());
            }
        }
        edge_idx++;
    }
}

void Hypergraph::partition(const vector<double>& constraints_selected){
     // reduce graph edges
    
    PS.clear();
    vector<HG_Node> updated_nodes;
    updated_nodes.resize(HG_nodes.size());
    updateNodes(constraints_selected,updated_nodes);
    // identify partitions with new edges...
    identifyPartitions(updated_nodes);

}

int Hypergraph::getLargestPartition()
{   
    largest_partition = 0;
    if (!PS.empty()) {
        for (auto& partition : PS) {
            if (partition.node_idxs.size() > largest_partition) {
                largest_partition = partition.node_idxs.size();
            }
        }
    }
    return largest_partition;
}


void Hypergraph::printPartitions(vector<vector<int>> partitions)
{
    for (auto& partition : partitions) {
        cout << "Partition - ";
        for (auto& node : partition) {
            cout << " " << node;
        }
        cout << endl;
    }
}