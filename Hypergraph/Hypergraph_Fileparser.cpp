#include "Hypergraph_Fileparser.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

void Hypergraph_Fileparser::parse(file_type ft, string filename){
    
    if (ft == USER){
        parserUser(filename);
    }
    else if (ft == MPS){
        parserMps(filename);
    }
    else{
        cout << "incorrect file type provided for Hypergraph initialisation" << endl;
    }
}


void Hypergraph_Fileparser::parserUser(string filename){
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
}
void Hypergraph_Fileparser::parserMps(string filename){
    

}


void Hypergraph_Fileparser::setHGEdgesSize(int size)
{
    HG_edges.resize(size);
    num_edges = size;
}
void Hypergraph_Fileparser::setHGNodesSize(int size)
{
    HG_nodes.resize(size);
    num_nodes = size;
}

void Hypergraph_Fileparser::initNodes(int size)
{
    if (HG_nodes.size()!= size){
        HG_nodes.resize(size);
    }
    
    for (int node_idx = 0; node_idx < size; node_idx++) {
        HG_nodes[node_idx] = HG_Node(node_idx);
    }
}