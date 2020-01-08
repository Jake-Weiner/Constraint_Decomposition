#include "Param.h"
#include "anyoption.h"

namespace mainParam{

void Param::parse(int argc, const char** argv)
{
    AnyOption parser(100);
    parser.setOption("input_filename");
    parser.setOption("subproblem_var_prop");
    parser.setOption("output_stats_filename");
    parser.setOption("output_lb_filename"); 
    parser.setOption("nsga_gen"); 
    if (argc == -1) // abuse of function
        parser.processFile(*argv);
    else
        parser.processCommandArgs(argc, argv);
    if (parser.getValue("input_filename"))
        input_filename = parser.getValue("input_filename");
    if (parser.getValue("subproblem_var_prop"))
        subproblem_var_prop = atof(parser.getValue("subproblem_var_prop"));
    if (parser.getValue("output_stats_filename"))
        output_stats_filename = parser.getValue("output_stats_filename");
    if (parser.getValue("output_lb_filename"))
        output_lb_filename = parser.getValue("output_lb_filename");
    if (parser.getValue("nsga_gen"))
        nsga_gen = atoi(parser.getValue("nsga_gen"));
    
}
};