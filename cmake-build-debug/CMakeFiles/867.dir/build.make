# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/zuoyuhui/CLionProjects/ACM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/867.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/867.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/867.dir/flags.make

CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.o: CMakeFiles/867.dir/flags.make
CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.o: ../Leetcode/数组/867转置矩阵.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.o -c /Users/zuoyuhui/CLionProjects/ACM/Leetcode/数组/867转置矩阵.cpp

CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zuoyuhui/CLionProjects/ACM/Leetcode/数组/867转置矩阵.cpp > CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.i

CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zuoyuhui/CLionProjects/ACM/Leetcode/数组/867转置矩阵.cpp -o CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.s

# Object files for target 867
867_OBJECTS = \
"CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.o"

# External object files for target 867
867_EXTERNAL_OBJECTS =

867: CMakeFiles/867.dir/Leetcode/数组/867转置矩阵.cpp.o
867: CMakeFiles/867.dir/build.make
867: CMakeFiles/867.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 867"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/867.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/867.dir/build: 867

.PHONY : CMakeFiles/867.dir/build

CMakeFiles/867.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/867.dir/cmake_clean.cmake
.PHONY : CMakeFiles/867.dir/clean

CMakeFiles/867.dir/depend:
	cd /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zuoyuhui/CLionProjects/ACM /Users/zuoyuhui/CLionProjects/ACM /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles/867.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/867.dir/depend

