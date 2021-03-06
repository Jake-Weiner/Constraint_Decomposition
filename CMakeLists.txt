cmake_minimum_required (VERSION 3.2.0)

project (Constraint_Decomposition)

cmake_policy(SET CMP0074 NEW)
find_package(Pagmo REQUIRED PATHS /home/jake/PhD/Coding_Libraries/tbb/tbb2019_20191006oss/lib/intel64/gcc4.8)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -g -O0 -m64 -O -fPIC -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

include_directories("/home/jake/PhD/Edge_Disjoint/c++/boost_1_67_0/Build/include")
include_directories("/home/jake/PhD/Coding_Libraries/cplex/include")
include_directories("/home/jake/PhD/Coding_Libraries/concert/include")
include_directories("/home/jake/PhD/Coding_Libraries/pagmo2-2.11.4/include")
include_directories("/home/jake/PhD/Decomposition/Constraint_Decomposition/include")

set(src "/home/jake/PhD/Decomposition/Constraint_Decomposition/src")

link_directories("/home/jake/PhD/Coding_Libraries/cplex/lib/x86-64_linux/static_pic")
link_directories("/home/jake/PhD/Coding_Libraries/concert/lib/x86-64_linux/static_pic")
link_directories("/home/jake/PhD/Edge_Disjoint/c++/boost_1_67_0/Build/lib")

add_executable(main_test ${src}/main.cpp ${src}/Param.cpp ${src}/MIP_Problem_CPLEX_Solver.cpp ${src}/anyoption.cpp ${src}/CpuTimer.cpp ${src}/LaPSO.cpp ${src}/ConDecomp_LaPSO_Connector.cpp ${src}/DecompMIP.cpp ${src}/Decomp.cpp ${src}/MIP_to_Hypergraph.cpp ${src}/Hypergraph.cpp ${src}/MIP_Fileparser.cpp ${src}/HG_Edge.cpp ${src}/HG_Node.cpp)

target_link_libraries(main_test Pagmo::pagmo concert ilocplex cplex m pthread dl)


