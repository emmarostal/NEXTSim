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
include source/CMakeFiles/nextSim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/CMakeFiles/nextSim.dir/compiler_depend.make

# Include the progress variables for this target.
include source/CMakeFiles/nextSim.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/nextSim.dir/flags.make

source/CMakeFiles/nextSim.dir/nextSim.cc.o: source/CMakeFiles/nextSim.dir/flags.make
source/CMakeFiles/nextSim.dir/nextSim.cc.o: /home/jeppe/devel/projects/NEXTSim/source/nextSim.cc
source/CMakeFiles/nextSim.dir/nextSim.cc.o: source/CMakeFiles/nextSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jeppe/devel/projects/NEXTSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/nextSim.dir/nextSim.cc.o"
	cd /home/jeppe/devel/projects/NEXTSim/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/nextSim.dir/nextSim.cc.o -MF CMakeFiles/nextSim.dir/nextSim.cc.o.d -o CMakeFiles/nextSim.dir/nextSim.cc.o -c /home/jeppe/devel/projects/NEXTSim/source/nextSim.cc

source/CMakeFiles/nextSim.dir/nextSim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/nextSim.dir/nextSim.cc.i"
	cd /home/jeppe/devel/projects/NEXTSim/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeppe/devel/projects/NEXTSim/source/nextSim.cc > CMakeFiles/nextSim.dir/nextSim.cc.i

source/CMakeFiles/nextSim.dir/nextSim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/nextSim.dir/nextSim.cc.s"
	cd /home/jeppe/devel/projects/NEXTSim/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeppe/devel/projects/NEXTSim/source/nextSim.cc -o CMakeFiles/nextSim.dir/nextSim.cc.s

# Object files for target nextSim
nextSim_OBJECTS = \
"CMakeFiles/nextSim.dir/nextSim.cc.o"

# External object files for target nextSim
nextSim_EXTERNAL_OBJECTS =

source/nextSim: source/CMakeFiles/nextSim.dir/nextSim.cc.o
source/nextSim: source/CMakeFiles/nextSim.dir/build.make
source/nextSim: source/libNextSimOutput.a
source/nextSim: source/libNextSimDetector.a
source/nextSim: source/libNextSimGenerator.a
source/nextSim: source/libNextSimPeripheral.a
source/nextSim: source/libNextSimCore.a
source/nextSim: /usr/local/lib/libG4Tree.so
source/nextSim: /usr/local/lib/libG4FR.so
source/nextSim: /usr/local/lib/libG4GMocren.so
source/nextSim: /usr/local/lib/libG4visHepRep.so
source/nextSim: /usr/local/lib/libG4RayTracer.so
source/nextSim: /usr/local/lib/libG4VRML.so
source/nextSim: /usr/local/lib/libG4ToolsSG.so
source/nextSim: /usr/local/lib/libG4OpenGL.so
source/nextSim: /usr/local/lib/libG4visQt3D.so
source/nextSim: /usr/local/lib/libG4visVtk.so
source/nextSim: /usr/local/lib/libG4vis_management.so
source/nextSim: /usr/local/lib/libG4modeling.so
source/nextSim: /usr/local/lib/libG4interfaces.so
source/nextSim: /usr/local/lib/libG4mctruth.so
source/nextSim: /usr/local/lib/libG4geomtext.so
source/nextSim: /usr/local/lib/libG4gdml.so
source/nextSim: /usr/local/lib/libG4error_propagation.so
source/nextSim: /usr/local/lib/libG4readout.so
source/nextSim: /usr/local/lib/libG4physicslists.so
source/nextSim: /usr/local/lib/libG4run.so
source/nextSim: /usr/local/lib/libG4event.so
source/nextSim: /usr/local/lib/libG4tracking.so
source/nextSim: /usr/local/lib/libG4parmodels.so
source/nextSim: /usr/local/lib/libG4processes.so
source/nextSim: /usr/local/lib/libG4digits_hits.so
source/nextSim: /usr/local/lib/libG4track.so
source/nextSim: /usr/local/lib/libG4particles.so
source/nextSim: /usr/local/lib/libG4geometry.so
source/nextSim: /usr/local/lib/libG4materials.so
source/nextSim: /usr/local/lib/libG4graphics_reps.so
source/nextSim: /usr/local/lib/libAUSA.so.17.1
source/nextSim: dict/libNextSimEvent.a
source/nextSim: /usr/lib/x86_64-linux-gnu/libXm.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libXmu.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libXext.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libXt.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libICE.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libSM.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.13
source/nextSim: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.13
source/nextSim: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.13
source/nextSim: /usr/lib/x86_64-linux-gnu/libX11.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libxerces-c.so
source/nextSim: /usr/local/lib/libG4analysis.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libexpat.so
source/nextSim: /usr/local/lib/libG4zlib.so
source/nextSim: /usr/local/lib/libG4intercoms.so
source/nextSim: /usr/local/lib/libG4global.so
source/nextSim: /usr/local/lib/libG4clhep.so
source/nextSim: /usr/local/lib/libG4ptl.so.2.3.3
source/nextSim: /usr/local/lib/libPhysics.so
source/nextSim: /usr/local/lib/libGenVector.so
source/nextSim: /usr/local/lib/libTreePlayer.so
source/nextSim: /usr/local/lib/libGraf3d.so
source/nextSim: /usr/local/lib/libGpad.so
source/nextSim: /usr/local/lib/libGraf.so
source/nextSim: /usr/local/lib/libTree.so
source/nextSim: /usr/local/lib/libMathMore.so
source/nextSim: /usr/local/lib/libSpectrum.so
source/nextSim: /usr/local/lib/libHist.so
source/nextSim: /usr/local/lib/libMatrix.so
source/nextSim: /usr/local/lib/libMathCore.so
source/nextSim: /usr/local/lib/libImt.so
source/nextSim: /usr/local/lib/libMultiProc.so
source/nextSim: /usr/local/lib/libNet.so
source/nextSim: /usr/local/lib/libRIO.so
source/nextSim: /usr/local/lib/libThread.so
source/nextSim: /usr/local/lib/libCore.so
source/nextSim: /usr/local/lib/libCling.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libfmt.so.9.1.0
source/nextSim: /usr/local/lib/libgsl.so
source/nextSim: /usr/local/lib/libgslcblas.so
source/nextSim: /usr/lib/x86_64-linux-gnu/libcurl.so
source/nextSim: source/CMakeFiles/nextSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jeppe/devel/projects/NEXTSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nextSim"
	cd /home/jeppe/devel/projects/NEXTSim/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nextSim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/nextSim.dir/build: source/nextSim
.PHONY : source/CMakeFiles/nextSim.dir/build

source/CMakeFiles/nextSim.dir/clean:
	cd /home/jeppe/devel/projects/NEXTSim/build/source && $(CMAKE_COMMAND) -P CMakeFiles/nextSim.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/nextSim.dir/clean

source/CMakeFiles/nextSim.dir/depend:
	cd /home/jeppe/devel/projects/NEXTSim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeppe/devel/projects/NEXTSim /home/jeppe/devel/projects/NEXTSim/source /home/jeppe/devel/projects/NEXTSim/build /home/jeppe/devel/projects/NEXTSim/build/source /home/jeppe/devel/projects/NEXTSim/build/source/CMakeFiles/nextSim.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : source/CMakeFiles/nextSim.dir/depend

