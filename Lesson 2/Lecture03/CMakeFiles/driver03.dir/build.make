# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03"

# Include any dependencies generated for this target.
include CMakeFiles/driver03.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/driver03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/driver03.dir/flags.make

CMakeFiles/driver03.dir/driver03.cpp.o: CMakeFiles/driver03.dir/flags.make
CMakeFiles/driver03.dir/driver03.cpp.o: driver03.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/driver03.dir/driver03.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/driver03.dir/driver03.cpp.o -c "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/driver03.cpp"

CMakeFiles/driver03.dir/driver03.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/driver03.dir/driver03.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/driver03.cpp" > CMakeFiles/driver03.dir/driver03.cpp.i

CMakeFiles/driver03.dir/driver03.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/driver03.dir/driver03.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/driver03.cpp" -o CMakeFiles/driver03.dir/driver03.cpp.s

CMakeFiles/driver03.dir/driver03.cpp.o.requires:

.PHONY : CMakeFiles/driver03.dir/driver03.cpp.o.requires

CMakeFiles/driver03.dir/driver03.cpp.o.provides: CMakeFiles/driver03.dir/driver03.cpp.o.requires
	$(MAKE) -f CMakeFiles/driver03.dir/build.make CMakeFiles/driver03.dir/driver03.cpp.o.provides.build
.PHONY : CMakeFiles/driver03.dir/driver03.cpp.o.provides

CMakeFiles/driver03.dir/driver03.cpp.o.provides.build: CMakeFiles/driver03.dir/driver03.cpp.o


CMakeFiles/driver03.dir/point1.cpp.o: CMakeFiles/driver03.dir/flags.make
CMakeFiles/driver03.dir/point1.cpp.o: point1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/driver03.dir/point1.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/driver03.dir/point1.cpp.o -c "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/point1.cpp"

CMakeFiles/driver03.dir/point1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/driver03.dir/point1.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/point1.cpp" > CMakeFiles/driver03.dir/point1.cpp.i

CMakeFiles/driver03.dir/point1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/driver03.dir/point1.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/point1.cpp" -o CMakeFiles/driver03.dir/point1.cpp.s

CMakeFiles/driver03.dir/point1.cpp.o.requires:

.PHONY : CMakeFiles/driver03.dir/point1.cpp.o.requires

CMakeFiles/driver03.dir/point1.cpp.o.provides: CMakeFiles/driver03.dir/point1.cpp.o.requires
	$(MAKE) -f CMakeFiles/driver03.dir/build.make CMakeFiles/driver03.dir/point1.cpp.o.provides.build
.PHONY : CMakeFiles/driver03.dir/point1.cpp.o.provides

CMakeFiles/driver03.dir/point1.cpp.o.provides.build: CMakeFiles/driver03.dir/point1.cpp.o


# Object files for target driver03
driver03_OBJECTS = \
"CMakeFiles/driver03.dir/driver03.cpp.o" \
"CMakeFiles/driver03.dir/point1.cpp.o"

# External object files for target driver03
driver03_EXTERNAL_OBJECTS =

driver03.exe: CMakeFiles/driver03.dir/driver03.cpp.o
driver03.exe: CMakeFiles/driver03.dir/point1.cpp.o
driver03.exe: CMakeFiles/driver03.dir/build.make
driver03.exe: CMakeFiles/driver03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable driver03.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/driver03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/driver03.dir/build: driver03.exe

.PHONY : CMakeFiles/driver03.dir/build

CMakeFiles/driver03.dir/requires: CMakeFiles/driver03.dir/driver03.cpp.o.requires
CMakeFiles/driver03.dir/requires: CMakeFiles/driver03.dir/point1.cpp.o.requires

.PHONY : CMakeFiles/driver03.dir/requires

CMakeFiles/driver03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/driver03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/driver03.dir/clean

CMakeFiles/driver03.dir/depend:
	cd "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03" "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03" "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03" "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03" "/cygdrive/d/Drive/Documents/School/CS235/Lesson 2/Lecture03/CMakeFiles/driver03.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/driver03.dir/depend

