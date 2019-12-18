#ifndef __CONSTRAINT__
#define __CONSTRAINT__

#include <vector>

using namespace std;

enum bound_type {Equal, Less, Greater};

class Constraint{

    public:
        Constraint(){};
        Constraint(int constraint_idx){
            this->constraint_idx = constraint_idx;
        };
        ~Constraint(){};
        void addVarIdx(const int& var_idx_to_add){
            for (auto& var_idx : variable_indxs){
                if (var_idx == var_idx_to_add){
                    return;
                }
            }
            variable_indxs.push_back(var_idx_to_add);
        };
        void addVarCoeff(const int& var_coeff_to_add){
            variable_coeffs.push_back(var_coeff_to_add);
        }
        vector<int> getVarIndxs(){
            return variable_indxs;
        }

        vector<double> getVarCoeffs(){
            return variable_coeffs;
        }

        int getConIdx(){
            return constraint_idx;
        }

        void setRHS(double bound){
            RHS = bound;
        }

        void setBoundType(bound_type bt){
            this-> bt = bt;
        }

        bound_type getBoundType(){
            return bt;
        }

        double getRHS(){
            return RHS;
        }

    private:
        double RHS;
        int constraint_idx;
        bound_type bt;
        vector<int> variable_indxs;
        vector<double> variable_coeffs;
};

#endif