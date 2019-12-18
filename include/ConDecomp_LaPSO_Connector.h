#ifndef ConDecomp_LaPSO_Connector_H
#define ConDecomp_LaPSO_Connector_H

#include "LaPSO.hpp"
#include "MIP_Problem.h"
#include "Constraint.h"
#include "Variable.h"
#include "Subproblem_Constraints.h"
#include "Hypergraph.h"
#include <ilcplex/ilocplex.h>
#include <string>
#include <map>
#include <unordered_map>
#include <ilcplex/ilocplex.h>

using namespace LaPSO;
using namespace std;


struct CPLEX_MIP_Subproblem{
    
    int num_subproblem_vars;
    unordered_map<int,int> subproblemVarIdx_to_originalVarIdx;
    unordered_map<int,int> originalVarIdx_to_subproblemVarIdx;
    IloEnv env;
    IloModel model;
    IloNumVarArray variables;
};


class ConDecomp_LaPSO_ConnectorParticle : public LaPSO::Particle {
public:
    ConDecomp_LaPSO_ConnectorParticle(int num_var, int num_con) : LaPSO::Particle(num_var,num_con){}
};

class ConDecomp_LaPSO_Connector : public LaPSO::UserHooks {

public:
    
    ConDecomp_LaPSO_Connector(MIP_Problem& original_problem, const vector<Partition_Struct>& partitions, const bool& printing);
    //void solve_ConDecomp_LaPSO_Connector(ConDecomp_LaPSO_ConnectorParticle &p);
    int nsolves;		// number of times ConDecomp_LaPSO_Connector was solved
    int maxsolves;		// abort after this many
    ~ConDecomp_LaPSO_Connector(){};

    Status reducedCost(const Particle &p, DblVec &redCost);
    Status solveSubproblem(Particle& p);
    //void randomiseMethod(ConDecomp_LaPSO_ConnectorParticle &p);
    Status fixConstraint(const int constraint,
									 const Particle &p,
									 SparseVec &feas);
    Status heuristics(Particle &p);
    Status updateBest(Particle &p);
    
    void setPrinting(bool p) {printing=p;}

private:
   
    vector<CPLEX_MIP_Subproblem> MS;
    void initSubproblems(MIP_Problem& original_problem,const vector<Partition_Struct>&);
    void initOriginalCosts(MIP_Problem& original_problem);
    bool printing;
    MIP_Problem OP;
    DblVec original_costs;
    
};


#endif 