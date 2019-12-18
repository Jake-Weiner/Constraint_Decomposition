#include "MIP_to_Hypergraph.h"


void MIP_to_Hypergraph::convertToHypergraph(MIP_Problem& MP){

    initNodes(MP.number_variables);
    //create edges
    for (auto& constraint : MP.constraints){
        vector<int> node_idxs = constraint.getVarIndxs();
        int constraint_idx = constraint.getConIdx();
        HG_Edge edge(constraint_idx, node_idxs);
        HG_edges.push_back(edge);
        // add node information
        for (auto& node_idx : node_idxs){
            cout << "constraint idx " << constraint_idx << " added for node idx " << node_idx << endl;
            HG_nodes[node_idx].addEdgeIdx(constraint_idx);
        }
    }
    for (auto& node : HG_nodes){
            if (node.getEdgeIdxs().empty()){
                cout << "empty node at idx " << node.getNodeIdx() << endl;
            }
    }

    int j =0;
}

void MIP_to_Hypergraph::setHGEdgesSize(int size)
{
    HG_edges.resize(size);
    num_edges = size;
}
void MIP_to_Hypergraph::setHGNodesSize(int size)
{
    HG_nodes.resize(size);
    num_nodes = size;
}

void MIP_to_Hypergraph::initNodes(int size)
{
    num_nodes = size;

    if (HG_nodes.size() != size) {
        HG_nodes.resize(size);
    }

    for (int node_idx = 0; node_idx < size; node_idx++) {
        HG_nodes[node_idx] = HG_Node(node_idx);
    }
}

// // If variable has been seen, add constraint idx to the HG Node and node idx to constraint
                        // if (MII.varNameExists(variable_name)){
                           

                        //     // HG_edges[edge_constraint_idx].addNodeIdx(MII.getVariableIdx(variable_name));
                        //     // HG_nodes[MII.getVariableIdx(variable_name)].addEdgeIdx(MII.getConstraintIdx(constraint_name));
                        // }
                        // // otherwise add information to MII and new node to HG_nodes
                        // else {
                        //     MII.addVariableName(variable_name, current_node_number);
                        //     MII.addVariableIdx(current_node_number, variable_name);
                        //     int edge_constraint_idx = MII.getConstraintIdx(constraint_name);
                        //     //HG_edges[edge_constraint_idx].addNodeIdx(current_node_number);
                        //     //HG_Node current_var(current_node_number);
                        //     //current_var.addEdgeIdx(MII.getConstraintIdx(constraint_name));
                        //     //HG_nodes.push_back(current_var);
                        //     current_node_number++;
                        // }