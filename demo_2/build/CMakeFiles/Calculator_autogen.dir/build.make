# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/yuan/Dev/TaskDemos/demo_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuan/Dev/TaskDemos/demo_2/build

# Utility rule file for Calculator_autogen.

# Include the progress variables for this target.
include CMakeFiles/Calculator_autogen.dir/progress.make

CMakeFiles/Calculator_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yuan/Dev/TaskDemos/demo_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target Calculator"
	/usr/bin/cmake -E cmake_autogen /home/yuan/Dev/TaskDemos/demo_2/build/CMakeFiles/Calculator_autogen.dir/AutogenInfo.cmake ""

Calculator_autogen: CMakeFiles/Calculator_autogen
Calculator_autogen: CMakeFiles/Calculator_autogen.dir/build.make

.PHONY : Calculator_autogen

# Rule to build all files generated by this target.
CMakeFiles/Calculator_autogen.dir/build: Calculator_autogen

.PHONY : CMakeFiles/Calculator_autogen.dir/build

CMakeFiles/Calculator_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Calculator_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Calculator_autogen.dir/clean

CMakeFiles/Calculator_autogen.dir/depend:
	cd /home/yuan/Dev/TaskDemos/demo_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuan/Dev/TaskDemos/demo_2 /home/yuan/Dev/TaskDemos/demo_2 /home/yuan/Dev/TaskDemos/demo_2/build /home/yuan/Dev/TaskDemos/demo_2/build /home/yuan/Dev/TaskDemos/demo_2/build/CMakeFiles/Calculator_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Calculator_autogen.dir/depend

