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
CMAKE_SOURCE_DIR = /home/wxx/Project/ServerTest/socket2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wxx/Project/ServerTest/socket2/build

# Include any dependencies generated for this target.
include CMakeFiles/client3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client3.dir/flags.make

CMakeFiles/client3.dir/src/client3.cpp.o: CMakeFiles/client3.dir/flags.make
CMakeFiles/client3.dir/src/client3.cpp.o: ../src/client3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wxx/Project/ServerTest/socket2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client3.dir/src/client3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client3.dir/src/client3.cpp.o -c /home/wxx/Project/ServerTest/socket2/src/client3.cpp

CMakeFiles/client3.dir/src/client3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client3.dir/src/client3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wxx/Project/ServerTest/socket2/src/client3.cpp > CMakeFiles/client3.dir/src/client3.cpp.i

CMakeFiles/client3.dir/src/client3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client3.dir/src/client3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wxx/Project/ServerTest/socket2/src/client3.cpp -o CMakeFiles/client3.dir/src/client3.cpp.s

CMakeFiles/client3.dir/src/client3.cpp.o.requires:

.PHONY : CMakeFiles/client3.dir/src/client3.cpp.o.requires

CMakeFiles/client3.dir/src/client3.cpp.o.provides: CMakeFiles/client3.dir/src/client3.cpp.o.requires
	$(MAKE) -f CMakeFiles/client3.dir/build.make CMakeFiles/client3.dir/src/client3.cpp.o.provides.build
.PHONY : CMakeFiles/client3.dir/src/client3.cpp.o.provides

CMakeFiles/client3.dir/src/client3.cpp.o.provides.build: CMakeFiles/client3.dir/src/client3.cpp.o


# Object files for target client3
client3_OBJECTS = \
"CMakeFiles/client3.dir/src/client3.cpp.o"

# External object files for target client3
client3_EXTERNAL_OBJECTS =

client3: CMakeFiles/client3.dir/src/client3.cpp.o
client3: CMakeFiles/client3.dir/build.make
client3: CMakeFiles/client3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wxx/Project/ServerTest/socket2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable client3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client3.dir/build: client3

.PHONY : CMakeFiles/client3.dir/build

CMakeFiles/client3.dir/requires: CMakeFiles/client3.dir/src/client3.cpp.o.requires

.PHONY : CMakeFiles/client3.dir/requires

CMakeFiles/client3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client3.dir/clean

CMakeFiles/client3.dir/depend:
	cd /home/wxx/Project/ServerTest/socket2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wxx/Project/ServerTest/socket2 /home/wxx/Project/ServerTest/socket2 /home/wxx/Project/ServerTest/socket2/build /home/wxx/Project/ServerTest/socket2/build /home/wxx/Project/ServerTest/socket2/build/CMakeFiles/client3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client3.dir/depend

