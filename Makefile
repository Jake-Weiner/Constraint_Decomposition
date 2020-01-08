# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jake/PhD/Decomposition/Constraint_Decomposition

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jake/PhD/Decomposition/Constraint_Decomposition

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles /home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main_test

# Build rule for target.
main_test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main_test
.PHONY : main_test

# fast build rule for target.
main_test/fast:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/build
.PHONY : main_test/fast

src/ConDecomp_LaPSO_Connector.o: src/ConDecomp_LaPSO_Connector.cpp.o

.PHONY : src/ConDecomp_LaPSO_Connector.o

# target to build an object file
src/ConDecomp_LaPSO_Connector.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/ConDecomp_LaPSO_Connector.cpp.o
.PHONY : src/ConDecomp_LaPSO_Connector.cpp.o

src/ConDecomp_LaPSO_Connector.i: src/ConDecomp_LaPSO_Connector.cpp.i

.PHONY : src/ConDecomp_LaPSO_Connector.i

# target to preprocess a source file
src/ConDecomp_LaPSO_Connector.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/ConDecomp_LaPSO_Connector.cpp.i
.PHONY : src/ConDecomp_LaPSO_Connector.cpp.i

src/ConDecomp_LaPSO_Connector.s: src/ConDecomp_LaPSO_Connector.cpp.s

.PHONY : src/ConDecomp_LaPSO_Connector.s

# target to generate assembly for a file
src/ConDecomp_LaPSO_Connector.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/ConDecomp_LaPSO_Connector.cpp.s
.PHONY : src/ConDecomp_LaPSO_Connector.cpp.s

src/CpuTimer.o: src/CpuTimer.cpp.o

.PHONY : src/CpuTimer.o

# target to build an object file
src/CpuTimer.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/CpuTimer.cpp.o
.PHONY : src/CpuTimer.cpp.o

src/CpuTimer.i: src/CpuTimer.cpp.i

.PHONY : src/CpuTimer.i

# target to preprocess a source file
src/CpuTimer.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/CpuTimer.cpp.i
.PHONY : src/CpuTimer.cpp.i

src/CpuTimer.s: src/CpuTimer.cpp.s

.PHONY : src/CpuTimer.s

# target to generate assembly for a file
src/CpuTimer.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/CpuTimer.cpp.s
.PHONY : src/CpuTimer.cpp.s

src/Decomp.o: src/Decomp.cpp.o

.PHONY : src/Decomp.o

# target to build an object file
src/Decomp.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/Decomp.cpp.o
.PHONY : src/Decomp.cpp.o

src/Decomp.i: src/Decomp.cpp.i

.PHONY : src/Decomp.i

# target to preprocess a source file
src/Decomp.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/Decomp.cpp.i
.PHONY : src/Decomp.cpp.i

src/Decomp.s: src/Decomp.cpp.s

.PHONY : src/Decomp.s

# target to generate assembly for a file
src/Decomp.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/Decomp.cpp.s
.PHONY : src/Decomp.cpp.s

src/DecompMIP.o: src/DecompMIP.cpp.o

.PHONY : src/DecompMIP.o

# target to build an object file
src/DecompMIP.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/DecompMIP.cpp.o
.PHONY : src/DecompMIP.cpp.o

src/DecompMIP.i: src/DecompMIP.cpp.i

.PHONY : src/DecompMIP.i

# target to preprocess a source file
src/DecompMIP.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/DecompMIP.cpp.i
.PHONY : src/DecompMIP.cpp.i

src/DecompMIP.s: src/DecompMIP.cpp.s

.PHONY : src/DecompMIP.s

# target to generate assembly for a file
src/DecompMIP.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/DecompMIP.cpp.s
.PHONY : src/DecompMIP.cpp.s

src/HG_Edge.o: src/HG_Edge.cpp.o

.PHONY : src/HG_Edge.o

# target to build an object file
src/HG_Edge.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/HG_Edge.cpp.o
.PHONY : src/HG_Edge.cpp.o

src/HG_Edge.i: src/HG_Edge.cpp.i

.PHONY : src/HG_Edge.i

# target to preprocess a source file
src/HG_Edge.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/HG_Edge.cpp.i
.PHONY : src/HG_Edge.cpp.i

src/HG_Edge.s: src/HG_Edge.cpp.s

