# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# Include any dependencies generated for this target.
include CMakeFiles/main_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_test.dir/flags.make

CMakeFiles/main_test.dir/main.cpp.o: CMakeFiles/main_test.dir/flags.make
CMakeFiles/main_test.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_test.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_test.dir/main.cpp.o -c /home/jake/PhD/Decomposition/Constraint_Decomposition/main.cpp

CMakeFiles/main_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_test.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jake/PhD/Decomposition/Constraint_Decomposition/main.cpp > CMakeFiles/main_test.dir/main.cpp.i

CMakeFiles/main_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_test.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jake/PhD/Decomposition/Constraint_Decomposition/main.cpp -o CMakeFiles/main_test.dir/main.cpp.s

CMakeFiles/main_test.dir/pagmo/Decomp.cpp.o: CMakeFiles/main_test.dir/flags.make
CMakeFiles/main_test.dir/pagmo/Decomp.cpp.o: pagmo/Decomp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main_test.dir/pagmo/Decomp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_test.dir/pagmo/Decomp.cpp.o -c /home/jake/PhD/Decomposition/Constraint_Decomposition/pagmo/Decomp.cpp

CMakeFiles/main_test.dir/pagmo/Decomp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_test.dir/pagmo/Decomp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jake/PhD/Decomposition/Constraint_Decomposition/pagmo/Decomp.cpp > CMakeFiles/main_test.dir/pagmo/Decomp.cpp.i

CMakeFiles/main_test.dir/pagmo/Decomp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_test.dir/pagmo/Decomp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jake/PhD/Decomposition/Constraint_Decomposition/pagmo/Decomp.cpp -o CMakeFiles/main_test.dir/pagmo/Decomp.cpp.s

CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.o: CMakeFiles/main_test.dir/flags.make
CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.o: Hypergraph/Hypergraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.o -c /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/Hypergraph.cpp

CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/Hypergraph.cpp > CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.i

CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/Hypergraph.cpp -o CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.s

CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.o: CMakeFiles/main_test.dir/flags.make
CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.o: Hypergraph/Hypergraph_Fileparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.o -c /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/Hypergraph_Fileparser.cpp

CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/Hypergraph_Fileparser.cpp > CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.i

CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/Hypergraph_Fileparser.cpp -o CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.s

CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.o: CMakeFiles/main_test.dir/flags.make
CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.o: Hypergraph/HG_Edge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.o -c /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/HG_Edge.cpp

CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/HG_Edge.cpp > CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.i

CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/HG_Edge.cpp -o CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.s

CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.o: CMakeFiles/main_test.dir/flags.make
CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.o: Hypergraph/HG_Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.o -c /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/HG_Node.cpp

CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/HG_Node.cpp > CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.i

CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jake/PhD/Decomposition/Constraint_Decomposition/Hypergraph/HG_Node.cpp -o CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.s

# Object files for target main_test
main_test_OBJECTS = \
"CMakeFiles/main_test.dir/main.cpp.o" \
"CMakeFiles/main_test.dir/pagmo/Decomp.cpp.o" \
"CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.o" \
"CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.o" \
"CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.o" \
"CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.o"

# External object files for target main_test
main_test_EXTERNAL_OBJECTS =

main_test: CMakeFiles/main_test.dir/main.cpp.o
main_test: CMakeFiles/main_test.dir/pagmo/Decomp.cpp.o
main_test: CMakeFiles/main_test.dir/Hypergraph/Hypergraph.cpp.o
main_test: CMakeFiles/main_test.dir/Hypergraph/Hypergraph_Fileparser.cpp.o
main_test: CMakeFiles/main_test.dir/Hypergraph/HG_Edge.cpp.o
main_test: CMakeFiles/main_test.dir/Hypergraph/HG_Node.cpp.o
main_test: CMakeFiles/main_test.dir/build.make
main_test: /home/jake/.local/lib/libpagmo.so.1.0
main_test: /home/jake/PhD/Edge_Disjoint/c++/boost_1_67_0/Build/lib/libboost_serialization.so
main_test: /home/jake/PhD/Coding_Libraries/tbb/tbb2019_20191006oss/lib/intel64/gcc4.8/libtbb.so.2
main_test: CMakeFiles/main_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable main_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_test.dir/build: main_test

.PHONY : CMakeFiles/main_test.dir/build

CMakeFiles/main_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_test.dir/clean

CMakeFiles/main_test.dir/depend:
	cd /home/jake/PhD/Decomposition/Constraint_Decomposition && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jake/PhD/Decomposition/Constraint_Decomposition /home/jake/PhD/Decomposition/Constraint_Decomposition /home/jake/PhD/Decomposition/Constraint_Decomposition /home/jake/PhD/Decomposition/Constraint_Decomposition /home/jake/PhD/Decomposition/Constraint_Decomposition/CMakeFiles/main_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_test.dir/depend
