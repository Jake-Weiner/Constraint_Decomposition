#ifndef __VARIABLE__
#define __VARIABLE__

#include <vector>

using namespace std;

class Variable{

    public:
        Variable(){};
        Variable(int variable_idx){
            this->variable_idx = variable_idx;
        };
        ~Variable(){};
        
        void setVarIdx(int idx){
            variable_idx = idx;
        }

        int getVarIndx() {
            return variable_idx;
        }

        void setUB(double bound){
            upper_bound = bound;
        }

        double getUB(){
            return upper_bound;
        }

        void setLB(double bound){
            lower_bound = bound;
        }

        double getLB(){
            return lower_bound;
        }

        
    private:
        double upper_bound = 999999999999;
        double lower_bound = 0;
        int variable_idx;
};

#endif