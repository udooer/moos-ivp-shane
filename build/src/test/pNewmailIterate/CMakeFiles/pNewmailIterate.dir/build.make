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
include src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/depend.make

# Include the progress variables for this target.
include src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/progress.make

# Include the compile flags for this target's objects.
include src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/flags.make

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/flags.make
src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o: ../src/test/pNewmailIterate/NewmailIterate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o -c /home/shane/moos-ivp-shane/src/test/pNewmailIterate/NewmailIterate.cpp

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/test/pNewmailIterate/NewmailIterate.cpp > CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.i

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/test/pNewmailIterate/NewmailIterate.cpp -o CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.s

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o.requires:

.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o.requires

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o.provides: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o.requires
	$(MAKE) -f src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/build.make src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o.provides.build
.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o.provides

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o.provides.build: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o


src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/flags.make
src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o: ../src/test/pNewmailIterate/NewmailIterate_Info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o -c /home/shane/moos-ivp-shane/src/test/pNewmailIterate/NewmailIterate_Info.cpp

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/test/pNewmailIterate/NewmailIterate_Info.cpp > CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.i

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/test/pNewmailIterate/NewmailIterate_Info.cpp -o CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.s

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o.requires:

.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o.requires

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o.provides: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o.requires
	$(MAKE) -f src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/build.make src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o.provides.build
.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o.provides

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o.provides.build: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o


src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/flags.make
src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o: ../src/test/pNewmailIterate/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pNewmailIterate.dir/main.cpp.o -c /home/shane/moos-ivp-shane/src/test/pNewmailIterate/main.cpp

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pNewmailIterate.dir/main.cpp.i"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shane/moos-ivp-shane/src/test/pNewmailIterate/main.cpp > CMakeFiles/pNewmailIterate.dir/main.cpp.i

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pNewmailIterate.dir/main.cpp.s"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shane/moos-ivp-shane/src/test/pNewmailIterate/main.cpp -o CMakeFiles/pNewmailIterate.dir/main.cpp.s

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o.requires:

.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o.requires

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o.provides: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o.requires
	$(MAKE) -f src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/build.make src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o.provides.build
.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o.provides

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o.provides.build: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o


# Object files for target pNewmailIterate
pNewmailIterate_OBJECTS = \
"CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o" \
"CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o" \
"CMakeFiles/pNewmailIterate.dir/main.cpp.o"

# External object files for target pNewmailIterate
pNewmailIterate_EXTERNAL_OBJECTS =

../bin/pNewmailIterate: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o
../bin/pNewmailIterate: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o
../bin/pNewmailIterate: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o
../bin/pNewmailIterate: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/build.make
../bin/pNewmailIterate: /home/shane/moos-ivp/build/MOOS/MOOSCore/lib/libMOOS.a
../bin/pNewmailIterate: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shane/moos-ivp-shane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../../../bin/pNewmailIterate"
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pNewmailIterate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/build: ../bin/pNewmailIterate

.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/build

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/requires: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate.cpp.o.requires
src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/requires: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/NewmailIterate_Info.cpp.o.requires
src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/requires: src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/main.cpp.o.requires

.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/requires

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/clean:
	cd /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate && $(CMAKE_COMMAND) -P CMakeFiles/pNewmailIterate.dir/cmake_clean.cmake
.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/clean

src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/depend:
	cd /home/shane/moos-ivp-shane/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shane/moos-ivp-shane /home/shane/moos-ivp-shane/src/test/pNewmailIterate /home/shane/moos-ivp-shane/build /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate /home/shane/moos-ivp-shane/build/src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/test/pNewmailIterate/CMakeFiles/pNewmailIterate.dir/depend