.PHONY : src/HG_Edge.s

# target to generate assembly for a file
src/HG_Edge.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/HG_Edge.cpp.s
.PHONY : src/HG_Edge.cpp.s

src/HG_Node.o: src/HG_Node.cpp.o

.PHONY : src/HG_Node.o

# target to build an object file
src/HG_Node.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/HG_Node.cpp.o
.PHONY : src/HG_Node.cpp.o

src/HG_Node.i: src/HG_Node.cpp.i

.PHONY : src/HG_Node.i

# target to preprocess a source file
src/HG_Node.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/HG_Node.cpp.i
.PHONY : src/HG_Node.cpp.i

src/HG_Node.s: src/HG_Node.cpp.s

.PHONY : src/HG_Node.s

# target to generate assembly for a file
src/HG_Node.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/HG_Node.cpp.s
.PHONY : src/HG_Node.cpp.s

src/Hypergraph.o: src/Hypergraph.cpp.o

.PHONY : src/Hypergraph.o

# target to build an object file
src/Hypergraph.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/Hypergraph.cpp.o
.PHONY : src/Hypergraph.cpp.o

src/Hypergraph.i: src/Hypergraph.cpp.i

.PHONY : src/Hypergraph.i

# target to preprocess a source file
src/Hypergraph.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/Hypergraph.cpp.i
.PHONY : src/Hypergraph.cpp.i

src/Hypergraph.s: src/Hypergraph.cpp.s

.PHONY : src/Hypergraph.s

# target to generate assembly for a file
src/Hypergraph.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/Hypergraph.cpp.s
.PHONY : src/Hypergraph.cpp.s

src/LaPSO.o: src/LaPSO.cpp.o

.PHONY : src/LaPSO.o

# target to build an object file
src/LaPSO.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/LaPSO.cpp.o
.PHONY : src/LaPSO.cpp.o

src/LaPSO.i: src/LaPSO.cpp.i

.PHONY : src/LaPSO.i

# target to preprocess a source file
src/LaPSO.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/LaPSO.cpp.i
.PHONY : src/LaPSO.cpp.i

src/LaPSO.s: src/LaPSO.cpp.s

.PHONY : src/LaPSO.s

# target to generate assembly for a file
src/LaPSO.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/LaPSO.cpp.s
.PHONY : src/LaPSO.cpp.s

src/MIP_Fileparser.o: src/MIP_Fileparser.cpp.o

.PHONY : src/MIP_Fileparser.o

# target to build an object file
src/MIP_Fileparser.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/MIP_Fileparser.cpp.o
.PHONY : src/MIP_Fileparser.cpp.o

src/MIP_Fileparser.i: src/MIP_Fileparser.cpp.i

.PHONY : src/MIP_Fileparser.i

# target to preprocess a source file
src/MIP_Fileparser.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/MIP_Fileparser.cpp.i
.PHONY : src/MIP_Fileparser.cpp.i

src/MIP_Fileparser.s: src/MIP_Fileparser.cpp.s

.PHONY : src/MIP_Fileparser.s

# target to generate assembly for a file
src/MIP_Fileparser.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/MIP_Fileparser.cpp.s
.PHONY : src/MIP_Fileparser.cpp.s

src/MIP_Problem_CPLEX_Solver.o: src/MIP_Problem_CPLEX_Solver.cpp.o

.PHONY : src/MIP_Problem_CPLEX_Solver.o

# target to build an object file
src/MIP_Problem_CPLEX_Solver.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/MIP_Problem_CPLEX_Solver.cpp.o
.PHONY : src/MIP_Problem_CPLEX_Solver.cpp.o

src/MIP_Problem_CPLEX_Solver.i: src/MIP_Problem_CPLEX_Solver.cpp.i

.PHONY : src/MIP_Problem_CPLEX_Solver.i

# target to preprocess a source file
src/MIP_Problem_CPLEX_Solver.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/MIP_Problem_CPLEX_Solver.cpp.i
.PHONY : src/MIP_Problem_CPLEX_Solver.cpp.i

src/MIP_Problem_CPLEX_Solver.s: src/MIP_Problem_CPLEX_Solver.cpp.s

.PHONY : src/MIP_Problem_CPLEX_Solver.s

