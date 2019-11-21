#include "Hypergraph.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

void Hypergraph::identifyPartitions(bool relaxation)
{
    current_partitions.clear();

    vector<HG_Edge>* edges_considered;
    if (relaxation == true) {
        edges_considered = &Non_relaxed_edges;
    } else {
        edges_considered = &HG_edges;
    }

    // test for empty edges
    if ((*edges_considered).empty()) {
        // cout << "no edges selected to identify partitions" << endl;
        return;
    }

    // List keeping track of seen edges
    vector<bool> edge_idx_seen;
    edge_idx_seen.resize((*edges_considered).size(), false);
    // List keeping track of nodes seen
    vector<bool> node_idx_seen;
    node_idx_seen.resize(HG_nodes.size(), false);

    //perform BFS on Hypergraph
    while (count(node_idx_seen.begin(), node_idx_seen.end(), true) != node_idx_seen.size()) {

        // pick first unseen node
        int node_idx_selected;
        for (int i = 0; i < node_idx_seen.size(); i++) {
            if (node_idx_seen[i] == false) {
                node_idx_selected = i;
                break;
            }
        }

        HG_Node node_selected = HG_nodes[node_idx_selected];

        current_partitions.push_back(findPartition(*edges_considered, node_selected, edge_idx_seen, node_idx_seen));

        // add each Hyperedge containing node to queue
    }
}

void Hypergraph::partitionWithRelaxation(vector<double> constraints_selected)
{

    Non_relaxed_edges.clear();
    // reduce graph edges

    // ensure constraint vector input matches number of edges in HG
    if (constraints_selected.size() != HG_edges.size()) {
        cout << "incorrect input vector size of relaxed constraints" << endl;
        return;
    }

    int constraint_idx = 0;
    for (auto& constraint_decision : constraints_selected) {
        if (constraint_decision == 0) {
            Non_relaxed_edges.push_back(HG_edges[constraint_idx]);
        }
        constraint_idx++;
    }
    // identify partitions with new edges...
    identifyPartitions(true);

}

void Hypergraph::partitionWithoutRelaxation()
{

    identifyPartitions(false);
}

vector<int> Hypergraph::findPartition(vector<HG_Edge>& edges_considered, HG_Node starting_node, vector<bool>& edge_idx_seen, vector<bool>& node_idx_seen)
{

    vector<int> partition;
    queue<HG_Edge> Q;
    for (auto& edge_idx : starting_node.getEdgeIdxs()) {
        if (edge_idx_seen[edge_idx] == false) {
            Q.push(edges_considered[edge_idx]);
            edge_idx_seen[edge_idx] = true;
        }
    }
    while (!Q.empty()) {
        HG_Edge current_edge = Q.front();
        // for each node in the hyperedge, add the node to the partition
        for (auto& node_idx : current_edge.getNodeIdxs()) {
            if (node_idx_seen[node_idx] == false) {
                node_idx_seen[node_idx] = true;
                HG_Node new_node = HG_nodes[node_idx];
                partition.push_back(new_node.getNodeIdx());
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

    return partition;
}

void Hypergraph::initNonRelaxedEdges()
{
    Non_relaxed_edges.resize(HG_edges.size());
    int edge_idx = 0;
    for (auto& edge : HG_edges) {
        Non_relaxed_edges[edge_idx] = HG_Edge(edge.getEdgeIdx(), edge.getNodeIdxs());
        edge_idx++;
    }
}

void Hypergraph::initHypergraph(string filename)
{
    int num_constraints_lineidx = 0;
    int num_variables_lineidx = 1;
    //read in constraint matrix file
    ifstream input(filename);
    int line_count = 0;
    int current_constraint_number = 0;
    if (input.is_open()) {
        while (!input.eof()) {
            string line;
            getline(input, line);
            if (line.empty()) {
                continue;
            }
            //read number constraints/variables
            if (line_count == num_constraints_lineidx) {
                num_edges = stoi(line);
                setHGEdgesSize(stoi(line));
                line_count++;
                continue;
            } else if (line_count == num_variables_lineidx) {
                num_nodes = stoi(line);
                initNodes(num_nodes);
                setHGNodesSize(stoi(line));
                line_count++;
                continue;
            }

            vector<string> line_split;
            // check for non empty line
            boost::split(line_split, line, boost::is_any_of(" "), boost::token_compress_on);
            vector<int> nodes_idxs_in_constraint;
            for (int node_idx = 0; node_idx < line_split.size(); node_idx++) {
                int node_value;
                try {
                    node_value = stoi(line_split[node_idx]);
                    if (node_value == 1) {
                        nodes_idxs_in_constraint.push_back(node_idx);
                        HG_nodes[node_idx].addEdgeIdx(current_constraint_number);
                    }
                } catch (exception invalid_argument) {
                    cout << "invalid stoi = " << line_split[node_idx] << endl;
                    cout << "line split = ";
                    for (auto& field : line_split) {
                        cout << field;
                    }
                    cout << endl;
                    cout << "node idx = " << node_idx << endl;
                    cout << "line number = " << line_count << endl;
                    cout << "line is " << line << endl;
                }
            }
            HG_Edge current_constraint = HG_Edge(current_constraint_number, nodes_idxs_in_constraint);
            HG_edges[current_constraint_number] = current_constraint;
            current_constraint_number += 1;
            line_count++;
        }
    }

    if (current_constraint_number != num_edges) {
        cout << "error - number of constraints read does not match constraint number in input file" << endl;
    }

    // initially, all edges are considered to be available
    //initNonRelaxedEdges();
}

bool Hypergraph::constraintCheck(HG_Edge constraint_to_check)
{
    if (constraint_to_check.getNodeIdxs().size() != num_nodes) {
        return false;
    }
    return true;
}

void Hypergraph::setHGEdgesSize(int size)
{
    HG_edges.resize(size);
    num_edges = size;
}
void Hypergraph::setHGNodesSize(int size)
{
    HG_nodes.resize(size);
    num_nodes = size;
}

void Hypergraph::initNodes(int size)
{
    for (int node_idx = 0; node_idx < size; node_idx++) {
        HG_nodes.push_back(HG_Node(node_idx));
    }
    HG_nodes.resize(size);
}

void Hypergraph::printEdges()
{
    for (auto& edge : HG_edges) {
        edge.printNodes();
    }
}

int Hypergraph::getLargestPartition()
{   

    int largest_partition = 0;
    if (!current_partitions.empty()) {
        for (auto& partition : current_partitions) {
            if (partition.size() > largest_partition) {
                largest_partition = partition.size();
            }
        }
    }
    return largest_partition;
}

void Hypergraph::printPartitions()
{
    for (auto& partition : current_partitions) {
        cout << "Partition - ";
        for (auto& node : partition) {
            cout << " " << node;
        }
        cout << endl;
    }
}