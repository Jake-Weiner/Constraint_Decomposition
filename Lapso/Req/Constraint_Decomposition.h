#ifndef Constraint_Decomposition_H
#define Constraint_Decomposition_H

#include "LaPSO.hpp"
#include <ilcplex/ilocplex.h>
#include <string>
#include <map>
#include <unordered_map>


using namespace LaPSO;
using namespace std;

struct subproblem_mip{
  vector<int> variable_idxs;
  unordered_map<int,string> idx_to_constraint;
};

template <typename Container> // we can make this generic for any container [1]
struct container_hash {
    std::size_t operator()(Container const& c) const {
        return boost::hash_range(c.begin(), c.end());
    }
};

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

class Constraint_DecompositionParticle : public LaPSO::Particle {
public:
    Constraint_DecompositionParticle();
    int repair_iter = 0;
    vector<int> solve_mip(map<vector<int>,int>& global_constraint_map);
};

class Constraint_Decomposition : public LaPSO::UserHooks {

public:
    
    Constraint_Decomposition();
    //void solve_Constraint_Decomposition(Constraint_DecompositionParticle &p);
    int nConstraint_Decompositionsolves;		// number of times Constraint_Decomposition was solvConstraint_Decomposition
    int maxConstraint_Decompositionsolves;		// abort after this many
    ~Constraint_Decomposition();
    Status redCost(const Particle &p, DblVec &redCost);
    Status solveSubproblem(Particle& p);
    //void randomiseMethod(Constraint_DecompositionParticle &p);
    Status fixConstraint(const int constraint,
									 const Particle &p,
									 SparseVec &feas);
    Status heuristics(Particle &p);
    Status updateBest(Particle &p);
    
    void initialise_global_constraints();
    void add_constraints_mip(vector<pair<vector<int>, int>>& local_constraints);

    void setPrinting(bool p) {printing=p;}

private:
    bool printing;
    vector<int> solve_mip(Constraint_DecompositionParticle &p);
};


#endif 