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

# Include any dependencies generated for this target.
include source/CMakeFiles/NextSimPeripheral.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/CMakeFiles/NextSimPeripheral.dir/compiler_depend.make

# Include the progress variables for this target.
include source/CMakeFiles/NextSimPeripheral.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/NextSimPeripheral.dir/flags.make

# Object files for target NextSimPeripheral
NextSimPeripheral_OBJECTS =

# External object files for target NextSimPeripheral
NextSimPeripheral_EXTERNAL_OBJECTS = \
"/home/emma/Documents/TILGITHUB/build/source/CMakeFiles/NextSimPeripheralObj.dir/optionHandler.cc.o" \
"/home/emma/Documents/TILGITHUB/build/source/CMakeFiles/NextSimPeripheralObj.dir/termColors.cc.o"

source/libNextSimPeripheral.a: source/CMakeFiles/NextSimPeripheralObj.dir/optionHandler.cc.o
source/libNextSimPeripheral.a: source/CMakeFiles/NextSimPeripheralObj.dir/termColors.cc.o
source/libNextSimPeripheral.a: source/CMakeFiles/NextSimPeripheral.dir/build.make
source/libNextSimPeripheral.a: source/CMakeFiles/NextSimPeripheral.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/emma/Documents/TILGITHUB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libNextSimPeripheral.a"
	cd /home/emma/Documents/TILGITHUB/build/source && $(CMAKE_COMMAND) -P CMakeFiles/NextSimPeripheral.dir/cmake_clean_target.cmake
	cd /home/emma/Documents/TILGITHUB/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NextSimPeripheral.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/NextSimPeripheral.dir/build: source/libNextSimPeripheral.a
.PHONY : source/CMakeFiles/NextSimPeripheral.dir/build

source/CMakeFiles/NextSimPeripheral.dir/clean:
	cd /home/emma/Documents/TILGITHUB/build/source && $(CMAKE_COMMAND) -P CMakeFiles/NextSimPeripheral.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/NextSimPeripheral.dir/clean

source/CMakeFiles/NextSimPeripheral.dir/depend:
	cd /home/emma/Documents/TILGITHUB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emma/Documents/TILGITHUB /home/emma/Documents/TILGITHUB/source /home/emma/Documents/TILGITHUB/build /home/emma/Documents/TILGITHUB/build/source /home/emma/Documents/TILGITHUB/build/source/CMakeFiles/NextSimPeripheral.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : source/CMakeFiles/NextSimPeripheral.dir/depend

