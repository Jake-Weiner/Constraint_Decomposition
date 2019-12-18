#include "Hypergraph.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> Hypergraph::identifyPartitions(const vector<HG_Edge>& edges, const vector<HG_Node>& nodes)
{

    vector<vector<int>> current_partitions;
   

    // test for empty edges
    if (edges.empty()) {
        // cout << "no edges selected to identify partitions" << endl;
        return current_partitions;
    }

    // List keeping track of seen edges
    vector<bool> edge_idx_seen;
    edge_idx_seen.resize(edges.size(), false);
    // List keeping track of nodes seen
    vector<bool> node_idx_seen;
    node_idx_seen.resize(nodes.size(), false);
    int BFS_counter = 0;
    //perform BFS on Hypergraph - stop when all edges have been considered or all nodes have been considered
    while (count(node_idx_seen.begin(), node_idx_seen.end(), true) != node_idx_seen.size()){
    // && count(edge_idx_seen.begin(), edge_idx_seen.end(), true) != edge_idx_seen.size() 
    // && BFS_counter < 100) {

        // pick first unseen node if it has an edge attached
        int node_idx_selected;
        for (int i = 0; i < node_idx_seen.size(); i++) {
            if (node_idx_seen[i] == false) {
                node_idx_selected = i;
                break;
            }
        }

        HG_Node node_selected = nodes[node_idx_selected];
        node_idx_seen[node_idx_selected] = true;

        current_partitions.push_back(findPartition(edges, nodes, node_selected, node_idx_seen));
        BFS_counter++;
        // add each Hyperedge containing node to queue
    }
    return current_partitions;
}




vector<int> Hypergraph::findPartition(const vector<HG_Edge>& edges_considered, const vector<HG_Node>& nodes_considered,
 HG_Node starting_node,  vector<bool>& node_idx_seen)
{
    vector<bool> edge_idx_seen;
    edge_idx_seen.resize(edges_considered.size(), false);
    vector<int> node_partition;
    vector<int> edge_partition;
    
    node_partition.push_back(starting_node.getNodeIdx());
    queue<HG_Edge> Q;
    
    if ((starting_node.getEdgeIdxs()).empty()){
        cout << "empty edge idx for node idx " << starting_node.getNodeIdx() << endl;
    }
    // add edges attached to node which haven't been seen before
    for (auto& edge_idx : starting_node.getEdgeIdxs()) {
        
        if (edge_idx_seen[edge_idx] == false) {
            Q.push(edges_considered[edge_idx]);
            cout << "edge idx to be added " << edge_idx << endl;
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
                        Q.push(edges_considered[edge_idx]);
                        edge_idx_seen[edge_idx] = true;
                    }
                }
            }
        }
        Q.pop();
    }

    if (edge_partition.empty()){
        cout << "empty edge partition" << endl;
    }
    if (node_partition.empty()){
        cout << "empty node partition" << endl;
    }

    Partition_Struct ps = {node_partition, edge_partition};
    PS.push_back(ps);
    return node_partition;
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

void Hypergraph::partition(const vector<double>& constraints_selected){
     // reduce graph edges
    vector<HG_Edge> updated_edges;
    vector<HG_Node> updated_nodes;
    updated_edges.resize(HG_edges.size());
    updated_nodes.resize(HG_nodes.size());
    // copy the original node information
    for (auto& node : HG_nodes){
        updated_nodes[node.getNodeIdx()] = HG_Node{node.getNodeIdx(),node.getEdgeIdxs()};
    }
    // ensure constraint vector input matches number of edges in HG
    if (constraints_selected.size() != HG_edges.size()) {
        cout << "incorrect input vector size of relaxed constraints" << endl;
    }
    int constraint_idx = 0;
    for (auto& constraint_decision : constraints_selected) {
        HG_Edge current_edge_copy = HG_Edge{HG_edges[constraint_idx].getEdgeIdx(),HG_edges[constraint_idx].getNodeIdxs()};
        // 1 is edge relaxation
        if (constraint_decision == 1) {
            for (auto& node_idx : current_edge_copy.getNodeIdxs()){
                //remove edge idx attached to node
                updated_nodes[node_idx].removeEdgeIdx(current_edge_copy.getEdgeIdx());
            }
        }
        updated_edges[constraint_idx] = current_edge_copy;
        constraint_idx++;
    }
    // identify partitions with new edges...
    identifyPartitions(updated_edges, updated_nodes);

}

int Hypergraph::getLargestPartition()
{   
    largest_partition = 0;
    if (!partitions.empty()) {
        for (auto& partition : partitions) {
            if (partition.size() > largest_partition) {
                largest_partition = partition.size();
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