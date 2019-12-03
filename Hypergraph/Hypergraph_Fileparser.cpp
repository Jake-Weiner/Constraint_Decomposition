#include "Hypergraph_Fileparser.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

void trim(string& s)
{
    size_t p = s.find_first_not_of(" \t");
    s.erase(0, p);

    p = s.find_last_not_of(" \t");
    if (string::npos != p)
        s.erase(p + 1);
}

void Hypergraph_Fileparser::parse(file_type ft, string filename)
{

    if (ft == USER) {
        parserUser(filename);
    } else if (ft == MPS) {
        parserMps(filename);
    } else {
        cout << "incorrect file type provided for Hypergraph initialisation" << endl;
    }
}

void Hypergraph_Fileparser::parserUser(string filename)
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
}
void Hypergraph_Fileparser::parserMps(string filename)
{

    ifstream input(filename);

    int current_constraint_number = 0;
    int current_node_number = 0;
    if (input.is_open()) {
        while (!input.eof()) {
            string line;
            getline(input, line);
            if (line.empty()) {
                continue;
            }
            trim(line);
            vector<string> line_split;
            // check for non empty line
            boost::split(line_split, line, boost::is_any_of(" \t"), boost::token_compress_on);
            if ((line_split[0].compare("E") ==0)|| (line_split[0].compare("L") ==0)
                || (line_split[0].compare("G"))==0) {
                string constraint_name = line_split[1];
                MI.addConstraintName(constraint_name, current_constraint_number);
                MI.addConstraintIdx(current_constraint_number, constraint_name);
                HG_Edge constraint(current_constraint_number);
                HG_edges.push_back(constraint);
                current_constraint_number++;
            }
            if (boost::starts_with(line_split[0], "x")) {
                for (int i = 1; i < line_split.size(); i++) {
                    if ( (line_split[i].compare("COST") != 0) && (isdigit(line_split[i][0]) == 0)) {
                        string variable_name = line_split[0];
                        string constraint_name = line_split[i];
                        // If variable has been seen, add constraint idx to the HG Node and node idx to constraint
                        if (MI.varNameExists(variable_name)) {
                            int edge_constraint_idx = MI.getConstraintIdx(constraint_name);
                            HG_edges[edge_constraint_idx].addNodeIdx(MI.getVariableIdx(variable_name));
                            HG_nodes[MI.getVariableIdx(variable_name)].addEdgeIdx(MI.getConstraintIdx(constraint_name));
                        }
                        // otherwise add information to MI and new node to HG_nodes
                        else {
                            MI.addVariableName(variable_name, current_node_number);
                            MI.addVariableIdx(current_node_number, variable_name);
                            int edge_constraint_idx = MI.getConstraintIdx(constraint_name);
                            HG_edges[edge_constraint_idx].addNodeIdx(current_node_number);
                            HG_Node current_var(current_node_number);
                            current_var.addEdgeIdx(MI.getConstraintIdx(constraint_name));
                            HG_nodes.push_back(current_var);
                            current_node_number++;
                        }
                    }
                }
            }
        }
    }
}

//
//         }
//
//         vector<int> nodes_idxs_in_constraint;
//         for (int node_idx = 0; node_idx < line_split.size(); node_idx++) {
//             int node_value;
//             try {
//                 node_value = stoi(line_split[node_idx]);
//                 if (node_value == 1) {
//                     nodes_idxs_in_constraint.push_back(node_idx);
//                     HG_nodes[node_idx].addEdgeIdx(current_constraint_number);
//                 }
//             } catch (exception invalid_argument) {
//                 cout << "invalid stoi = " << line_split[node_idx] << endl;
//                 cout << "line split = ";
//                 for (auto& field : line_split) {
//                     cout << field;
//                 }
//                 cout << endl;
//                 cout << "node idx = " << node_idx << endl;
//                 cout << "line number = " << line_count << endl;
//                 cout << "line is " << line << endl;
//             }
//         }
//         HG_Edge current_constraint = HG_Edge(current_constraint_number, nodes_idxs_in_constraint);
//         HG_edges[current_constraint_number] = current_constraint;
//         current_constraint_number += 1;
//         line_count++;
//     }
// }

// if (current_constraint_number != num_edges) {
//     cout << "error - number of constraints read does not match constraint number in input file" << endl;
// }

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
    if (HG_nodes.size() != size) {
        HG_nodes.resize(size);
    }

    for (int node_idx = 0; node_idx < size; node_idx++) {
        HG_nodes[node_idx] = HG_Node(node_idx);
    }
}