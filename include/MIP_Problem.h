#ifndef __MIP_PROBLEM__
#define __MIP_PROBLEM__

#include "Constraint.h"
#include "Variable.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

enum Optimisation_Type{Minimise,Maximise};

struct MIP_Problem{

    void addConstraint(Constraint constraint){
        constraints.push_back(constraint);
    };
    void addObjVarIdx(const int& var_idx){
        variables_obj_fn.push_back(var_idx);
    }
    void addObjVarCoeff(const int& var_coeff){
        coeff_obj_fn.push_back(var_coeff);
    }

    Variable getVariable(const int& index){
        if (index < variables.size() && index >= 0){
            return variables[index];
        }
        else{
            cout << "out of bounds array index for accessing Variable in MIP_Problem" << endl;
            cout << "index is -" << index << " vector size is - " << variables.size() << endl;
        }
        return NULL;
    }

    int getNumConstraints(){
        return constraints.size();
    }

    int getNumVariables(){
        return variables.size();
    }
    

    int number_variables;
    vector<Constraint> constraints;
    vector<Variable> variables;
    vector<int> variables_obj_fn;
    vector<double> coeff_obj_fn;
    Optimisation_Type OT;
};

#endif