# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shane/moos-ivp-shane

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shane/moos-ivp-shane/build

# Include any dependencies generated for this target.
include src/pAngleDecision/CMakeFiles/pAngleDecision.dir/depend.make

# Include the progress variables for this target.
include src/pAngleDecision/CMakeFiles/pAngleDecision.dir/progress.make

# Include the compile flags for this target's objects.
include src/pAngleDecision/CMakeFiles/pAngleDecision.dir/flags.make

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/flags.make
src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o: ../src/pAngleDecision/AngleDecision.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o -c /home/shane/moos-ivp-shane/src/pAngleDecision/AngleDecision.cpp

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/pAngleDecision/AngleDecision.cpp > CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.i

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/pAngleDecision/AngleDecision.cpp -o CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.s

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o.requires:

.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o.requires

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o.provides: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o.requires
	$(MAKE) -f src/pAngleDecision/CMakeFiles/pAngleDecision.dir/build.make src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o.provides.build
.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o.provides

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o.provides.build: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o


src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/flags.make
src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o: ../src/pAngleDecision/AngleDecision_Info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o -c /home/shane/moos-ivp-shane/src/pAngleDecision/AngleDecision_Info.cpp

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/pAngleDecision/AngleDecision_Info.cpp > CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.i

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/pAngleDecision/AngleDecision_Info.cpp -o CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.s

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o.requires:

.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o.requires

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o.provides: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o.requires
	$(MAKE) -f src/pAngleDecision/CMakeFiles/pAngleDecision.dir/build.make src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o.provides.build
.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o.provides

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o.provides.build: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o


src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/flags.make
src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o: ../src/pAngleDecision/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pAngleDecision.dir/main.cpp.o -c /home/shane/moos-ivp-shane/src/pAngleDecision/main.cpp

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pAngleDecision.dir/main.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/pAngleDecision/main.cpp > CMakeFiles/pAngleDecision.dir/main.cpp.i

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pAngleDecision.dir/main.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/pAngleDecision/main.cpp -o CMakeFiles/pAngleDecision.dir/main.cpp.s

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o.requires:

.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o.requires

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o.provides: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o.requires
	$(MAKE) -f src/pAngleDecision/CMakeFiles/pAngleDecision.dir/build.make src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o.provides.build
.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o.provides

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o.provides.build: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o


# Object files for target pAngleDecision
pAngleDecision_OBJECTS = \
"CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o" \
"CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o" \
"CMakeFiles/pAngleDecision.dir/main.cpp.o"

# External object files for target pAngleDecision
pAngleDecision_EXTERNAL_OBJECTS =

../bin/pAngleDecision: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o
../bin/pAngleDecision: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o
../bin/pAngleDecision: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o
../bin/pAngleDecision: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/build.make
../bin/pAngleDecision: /home/shane/moos-ivp/build/MOOS/MOOSCore/lib/libMOOS.a
../bin/pAngleDecision: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../../bin/pAngleDecision"
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pAngleDecision.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pAngleDecision/CMakeFiles/pAngleDecision.dir/build: ../bin/pAngleDecision

.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/build

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/requires: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision.cpp.o.requires
src/pAngleDecision/CMakeFiles/pAngleDecision.dir/requires: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/AngleDecision_Info.cpp.o.requires
src/pAngleDecision/CMakeFiles/pAngleDecision.dir/requires: src/pAngleDecision/CMakeFiles/pAngleDecision.dir/main.cpp.o.requires

.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/requires

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/clean:
	cd /home/shane/moos-ivp-shane/build/src/pAngleDecision && $(CMAKE_COMMAND) -P CMakeFiles/pAngleDecision.dir/cmake_clean.cmake
.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/clean

src/pAngleDecision/CMakeFiles/pAngleDecision.dir/depend:
	cd /home/shane/moos-ivp-shane/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shane/moos-ivp-shane /home/shane/moos-ivp-shane/src/pAngleDecision /home/shane/moos-ivp-shane/build /home/shane/moos-ivp-shane/build/src/pAngleDecision /home/shane/moos-ivp-shane/build/src/pAngleDecision/CMakeFiles/pAngleDecision.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pAngleDecision/CMakeFiles/pAngleDecision.dir/depend

