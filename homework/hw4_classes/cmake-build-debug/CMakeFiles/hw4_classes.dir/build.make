# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/murt/Programs/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/murt/Programs/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/murt/CLionProjects/hw4_classes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/murt/CLionProjects/hw4_classes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw4_classes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw4_classes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw4_classes.dir/flags.make

CMakeFiles/hw4_classes.dir/main.cpp.o: CMakeFiles/hw4_classes.dir/flags.make
CMakeFiles/hw4_classes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murt/CLionProjects/hw4_classes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw4_classes.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw4_classes.dir/main.cpp.o -c /home/murt/CLionProjects/hw4_classes/main.cpp

CMakeFiles/hw4_classes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4_classes.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/murt/CLionProjects/hw4_classes/main.cpp > CMakeFiles/hw4_classes.dir/main.cpp.i

CMakeFiles/hw4_classes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4_classes.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/murt/CLionProjects/hw4_classes/main.cpp -o CMakeFiles/hw4_classes.dir/main.cpp.s

CMakeFiles/hw4_classes.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/hw4_classes.dir/main.cpp.o.requires

CMakeFiles/hw4_classes.dir/main.cpp.o.provides: CMakeFiles/hw4_classes.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw4_classes.dir/build.make CMakeFiles/hw4_classes.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/hw4_classes.dir/main.cpp.o.provides

CMakeFiles/hw4_classes.dir/main.cpp.o.provides.build: CMakeFiles/hw4_classes.dir/main.cpp.o


CMakeFiles/hw4_classes.dir/person_class.cpp.o: CMakeFiles/hw4_classes.dir/flags.make
CMakeFiles/hw4_classes.dir/person_class.cpp.o: ../person_class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murt/CLionProjects/hw4_classes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw4_classes.dir/person_class.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw4_classes.dir/person_class.cpp.o -c /home/murt/CLionProjects/hw4_classes/person_class.cpp

CMakeFiles/hw4_classes.dir/person_class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4_classes.dir/person_class.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/murt/CLionProjects/hw4_classes/person_class.cpp > CMakeFiles/hw4_classes.dir/person_class.cpp.i

CMakeFiles/hw4_classes.dir/person_class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4_classes.dir/person_class.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/murt/CLionProjects/hw4_classes/person_class.cpp -o CMakeFiles/hw4_classes.dir/person_class.cpp.s

CMakeFiles/hw4_classes.dir/person_class.cpp.o.requires:

.PHONY : CMakeFiles/hw4_classes.dir/person_class.cpp.o.requires

CMakeFiles/hw4_classes.dir/person_class.cpp.o.provides: CMakeFiles/hw4_classes.dir/person_class.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw4_classes.dir/build.make CMakeFiles/hw4_classes.dir/person_class.cpp.o.provides.build
.PHONY : CMakeFiles/hw4_classes.dir/person_class.cpp.o.provides

CMakeFiles/hw4_classes.dir/person_class.cpp.o.provides.build: CMakeFiles/hw4_classes.dir/person_class.cpp.o


CMakeFiles/hw4_classes.dir/functions.cpp.o: CMakeFiles/hw4_classes.dir/flags.make
CMakeFiles/hw4_classes.dir/functions.cpp.o: ../functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murt/CLionProjects/hw4_classes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hw4_classes.dir/functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw4_classes.dir/functions.cpp.o -c /home/murt/CLionProjects/hw4_classes/functions.cpp

CMakeFiles/hw4_classes.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4_classes.dir/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/murt/CLionProjects/hw4_classes/functions.cpp > CMakeFiles/hw4_classes.dir/functions.cpp.i

CMakeFiles/hw4_classes.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4_classes.dir/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/murt/CLionProjects/hw4_classes/functions.cpp -o CMakeFiles/hw4_classes.dir/functions.cpp.s

CMakeFiles/hw4_classes.dir/functions.cpp.o.requires:

.PHONY : CMakeFiles/hw4_classes.dir/functions.cpp.o.requires

CMakeFiles/hw4_classes.dir/functions.cpp.o.provides: CMakeFiles/hw4_classes.dir/functions.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw4_classes.dir/build.make CMakeFiles/hw4_classes.dir/functions.cpp.o.provides.build
.PHONY : CMakeFiles/hw4_classes.dir/functions.cpp.o.provides

CMakeFiles/hw4_classes.dir/functions.cpp.o.provides.build: CMakeFiles/hw4_classes.dir/functions.cpp.o


# Object files for target hw4_classes
hw4_classes_OBJECTS = \
"CMakeFiles/hw4_classes.dir/main.cpp.o" \
"CMakeFiles/hw4_classes.dir/person_class.cpp.o" \
"CMakeFiles/hw4_classes.dir/functions.cpp.o"

# External object files for target hw4_classes
hw4_classes_EXTERNAL_OBJECTS =

hw4_classes: CMakeFiles/hw4_classes.dir/main.cpp.o
hw4_classes: CMakeFiles/hw4_classes.dir/person_class.cpp.o
hw4_classes: CMakeFiles/hw4_classes.dir/functions.cpp.o
hw4_classes: CMakeFiles/hw4_classes.dir/build.make
hw4_classes: CMakeFiles/hw4_classes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/murt/CLionProjects/hw4_classes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable hw4_classes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw4_classes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw4_classes.dir/build: hw4_classes

.PHONY : CMakeFiles/hw4_classes.dir/build

CMakeFiles/hw4_classes.dir/requires: CMakeFiles/hw4_classes.dir/main.cpp.o.requires
CMakeFiles/hw4_classes.dir/requires: CMakeFiles/hw4_classes.dir/person_class.cpp.o.requires
CMakeFiles/hw4_classes.dir/requires: CMakeFiles/hw4_classes.dir/functions.cpp.o.requires

.PHONY : CMakeFiles/hw4_classes.dir/requires

CMakeFiles/hw4_classes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw4_classes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw4_classes.dir/clean

CMakeFiles/hw4_classes.dir/depend:
	cd /home/murt/CLionProjects/hw4_classes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/murt/CLionProjects/hw4_classes /home/murt/CLionProjects/hw4_classes /home/murt/CLionProjects/hw4_classes/cmake-build-debug /home/murt/CLionProjects/hw4_classes/cmake-build-debug /home/murt/CLionProjects/hw4_classes/cmake-build-debug/CMakeFiles/hw4_classes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw4_classes.dir/depend

