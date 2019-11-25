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

Hypergraph/HG_Edge.o: Hypergraph/HG_Edge.cpp.o

.PHONY : Hypergraph/HG_Edge.o

# target to build an object file
Hypergraph/HG_Edge.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.o
.PHONY : Hypergraph/HG_Edge.cpp.o

Hypergraph/HG_Edge.i: Hypergraph/HG_Edge.cpp.i

.PHONY : Hypergraph/HG_Edge.i

# target to preprocess a source file
Hypergraph/HG_Edge.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.i
.PHONY : Hypergraph/HG_Edge.cpp.i

Hypergraph/HG_Edge.s: Hypergraph/HG_Edge.cpp.s

.PHONY : Hypergraph/HG_Edge.s

# target to generate assembly for a file
Hypergraph/HG_Edge.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.s
.PHONY : Hypergraph/HG_Edge.cpp.s

Hypergraph/HG_Node.o: Hypergraph/HG_Node.cpp.o

.PHONY : Hypergraph/HG_Node.o

# target to build an object file
Hypergraph/HG_Node.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.o
.PHONY : Hypergraph/HG_Node.cpp.o

Hypergraph/HG_Node.i: Hypergraph/HG_Node.cpp.i

.PHONY : Hypergraph/HG_Node.i

# target to preprocess a source file
Hypergraph/HG_Node.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.i
.PHONY : Hypergraph/HG_Node.cpp.i

Hypergraph/HG_Node.s: Hypergraph/HG_Node.cpp.s

.PHONY : Hypergraph/HG_Node.s

# target to generate assembly for a file
Hypergraph/HG_Node.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.s
.PHONY : Hypergraph/HG_Node.cpp.s

Hypergraph/Hypergraph.o: Hypergraph/Hypergraph.cpp.o

.PHONY : Hypergraph/Hypergraph.o

# target to build an object file
Hypergraph/Hypergraph.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.o
.PHONY : Hypergraph/Hypergraph.cpp.o

Hypergraph/Hypergraph.i: Hypergraph/Hypergraph.cpp.i

.PHONY : Hypergraph/Hypergraph.i

# target to preprocess a source file
Hypergraph/Hypergraph.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.i
.PHONY : Hypergraph/Hypergraph.cpp.i

Hypergraph/Hypergraph.s: Hypergraph/Hypergraph.cpp.s

.PHONY : Hypergraph/Hypergraph.s

# target to generate assembly for a file
Hypergraph/Hypergraph.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.s
.PHONY : Hypergraph/Hypergraph.cpp.s

Hypergraph/Hypergraph_Fileparser.o: Hypergraph/Hypergraph_Fileparser.cpp.o

.PHONY : Hypergraph/Hypergraph_Fileparser.o

# target to build an object file
Hypergraph/Hypergraph_Fileparser.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.o
.PHONY : Hypergraph/Hypergraph_Fileparser.cpp.o

Hypergraph/Hypergraph_Fileparser.i: Hypergraph/Hypergraph_Fileparser.cpp.i

.PHONY : Hypergraph/Hypergraph_Fileparser.i

# target to preprocess a source file
Hypergraph/Hypergraph_Fileparser.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.i
.PHONY : Hypergraph/Hypergraph_Fileparser.cpp.i

Hypergraph/Hypergraph_Fileparser.s: Hypergraph/Hypergraph_Fileparser.cpp.s

.PHONY : Hypergraph/Hypergraph_Fileparser.s

# target to generate assembly for a file
Hypergraph/Hypergraph_Fileparser.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.s
.PHONY : Hypergraph/Hypergraph_Fileparser.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/main.cpp.s
.PHONY : main.cpp.s

pagmo/Decomp.o: pagmo/Decomp.cpp.o

.PHONY : pagmo/Decomp.o

# target to build an object file
pagmo/Decomp.cpp.o:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/pagmo/Decomp.cpp.o
.PHONY : pagmo/Decomp.cpp.o

pagmo/Decomp.i: pagmo/Decomp.cpp.i

.PHONY : pagmo/Decomp.i

# target to preprocess a source file
pagmo/Decomp.cpp.i:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/pagmo/Decomp.cpp.i
.PHONY : pagmo/Decomp.cpp.i

pagmo/Decomp.s: pagmo/Decomp.cpp.s

.PHONY : pagmo/Decomp.s

# target to generate assembly for a file
pagmo/Decomp.cpp.s:
	$(MAKE) -f CMakeFiles/main_test.dir/build.make CMakeFiles/main_test.dir/pagmo/Decomp.cpp.s
.PHONY : pagmo/Decomp.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... main_test"
	@echo "... Hypergraph/HG_Edge.o"
	@echo "... Hypergraph/HG_Edge.i"
	@echo "... Hypergraph/HG_Edge.s"
	@echo "... Hypergraph/HG_Node.o"
	@echo "... Hypergraph/HG_Node.i"
	@echo "... Hypergraph/HG_Node.s"
	@echo "... Hypergraph/Hypergraph.o"
	@echo "... Hypergraph/Hypergraph.i"
	@echo "... Hypergraph/Hypergraph.s"
	@echo "... Hypergraph/Hypergraph_Fileparser.o"
	@echo "... Hypergraph/Hypergraph_Fileparser.i"
	@echo "... Hypergraph/Hypergraph_Fileparser.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... pagmo/Decomp.o"
	@echo "... pagmo/Decomp.i"
	@echo "... pagmo/Decomp.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

