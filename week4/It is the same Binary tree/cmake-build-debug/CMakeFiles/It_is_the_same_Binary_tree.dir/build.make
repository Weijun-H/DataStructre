# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/It_is_the_same_Binary_tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/It_is_the_same_Binary_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/It_is_the_same_Binary_tree.dir/flags.make

CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.o: CMakeFiles/It_is_the_same_Binary_tree.dir/flags.make
CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.o -c "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/main.cpp"

CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/main.cpp" > CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.i

CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/main.cpp" -o CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.s

# Object files for target It_is_the_same_Binary_tree
It_is_the_same_Binary_tree_OBJECTS = \
"CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.o"

# External object files for target It_is_the_same_Binary_tree
It_is_the_same_Binary_tree_EXTERNAL_OBJECTS =

It_is_the_same_Binary_tree: CMakeFiles/It_is_the_same_Binary_tree.dir/main.cpp.o
It_is_the_same_Binary_tree: CMakeFiles/It_is_the_same_Binary_tree.dir/build.make
It_is_the_same_Binary_tree: CMakeFiles/It_is_the_same_Binary_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable It_is_the_same_Binary_tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/It_is_the_same_Binary_tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/It_is_the_same_Binary_tree.dir/build: It_is_the_same_Binary_tree

.PHONY : CMakeFiles/It_is_the_same_Binary_tree.dir/build

CMakeFiles/It_is_the_same_Binary_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/It_is_the_same_Binary_tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/It_is_the_same_Binary_tree.dir/clean

CMakeFiles/It_is_the_same_Binary_tree.dir/depend:
	cd "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree" "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree" "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/cmake-build-debug" "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/cmake-build-debug" "/Users/huangweijun/Desktop/DataStructre/week4/It is the same Binary tree/cmake-build-debug/CMakeFiles/It_is_the_same_Binary_tree.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/It_is_the_same_Binary_tree.dir/depend

