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
CMAKE_SOURCE_DIR = /home/emma/devel/resources/Clone/NEXTSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emma/devel/resources/Clone/NEXTSim/build

# Include any dependencies generated for this target.
include source/CMakeFiles/NextSimGeneratorObj.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/CMakeFiles/NextSimGeneratorObj.dir/compiler_depend.make

# Include the progress variables for this target.
include source/CMakeFiles/NextSimGeneratorObj.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/NextSimGeneratorObj.dir/flags.make

source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.o: source/CMakeFiles/NextSimGeneratorObj.dir/flags.make
source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.o: /home/emma/devel/resources/Clone/NEXTSim/source/nDetParticleSource.cc
source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.o: source/CMakeFiles/NextSimGeneratorObj.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/emma/devel/resources/Clone/NEXTSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.o"
	cd /home/emma/devel/resources/Clone/NEXTSim/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.o -MF CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.o.d -o CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.o -c /home/emma/devel/resources/Clone/NEXTSim/source/nDetParticleSource.cc

source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.i"
	cd /home/emma/devel/resources/Clone/NEXTSim/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emma/devel/resources/Clone/NEXTSim/source/nDetParticleSource.cc > CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.i

source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.s"
	cd /home/emma/devel/resources/Clone/NEXTSim/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emma/devel/resources/Clone/NEXTSim/source/nDetParticleSource.cc -o CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.s

source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.o: source/CMakeFiles/NextSimGeneratorObj.dir/flags.make
source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.o: /home/emma/devel/resources/Clone/NEXTSim/source/nDetParticleSourceMessenger.cc
source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.o: source/CMakeFiles/NextSimGeneratorObj.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/emma/devel/resources/Clone/NEXTSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.o"
	cd /home/emma/devel/resources/Clone/NEXTSim/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.o -MF CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.o.d -o CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.o -c /home/emma/devel/resources/Clone/NEXTSim/source/nDetParticleSourceMessenger.cc

source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.i"
	cd /home/emma/devel/resources/Clone/NEXTSim/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emma/devel/resources/Clone/NEXTSim/source/nDetParticleSourceMessenger.cc > CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.i

source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.s"
	cd /home/emma/devel/resources/Clone/NEXTSim/build/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emma/devel/resources/Clone/NEXTSim/source/nDetParticleSourceMessenger.cc -o CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.s

NextSimGeneratorObj: source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSource.cc.o
NextSimGeneratorObj: source/CMakeFiles/NextSimGeneratorObj.dir/nDetParticleSourceMessenger.cc.o
NextSimGeneratorObj: source/CMakeFiles/NextSimGeneratorObj.dir/build.make
.PHONY : NextSimGeneratorObj

# Rule to build all files generated by this target.
source/CMakeFiles/NextSimGeneratorObj.dir/build: NextSimGeneratorObj
.PHONY : source/CMakeFiles/NextSimGeneratorObj.dir/build

source/CMakeFiles/NextSimGeneratorObj.dir/clean:
	cd /home/emma/devel/resources/Clone/NEXTSim/build/source && $(CMAKE_COMMAND) -P CMakeFiles/NextSimGeneratorObj.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/NextSimGeneratorObj.dir/clean

source/CMakeFiles/NextSimGeneratorObj.dir/depend:
	cd /home/emma/devel/resources/Clone/NEXTSim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emma/devel/resources/Clone/NEXTSim /home/emma/devel/resources/Clone/NEXTSim/source /home/emma/devel/resources/Clone/NEXTSim/build /home/emma/devel/resources/Clone/NEXTSim/build/source /home/emma/devel/resources/Clone/NEXTSim/build/source/CMakeFiles/NextSimGeneratorObj.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : source/CMakeFiles/NextSimGeneratorObj.dir/depend
