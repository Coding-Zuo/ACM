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
include CMakeFiles/ACM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ACM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ACM.dir/flags.make

CMakeFiles/ACM.dir/main.cpp.o: CMakeFiles/ACM.dir/flags.make
CMakeFiles/ACM.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ACM.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ACM.dir/main.cpp.o -c /Users/zuoyuhui/CLionProjects/ACM/main.cpp

CMakeFiles/ACM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ACM.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zuoyuhui/CLionProjects/ACM/main.cpp > CMakeFiles/ACM.dir/main.cpp.i

CMakeFiles/ACM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ACM.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zuoyuhui/CLionProjects/ACM/main.cpp -o CMakeFiles/ACM.dir/main.cpp.s

CMakeFiles/ACM.dir/模板.cpp.o: CMakeFiles/ACM.dir/flags.make
CMakeFiles/ACM.dir/模板.cpp.o: ../模板.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ACM.dir/模板.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ACM.dir/模板.cpp.o -c /Users/zuoyuhui/CLionProjects/ACM/模板.cpp

CMakeFiles/ACM.dir/模板.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ACM.dir/模板.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zuoyuhui/CLionProjects/ACM/模板.cpp > CMakeFiles/ACM.dir/模板.cpp.i

CMakeFiles/ACM.dir/模板.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ACM.dir/模板.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zuoyuhui/CLionProjects/ACM/模板.cpp -o CMakeFiles/ACM.dir/模板.cpp.s

# Object files for target ACM
ACM_OBJECTS = \
"CMakeFiles/ACM.dir/main.cpp.o" \
"CMakeFiles/ACM.dir/模板.cpp.o"

# External object files for target ACM
ACM_EXTERNAL_OBJECTS =

ACM: CMakeFiles/ACM.dir/main.cpp.o
ACM: CMakeFiles/ACM.dir/模板.cpp.o
ACM: CMakeFiles/ACM.dir/build.make
ACM: CMakeFiles/ACM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ACM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ACM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ACM.dir/build: ACM

.PHONY : CMakeFiles/ACM.dir/build

CMakeFiles/ACM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ACM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ACM.dir/clean

CMakeFiles/ACM.dir/depend:
	cd /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zuoyuhui/CLionProjects/ACM /Users/zuoyuhui/CLionProjects/ACM /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug /Users/zuoyuhui/CLionProjects/ACM/cmake-build-debug/CMakeFiles/ACM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ACM.dir/depend

