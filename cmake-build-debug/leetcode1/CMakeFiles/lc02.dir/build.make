# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/liangke/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/222.4345.21/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/liangke/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/222.4345.21/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/liangke/CLionProjects/lc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liangke/CLionProjects/lc/cmake-build-debug

# Include any dependencies generated for this target.
include leetcode1/CMakeFiles/lc02.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include leetcode1/CMakeFiles/lc02.dir/compiler_depend.make

# Include the progress variables for this target.
include leetcode1/CMakeFiles/lc02.dir/progress.make

# Include the compile flags for this target's objects.
include leetcode1/CMakeFiles/lc02.dir/flags.make

leetcode1/CMakeFiles/lc02.dir/lc02.cpp.o: leetcode1/CMakeFiles/lc02.dir/flags.make
leetcode1/CMakeFiles/lc02.dir/lc02.cpp.o: ../leetcode1/lc02.cpp
leetcode1/CMakeFiles/lc02.dir/lc02.cpp.o: leetcode1/CMakeFiles/lc02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liangke/CLionProjects/lc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object leetcode1/CMakeFiles/lc02.dir/lc02.cpp.o"
	cd /Users/liangke/CLionProjects/lc/cmake-build-debug/leetcode1 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT leetcode1/CMakeFiles/lc02.dir/lc02.cpp.o -MF CMakeFiles/lc02.dir/lc02.cpp.o.d -o CMakeFiles/lc02.dir/lc02.cpp.o -c /Users/liangke/CLionProjects/lc/leetcode1/lc02.cpp

leetcode1/CMakeFiles/lc02.dir/lc02.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc02.dir/lc02.cpp.i"
	cd /Users/liangke/CLionProjects/lc/cmake-build-debug/leetcode1 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liangke/CLionProjects/lc/leetcode1/lc02.cpp > CMakeFiles/lc02.dir/lc02.cpp.i

leetcode1/CMakeFiles/lc02.dir/lc02.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc02.dir/lc02.cpp.s"
	cd /Users/liangke/CLionProjects/lc/cmake-build-debug/leetcode1 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liangke/CLionProjects/lc/leetcode1/lc02.cpp -o CMakeFiles/lc02.dir/lc02.cpp.s

# Object files for target lc02
lc02_OBJECTS = \
"CMakeFiles/lc02.dir/lc02.cpp.o"

# External object files for target lc02
lc02_EXTERNAL_OBJECTS =

leetcode1/lc02: leetcode1/CMakeFiles/lc02.dir/lc02.cpp.o
leetcode1/lc02: leetcode1/CMakeFiles/lc02.dir/build.make
leetcode1/lc02: leetcode1/CMakeFiles/lc02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liangke/CLionProjects/lc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lc02"
	cd /Users/liangke/CLionProjects/lc/cmake-build-debug/leetcode1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lc02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
leetcode1/CMakeFiles/lc02.dir/build: leetcode1/lc02
.PHONY : leetcode1/CMakeFiles/lc02.dir/build

leetcode1/CMakeFiles/lc02.dir/clean:
	cd /Users/liangke/CLionProjects/lc/cmake-build-debug/leetcode1 && $(CMAKE_COMMAND) -P CMakeFiles/lc02.dir/cmake_clean.cmake
.PHONY : leetcode1/CMakeFiles/lc02.dir/clean

leetcode1/CMakeFiles/lc02.dir/depend:
	cd /Users/liangke/CLionProjects/lc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liangke/CLionProjects/lc /Users/liangke/CLionProjects/lc/leetcode1 /Users/liangke/CLionProjects/lc/cmake-build-debug /Users/liangke/CLionProjects/lc/cmake-build-debug/leetcode1 /Users/liangke/CLionProjects/lc/cmake-build-debug/leetcode1/CMakeFiles/lc02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : leetcode1/CMakeFiles/lc02.dir/depend
