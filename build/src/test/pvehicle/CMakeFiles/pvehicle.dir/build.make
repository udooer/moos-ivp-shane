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
include src/test/pvehicle/CMakeFiles/pvehicle.dir/depend.make

# Include the progress variables for this target.
include src/test/pvehicle/CMakeFiles/pvehicle.dir/progress.make

# Include the compile flags for this target's objects.
include src/test/pvehicle/CMakeFiles/pvehicle.dir/flags.make

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o: src/test/pvehicle/CMakeFiles/pvehicle.dir/flags.make
src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o: ../src/test/pvehicle/vehicle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pvehicle.dir/vehicle.cpp.o -c /home/shane/moos-ivp-shane/src/test/pvehicle/vehicle.cpp

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pvehicle.dir/vehicle.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/test/pvehicle/vehicle.cpp > CMakeFiles/pvehicle.dir/vehicle.cpp.i

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pvehicle.dir/vehicle.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/test/pvehicle/vehicle.cpp -o CMakeFiles/pvehicle.dir/vehicle.cpp.s

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o.requires:

.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o.requires

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o.provides: src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o.requires
	$(MAKE) -f src/test/pvehicle/CMakeFiles/pvehicle.dir/build.make src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o.provides.build
.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o.provides

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o.provides.build: src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o


src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o: src/test/pvehicle/CMakeFiles/pvehicle.dir/flags.make
src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o: ../src/test/pvehicle/vehicle_Info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o -c /home/shane/moos-ivp-shane/src/test/pvehicle/vehicle_Info.cpp

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pvehicle.dir/vehicle_Info.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/test/pvehicle/vehicle_Info.cpp > CMakeFiles/pvehicle.dir/vehicle_Info.cpp.i

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pvehicle.dir/vehicle_Info.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/test/pvehicle/vehicle_Info.cpp -o CMakeFiles/pvehicle.dir/vehicle_Info.cpp.s

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o.requires:

.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o.requires

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o.provides: src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o.requires
	$(MAKE) -f src/test/pvehicle/CMakeFiles/pvehicle.dir/build.make src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o.provides.build
.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o.provides

src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o.provides.build: src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o


src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o: src/test/pvehicle/CMakeFiles/pvehicle.dir/flags.make
src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o: ../src/test/pvehicle/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pvehicle.dir/main.cpp.o -c /home/shane/moos-ivp-shane/src/test/pvehicle/main.cpp

src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pvehicle.dir/main.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/test/pvehicle/main.cpp > CMakeFiles/pvehicle.dir/main.cpp.i

src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pvehicle.dir/main.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/test/pvehicle/main.cpp -o CMakeFiles/pvehicle.dir/main.cpp.s

src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o.requires:

.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o.requires

src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o.provides: src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o.requires
	$(MAKE) -f src/test/pvehicle/CMakeFiles/pvehicle.dir/build.make src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o.provides.build
.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o.provides

src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o.provides.build: src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o


# Object files for target pvehicle
pvehicle_OBJECTS = \
"CMakeFiles/pvehicle.dir/vehicle.cpp.o" \
"CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o" \
"CMakeFiles/pvehicle.dir/main.cpp.o"

# External object files for target pvehicle
pvehicle_EXTERNAL_OBJECTS =

../bin/pvehicle: src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o
../bin/pvehicle: src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o
../bin/pvehicle: src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o
../bin/pvehicle: src/test/pvehicle/CMakeFiles/pvehicle.dir/build.make
../bin/pvehicle: /home/shane/moos-ivp/build/MOOS/MOOSCore/lib/libMOOS.a
../bin/pvehicle: src/test/pvehicle/CMakeFiles/pvehicle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../../../bin/pvehicle"
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pvehicle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/test/pvehicle/CMakeFiles/pvehicle.dir/build: ../bin/pvehicle

.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/build

src/test/pvehicle/CMakeFiles/pvehicle.dir/requires: src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle.cpp.o.requires
src/test/pvehicle/CMakeFiles/pvehicle.dir/requires: src/test/pvehicle/CMakeFiles/pvehicle.dir/vehicle_Info.cpp.o.requires
src/test/pvehicle/CMakeFiles/pvehicle.dir/requires: src/test/pvehicle/CMakeFiles/pvehicle.dir/main.cpp.o.requires

.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/requires

src/test/pvehicle/CMakeFiles/pvehicle.dir/clean:
	cd /home/shane/moos-ivp-shane/build/src/test/pvehicle && $(CMAKE_COMMAND) -P CMakeFiles/pvehicle.dir/cmake_clean.cmake
.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/clean

src/test/pvehicle/CMakeFiles/pvehicle.dir/depend:
	cd /home/shane/moos-ivp-shane/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shane/moos-ivp-shane /home/shane/moos-ivp-shane/src/test/pvehicle /home/shane/moos-ivp-shane/build /home/shane/moos-ivp-shane/build/src/test/pvehicle /home/shane/moos-ivp-shane/build/src/test/pvehicle/CMakeFiles/pvehicle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/test/pvehicle/CMakeFiles/pvehicle.dir/depend
