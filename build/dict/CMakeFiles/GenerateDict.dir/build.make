# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/emma/Documents/TILGITHUB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emma/Documents/TILGITHUB/build

# Utility rule file for GenerateDict.

# Include any custom commands dependencies for this target.
include dict/CMakeFiles/GenerateDict.dir/compiler_depend.make

# Include the progress variables for this target.
include dict/CMakeFiles/GenerateDict.dir/progress.make

dict/CMakeFiles/GenerateDict: /home/emma/Documents/TILGITHUB/dict/source/nDetStructures.cpp
dict/CMakeFiles/GenerateDict: /home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp
dict/CMakeFiles/GenerateDict: /home/emma/Documents/TILGITHUB/dict/include/LinkDef.h
dict/CMakeFiles/GenerateDict: dict/NextSimEvent.cpp

dict/NextSimEvent.cpp: /home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp
dict/NextSimEvent.cpp: /home/emma/Documents/TILGITHUB/dict/include/LinkDef.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/emma/Documents/TILGITHUB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating NextSimEvent.cpp"
	cd /home/emma/Documents/TILGITHUB/build/dict && /home/emma/devel/resources/root/root/bin/rootcint -f /home/emma/Documents/TILGITHUB/build/dict/NextSimEvent.cpp -c /home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp /home/emma/Documents/TILGITHUB/dict/include/LinkDef.h

GenerateDict: dict/CMakeFiles/GenerateDict
GenerateDict: dict/NextSimEvent.cpp
GenerateDict: dict/CMakeFiles/GenerateDict.dir/build.make
.PHONY : GenerateDict

# Rule to build all files generated by this target.
dict/CMakeFiles/GenerateDict.dir/build: GenerateDict
.PHONY : dict/CMakeFiles/GenerateDict.dir/build

dict/CMakeFiles/GenerateDict.dir/clean:
	cd /home/emma/Documents/TILGITHUB/build/dict && $(CMAKE_COMMAND) -P CMakeFiles/GenerateDict.dir/cmake_clean.cmake
.PHONY : dict/CMakeFiles/GenerateDict.dir/clean

dict/CMakeFiles/GenerateDict.dir/depend:
	cd /home/emma/Documents/TILGITHUB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emma/Documents/TILGITHUB /home/emma/Documents/TILGITHUB/dict /home/emma/Documents/TILGITHUB/build /home/emma/Documents/TILGITHUB/build/dict /home/emma/Documents/TILGITHUB/build/dict/CMakeFiles/GenerateDict.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : dict/CMakeFiles/GenerateDict.dir/depend

