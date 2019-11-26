#ifndef __HG_FILEPARSER__
#define __HG_FILEPARSER__

#include <vector>
#include <string>
#include "HG_Node.h"
#include "HG_Edge.h"
#include "Mps_Info.h"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

enum file_type{USER, MPS};



class Hypergraph_Fileparser {
public:
    
    Hypergraph_Fileparser(){};
    void printEdges();
    void printNodes();
    void parse(file_type ft, string filename);
    vector<HG_Edge> getHGEdges(){
        return HG_edges;
    };
    vector<HG_Node> getHGNodes(){
        return HG_nodes;
    };
    

private:

    int num_nodes;
    int num_edges;
    vector<HG_Edge> HG_edges;
    vector<HG_Node> HG_nodes;
    void printPartitions(vector<vector<int>> partitions);
    void setNumEdges(int num_edges);
    bool constraintCheck(HG_Edge constraint_to_check);
    void setHGEdgesSize(int size);
    void setHGNodesSize(int size);
    void initNodes(int size);
    void parserUser(string filename);
    void parserMps(string filename);

    Mps_Info MI;
        


};


#endif