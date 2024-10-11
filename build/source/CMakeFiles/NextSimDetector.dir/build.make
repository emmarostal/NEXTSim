# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/jeppe/devel/projects/NEXTSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeppe/devel/projects/NEXTSim/build

# Include any dependencies generated for this target.
include source/CMakeFiles/NextSimDetector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/CMakeFiles/NextSimDetector.dir/compiler_depend.make

# Include the progress variables for this target.
include source/CMakeFiles/NextSimDetector.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/NextSimDetector.dir/flags.make

# Object files for target NextSimDetector
NextSimDetector_OBJECTS =

# External object files for target NextSimDetector
NextSimDetector_EXTERNAL_OBJECTS = \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetMaterials.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetMaterialsMessenger.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetConstruction.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetConstructionMessenger.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetWorld.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetWorldMessenger.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetWorldObject.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetDetector.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetDetectorTypes.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetDetectorMessenger.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetDetectorLayer.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/gdmlSolid.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/nDetDynamicMaterial.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/CERNFrame.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/CERNTapeBox.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/MaterialsManager.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/CERNSupport.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/ArgoneFrame.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/CERNFloor.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/Polyhedron.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/IS530_Chamber.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/IS530_Plastic.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/Tape.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/CloverQuadBuchDetector.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/CloverQuadDetector.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/CloverSingleBuchDetector.cc.o" \
"/home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetectorObj.dir/CloverSingleDetector.cc.o"

source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetMaterials.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetMaterialsMessenger.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetConstruction.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetConstructionMessenger.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetWorld.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetWorldMessenger.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetWorldObject.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetDetector.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetDetectorTypes.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetDetectorMessenger.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetDetectorLayer.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/gdmlSolid.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/nDetDynamicMaterial.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/CERNFrame.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/CERNTapeBox.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/MaterialsManager.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/CERNSupport.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/ArgoneFrame.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/CERNFloor.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/Polyhedron.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/IS530_Chamber.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/IS530_Plastic.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/Tape.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/CloverQuadBuchDetector.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/CloverQuadDetector.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/CloverSingleBuchDetector.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetectorObj.dir/CloverSingleDetector.cc.o
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetector.dir/build.make
source/libNextSimDetector.a: source/CMakeFiles/NextSimDetector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jeppe/devel/projects/NEXTSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libNextSimDetector.a"
	cd /home/jeppe/devel/projects/NEXTSim/build/source && $(CMAKE_COMMAND) -P CMakeFiles/NextSimDetector.dir/cmake_clean_target.cmake
	cd /home/jeppe/devel/projects/NEXTSim/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NextSimDetector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/NextSimDetector.dir/build: source/libNextSimDetector.a
.PHONY : source/CMakeFiles/NextSimDetector.dir/build

source/CMakeFiles/NextSimDetector.dir/clean:
	cd /home/jeppe/devel/projects/NEXTSim/build/source && $(CMAKE_COMMAND) -P CMakeFiles/NextSimDetector.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/NextSimDetector.dir/clean

source/CMakeFiles/NextSimDetector.dir/depend:
	cd /home/jeppe/devel/projects/NEXTSim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeppe/devel/projects/NEXTSim /home/jeppe/devel/projects/NEXTSim/source /home/jeppe/devel/projects/NEXTSim/build /home/jeppe/devel/projects/NEXTSim/build/source /home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/NextSimDetector.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : source/CMakeFiles/NextSimDetector.dir/depend

