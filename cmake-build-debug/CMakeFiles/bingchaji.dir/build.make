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
include CMakeFiles/bingchaji.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bingchaji.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bingchaji.dir/flags.make

CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.o: CMakeFiles/bingchaji.dir/flags.make
CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.o: ../Leetcode/马士兵/并查集.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.o -c /Users/zuoyuhui/CLionProjects/ACM/Leetcode/马士兵/并查集.cpp

CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zuoyuhui/CLionProjects/ACM/Leetcode/马士兵/并查集.cpp > CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.i

CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zuoyuhui/CLionProjects/ACM/Leetcode/马士兵/并查集.cpp -o CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.s

# Object files for target bingchaji
bingchaji_OBJECTS = \
"CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.o"

# External object files for target bingchaji
bingchaji_EXTERNAL_OBJECTS =

bingchaji: CMakeFiles/bingchaji.dir/Leetcode/马士兵/并查集.cpp.o
bingchaji: CMakeFiles/bingchaji.dir/build.make
bingchaji: CMakeFiles/bingchaji.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bingchaji"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bingchaji.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bingchaji.dir/build: bingchaji

.PHONY : CMakeFiles/bingchaji.dir/build

CMakeFiles/bingchaji.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bingchaji.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bingchaji.dir/clean

CMakeFiles/bingchaji.dir/depend:
	cd /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zuoyuhui/CLionProjects/ACM /Users/zuoyuhui/CLionProjects/ACM /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles/bingchaji.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bingchaji.dir/depend