# target to generate assembly for a file
src/MIP_Problem_CPLEX_Solver.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/MIP_Problem_CPLEX_Solver.cpp.s
.PHONY : src/MIP_Problem_CPLEX_Solver.cpp.s

src/MIP_to_Hypergraph.o: src/MIP_to_Hypergraph.cpp.o

.PHONY : src/MIP_to_Hypergraph.o

# target to build an object file
src/MIP_to_Hypergraph.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/MIP_to_Hypergraph.cpp.o
.PHONY : src/MIP_to_Hypergraph.cpp.o

src/MIP_to_Hypergraph.i: src/MIP_to_Hypergraph.cpp.i

.PHONY : src/MIP_to_Hypergraph.i

# target to preprocess a source file
src/MIP_to_Hypergraph.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/MIP_to_Hypergraph.cpp.i
.PHONY : src/MIP_to_Hypergraph.cpp.i

src/MIP_to_Hypergraph.s: src/MIP_to_Hypergraph.cpp.s

.PHONY : src/MIP_to_Hypergraph.s

# target to generate assembly for a file
src/MIP_to_Hypergraph.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/MIP_to_Hypergraph.cpp.s
.PHONY : src/MIP_to_Hypergraph.cpp.s

src/Param.o: src/Param.cpp.o

.PHONY : src/Param.o

# target to build an object file
src/Param.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/Param.cpp.o
.PHONY : src/Param.cpp.o

src/Param.i: src/Param.cpp.i

.PHONY : src/Param.i

# target to preprocess a source file
src/Param.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/Param.cpp.i
.PHONY : src/Param.cpp.i

src/Param.s: src/Param.cpp.s

.PHONY : src/Param.s

# target to generate assembly for a file
src/Param.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/Param.cpp.s
.PHONY : src/Param.cpp.s

src/anyoption.o: src/anyoption.cpp.o

.PHONY : src/anyoption.o

# target to build an object file
src/anyoption.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/anyoption.cpp.o
.PHONY : src/anyoption.cpp.o

src/anyoption.i: src/anyoption.cpp.i

.PHONY : src/anyoption.i

# target to preprocess a source file
src/anyoption.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/anyoption.cpp.i
.PHONY : src/anyoption.cpp.i

src/anyoption.s: src/anyoption.cpp.s

.PHONY : src/anyoption.s

# target to generate assembly for a file
src/anyoption.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/anyoption.cpp.s
.PHONY : src/anyoption.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... main_test"
	@echo "... src/ConDecomp_LaPSO_Connector.o"
	@echo "... src/ConDecomp_LaPSO_Connector.i"
	@echo "... src/ConDecomp_LaPSO_Connector.s"
	@echo "... src/CpuTimer.o"
	@echo "... src/CpuTimer.i"
	@echo "... src/CpuTimer.s"
	@echo "... src/Decomp.o"
	@echo "... src/Decomp.i"
	@echo "... src/Decomp.s"
	@echo "... src/DecompMIP.o"
	@echo "... src/DecompMIP.i"
	@echo "... src/DecompMIP.s"
	@echo "... src/HG_Edge.o"
	@echo "... src/HG_Edge.i"
	@echo "... src/HG_Edge.s"
	@echo "... src/HG_Node.o"
	@echo "... src/HG_Node.i"
	@echo "... src/HG_Node.s"
	@echo "... src/Hypergraph.o"
	@echo "... src/Hypergraph.i"
	@echo "... src/Hypergraph.s"
	@echo "... src/LaPSO.o"
	@echo "... src/LaPSO.i"
	@echo "... src/LaPSO.s"
	@echo "... src/MIP_Fileparser.o"
	@echo "... src/MIP_Fileparser.i"
	@echo "... src/MIP_Fileparser.s"
	@echo "... src/MIP_Problem_CPLEX_Solver.o"
	@echo "... src/MIP_Problem_CPLEX_Solver.i"
	@echo "... src/MIP_Problem_CPLEX_Solver.s"
	@echo "... src/MIP_to_Hypergraph.o"
	@echo "... src/MIP_to_Hypergraph.i"
	@echo "... src/MIP_to_Hypergraph.s"
	@echo "... src/Param.o"
	@echo "... src/Param.i"
	@echo "... src/Param.s"
	@echo "... src/anyoption.o"
	@echo "... src/anyoption.i"
	@echo "... src/anyoption.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

