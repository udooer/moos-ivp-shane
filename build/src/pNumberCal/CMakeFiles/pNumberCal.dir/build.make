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
CMAKE_SOURCE_DIR = /home/shane/moos-ivp-shane

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shane/moos-ivp-shane/build

# Include any dependencies generated for this target.
include src/pNumberCal/CMakeFiles/pNumberCal.dir/depend.make

# Include the progress variables for this target.
include src/pNumberCal/CMakeFiles/pNumberCal.dir/progress.make

# Include the compile flags for this target's objects.
include src/pNumberCal/CMakeFiles/pNumberCal.dir/flags.make

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o: src/pNumberCal/CMakeFiles/pNumberCal.dir/flags.make
src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o: ../src/pNumberCal/NumberCal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pNumberCal.dir/NumberCal.cpp.o -c /home/shane/moos-ivp-shane/src/pNumberCal/NumberCal.cpp

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pNumberCal.dir/NumberCal.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/pNumberCal/NumberCal.cpp > CMakeFiles/pNumberCal.dir/NumberCal.cpp.i

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pNumberCal.dir/NumberCal.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/pNumberCal/NumberCal.cpp -o CMakeFiles/pNumberCal.dir/NumberCal.cpp.s

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o.requires:

.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o.requires

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o.provides: src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o.requires
	$(MAKE) -f src/pNumberCal/CMakeFiles/pNumberCal.dir/build.make src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o.provides.build
.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o.provides

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o.provides.build: src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o


src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o: src/pNumberCal/CMakeFiles/pNumberCal.dir/flags.make
src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o: ../src/pNumberCal/NumberCal_Info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o -c /home/shane/moos-ivp-shane/src/pNumberCal/NumberCal_Info.cpp

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/pNumberCal/NumberCal_Info.cpp > CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.i

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/pNumberCal/NumberCal_Info.cpp -o CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.s

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o.requires:

.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o.requires

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o.provides: src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o.requires
	$(MAKE) -f src/pNumberCal/CMakeFiles/pNumberCal.dir/build.make src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o.provides.build
.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o.provides

src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o.provides.build: src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o


src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o: src/pNumberCal/CMakeFiles/pNumberCal.dir/flags.make
src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o: ../src/pNumberCal/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pNumberCal.dir/main.cpp.o -c /home/shane/moos-ivp-shane/src/pNumberCal/main.cpp

src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pNumberCal.dir/main.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/pNumberCal/main.cpp > CMakeFiles/pNumberCal.dir/main.cpp.i

src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pNumberCal.dir/main.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/pNumberCal/main.cpp -o CMakeFiles/pNumberCal.dir/main.cpp.s

src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o.requires:

.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o.requires

src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o.provides: src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o.requires
	$(MAKE) -f src/pNumberCal/CMakeFiles/pNumberCal.dir/build.make src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o.provides.build
.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o.provides

src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o.provides.build: src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o


src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o: src/pNumberCal/CMakeFiles/pNumberCal.dir/flags.make
src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o: ../src/pNumberCal/MyData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pNumberCal.dir/MyData.cpp.o -c /home/shane/moos-ivp-shane/src/pNumberCal/MyData.cpp

src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pNumberCal.dir/MyData.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/pNumberCal/MyData.cpp > CMakeFiles/pNumberCal.dir/MyData.cpp.i

src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pNumberCal.dir/MyData.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/pNumberCal/MyData.cpp -o CMakeFiles/pNumberCal.dir/MyData.cpp.s

src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o.requires:

.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o.requires

src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o.provides: src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o.requires
	$(MAKE) -f src/pNumberCal/CMakeFiles/pNumberCal.dir/build.make src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o.provides.build
.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o.provides

src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o.provides.build: src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o


# Object files for target pNumberCal
pNumberCal_OBJECTS = \
"CMakeFiles/pNumberCal.dir/NumberCal.cpp.o" \
"CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o" \
"CMakeFiles/pNumberCal.dir/main.cpp.o" \
"CMakeFiles/pNumberCal.dir/MyData.cpp.o"

# External object files for target pNumberCal
pNumberCal_EXTERNAL_OBJECTS =

../bin/pNumberCal: src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o
../bin/pNumberCal: src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o
../bin/pNumberCal: src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o
../bin/pNumberCal: src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o
../bin/pNumberCal: src/pNumberCal/CMakeFiles/pNumberCal.dir/build.make
../bin/pNumberCal: /home/shane/moos-ivp/build/MOOS/MOOSCore/lib/libMOOS.a
../bin/pNumberCal: src/pNumberCal/CMakeFiles/pNumberCal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../../../bin/pNumberCal"
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pNumberCal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pNumberCal/CMakeFiles/pNumberCal.dir/build: ../bin/pNumberCal

.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/build

src/pNumberCal/CMakeFiles/pNumberCal.dir/requires: src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal.cpp.o.requires
src/pNumberCal/CMakeFiles/pNumberCal.dir/requires: src/pNumberCal/CMakeFiles/pNumberCal.dir/NumberCal_Info.cpp.o.requires
src/pNumberCal/CMakeFiles/pNumberCal.dir/requires: src/pNumberCal/CMakeFiles/pNumberCal.dir/main.cpp.o.requires
src/pNumberCal/CMakeFiles/pNumberCal.dir/requires: src/pNumberCal/CMakeFiles/pNumberCal.dir/MyData.cpp.o.requires

.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/requires

src/pNumberCal/CMakeFiles/pNumberCal.dir/clean:
	cd /home/shane/moos-ivp-shane/build/src/pNumberCal && $(CMAKE_COMMAND) -P CMakeFiles/pNumberCal.dir/cmake_clean.cmake
.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/clean

src/pNumberCal/CMakeFiles/pNumberCal.dir/depend:
	cd /home/shane/moos-ivp-shane/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shane/moos-ivp-shane /home/shane/moos-ivp-shane/src/pNumberCal /home/shane/moos-ivp-shane/build /home/shane/moos-ivp-shane/build/src/pNumberCal /home/shane/moos-ivp-shane/build/src/pNumberCal/CMakeFiles/pNumberCal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pNumberCal/CMakeFiles/pNumberCal.dir/depend

