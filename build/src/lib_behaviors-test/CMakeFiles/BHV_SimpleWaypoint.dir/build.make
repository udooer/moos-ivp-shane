# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build

# Include any dependencies generated for this target.
include src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/depend.make

# Include the progress variables for this target.
include src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/progress.make

# Include the compile flags for this target's objects.
include src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/flags.make

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/flags.make
src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o: ../src/lib_behaviors-test/BHV_SimpleWaypoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o"
	cd /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o -c /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/src/lib_behaviors-test/BHV_SimpleWaypoint.cpp

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.i"
	cd /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/src/lib_behaviors-test/BHV_SimpleWaypoint.cpp > CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.i

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.s"
	cd /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/src/lib_behaviors-test/BHV_SimpleWaypoint.cpp -o CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.s

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o.requires:

.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o.requires

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o.provides: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o.requires
	$(MAKE) -f src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/build.make src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o.provides.build
.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o.provides

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o.provides.build: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o


src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/flags.make
src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o: ../src/lib_behaviors-test/AOF_SimpleWaypoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o"
	cd /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o -c /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/src/lib_behaviors-test/AOF_SimpleWaypoint.cpp

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.i"
	cd /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/src/lib_behaviors-test/AOF_SimpleWaypoint.cpp > CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.i

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.s"
	cd /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/src/lib_behaviors-test/AOF_SimpleWaypoint.cpp -o CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.s

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o.requires:

.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o.requires

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o.provides: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o.requires
	$(MAKE) -f src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/build.make src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o.provides.build
.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o.provides

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o.provides.build: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o


# Object files for target BHV_SimpleWaypoint
BHV_SimpleWaypoint_OBJECTS = \
"CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o" \
"CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o"

# External object files for target BHV_SimpleWaypoint
BHV_SimpleWaypoint_EXTERNAL_OBJECTS =

../lib/libBHV_SimpleWaypoint.so: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o
../lib/libBHV_SimpleWaypoint.so: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o
../lib/libBHV_SimpleWaypoint.so: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/build.make
../lib/libBHV_SimpleWaypoint.so: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../../lib/libBHV_SimpleWaypoint.so"
	cd /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BHV_SimpleWaypoint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/build: ../lib/libBHV_SimpleWaypoint.so

.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/build

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/requires: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o.requires
src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/requires: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o.requires

.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/requires

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/clean:
	cd /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test && $(CMAKE_COMMAND) -P CMakeFiles/BHV_SimpleWaypoint.dir/cmake_clean.cmake
.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/clean

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/depend:
	cd /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/src/lib_behaviors-test /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test /home/shane/moos-ivp-shane/trunk/moos-ivp-hhshane/build/src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/depend

