//Parameters used for experiments

#ifndef __PARAM__
#define __PARAM__

#include <string>
#include <map>
#include <limits>

enum DecompType { NSGA, CPLEX };
namespace mainParam {

using namespace std;



struct Param {

    /// load commandline arguments to set parameter values.
    /// This function will take any argument pair of the form
    /// --<name> <value> (where name is one of the attributes like
    /// maxIter) and set the corresponding parameter to the value
    void parse(int argc, const char** argv);

    // mip input filename
    const char* input_root_folder;

    // proportion of variables in largest subproblem
    const char* subproblem_var_prop = "";

    // LB output filename
    const char* output_root_folder = "";

    // // print LB
    // bool print_LB;

    // Final Stats filename
    // const char* output_lb_root_folder = "";

    int nsga_gen = 1;

    int nsga_pop_size = 1;

    const char* input_instance_name = "";
    
    const char* decomp_type = "";

    const char* nsga_vector_root_folder = "";


    const char* cplex_decomp_warmstart_file = "";

    const char* cplex_decomp_output_root_folder = "";

    const char* solve_generic_MIP_output_root_folder = "";
    
    const char* run_nsga_decomp = "";

    double set_ub = std::numeric_limits<double>::max();

    double set_generic_MIP_time = 100;

    const char* run_generic_MIP_solver = "true";

    const char* run_lapso = "true";

    const char* test_greedy_decomp = "";

    const char* test_random_decomp = "";

    const char* random_lb_output = "";

    map<string, DecompType> str_to_DT = {{"NSGA", NSGA}, {"CPLEX", CPLEX}};

    map<string, bool> char_to_BOOL = {{"true", true} , {"false" , false}};



    
};
};
#endif