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
include_directories("/home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/Req")
include_directories("/home/jake/PhD/Coding_Libraries/cplex/include")
include_directories("/home/jake/PhD/Coding_Libraries/concert/include")
include_directories("/home/jake/PhD/Coding_Libraries/pagmo2-2.11.4/include")
include_directories("/home/jake/PhD/Decomposition/Constraint_Decomposition/pagmo/Req")

set(Hypergraph_src "/home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph")
set(Pagmo_src "/home/jake/PhD/Decomposition/Constraint_Decomposition/pagmo")

link_directories("/home/jake/PhD/Coding_Libraries/cplex/lib/x86-64_linux/static_pic")
link_directories("/home/jake/PhD/Coding_Libraries/concert/lib/x86-64_linux/static_pic")
link_directories("/home/jake/PhD/Edge_Disjoint/c++/boost_1_67_0/Build/lib")

add_executable(main_test main.cpp ${Pagmo_src}/Decomp.cpp ${Hypergraph_src}/Hypergraph.cpp ${Hypergraph_src}/Hypergraph_Fileparser.cpp ${Hypergraph_src}/HG_Edge.cpp ${Hypergraph_src}/HG_Node.cpp)

target_link_libraries(main_test Pagmo::pagmo concert ilocplex cplex m pthread dl)


