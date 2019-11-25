#ifndef __HG_MPSINFO__
#define __HG_MPSINFO__

#include <vector>
#include <string>
#include "HG_Node.h"
#include "HG_Edge.h"
#include <unordered_map>
#include <fstream>
#include <iostream>

using namespace std;

struct Mps_Info{
    //insert hashmaps for mps info 
    unordered_map<int,string> idx_to_constraint;
    unordered_map<string,int> constraint_to_idx;
    unordered_map<int,string> idx_to_var;
    unordered_map<string, int> var_to_idx;
    string getConstraintName(int idx){
        if (idx_to_constraint.find(idx) != idx_to_constraint.end()){
            return idx_to_constraint[idx];
        }
        else{
            cout << "constraint idx does not exist" << endl;
        }
        return "";
    };
    string getVariableName(int idx){
        if (idx_to_var.find(idx) != idx_to_var.end()){
            return idx_to_var[idx];
        }
        else{
            cout << "variable idx does not exist" << endl;
        }
        return "";
    }
    int getConstraintIdx(string constraint){
         if (constraint_to_idx.find(constraint) != constraint_to_idx.end()){
            return constraint_to_idx[constraint];
        }
        else{
            cout << "constraint name does not exist" << endl;
        }
        return -1;
    }
    int getVariableIdx(string variable){
          if (var_to_idx.find(variable) != var_to_idx.end()){
            return var_to_idx[variable];
        }
        else{
            cout << "variable name does not exist" << endl;
        }
        return -1;
    }
};

#endif