//Parameters used for experiments

#ifndef __PARAM__
#define __PARAM__

#include <string>

namespace mainParam {

using namespace std;

struct Param {

    /// load commandline arguments to set parameter values.
    /// This function will take any argument pair of the form
    /// --<name> <value> (where name is one of the attributes like
    /// maxIter) and set the corresponding parameter to the value
    void parse(int argc, const char** argv);

    // mip input filname
    const char* input_filename;

    // proportion of variables in largest subproblem
    double subproblem_var_prop;

    // LB output filename
    const char* output_stats_filename = "";

    // // print LB
    // bool print_LB;

    // Final Stats filename
    const char* output_lb_filename = "";

    int nsga_gen;
};
};
#endif