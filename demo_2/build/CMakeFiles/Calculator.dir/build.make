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

# Include any dependencies generated for this target.
include CMakeFiles/Calculator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Calculator.dir/flags.make

CMakeFiles/Calculator.dir/src/cmdcalc.cpp.o: CMakeFiles/Calculator.dir/flags.make
CMakeFiles/Calculator.dir/src/cmdcalc.cpp.o: ../src/cmdcalc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuan/Dev/TaskDemos/demo_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Calculator.dir/src/cmdcalc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Calculator.dir/src/cmdcalc.cpp.o -c /home/yuan/Dev/TaskDemos/demo_2/src/cmdcalc.cpp

CMakeFiles/Calculator.dir/src/cmdcalc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calculator.dir/src/cmdcalc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuan/Dev/TaskDemos/demo_2/src/cmdcalc.cpp > CMakeFiles/Calculator.dir/src/cmdcalc.cpp.i

CMakeFiles/Calculator.dir/src/cmdcalc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calculator.dir/src/cmdcalc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuan/Dev/TaskDemos/demo_2/src/cmdcalc.cpp -o CMakeFiles/Calculator.dir/src/cmdcalc.cpp.s

CMakeFiles/Calculator.dir/src/main.cpp.o: CMakeFiles/Calculator.dir/flags.make
CMakeFiles/Calculator.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuan/Dev/TaskDemos/demo_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Calculator.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Calculator.dir/src/main.cpp.o -c /home/yuan/Dev/TaskDemos/demo_2/src/main.cpp

CMakeFiles/Calculator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calculator.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuan/Dev/TaskDemos/demo_2/src/main.cpp > CMakeFiles/Calculator.dir/src/main.cpp.i

CMakeFiles/Calculator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calculator.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuan/Dev/TaskDemos/demo_2/src/main.cpp -o CMakeFiles/Calculator.dir/src/main.cpp.s

CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.o: CMakeFiles/Calculator.dir/flags.make
CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.o: Calculator_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuan/Dev/TaskDemos/demo_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.o -c /home/yuan/Dev/TaskDemos/demo_2/build/Calculator_autogen/mocs_compilation.cpp

CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuan/Dev/TaskDemos/demo_2/build/Calculator_autogen/mocs_compilation.cpp > CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.i

CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuan/Dev/TaskDemos/demo_2/build/Calculator_autogen/mocs_compilation.cpp -o CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.s

# Object files for target Calculator
Calculator_OBJECTS = \
"CMakeFiles/Calculator.dir/src/cmdcalc.cpp.o" \
"CMakeFiles/Calculator.dir/src/main.cpp.o" \
"CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.o"

# External object files for target Calculator
Calculator_EXTERNAL_OBJECTS =

Calculator: CMakeFiles/Calculator.dir/src/cmdcalc.cpp.o
Calculator: CMakeFiles/Calculator.dir/src/main.cpp.o
Calculator: CMakeFiles/Calculator.dir/Calculator_autogen/mocs_compilation.cpp.o
Calculator: CMakeFiles/Calculator.dir/build.make
Calculator: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.11.3
Calculator: /usr/lib/x86_64-linux-gnu/libQt5DBus.so.5.11.3
Calculator: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.11.3
Calculator: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.11.3
Calculator: CMakeFiles/Calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yuan/Dev/TaskDemos/demo_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Calculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Calculator.dir/build: Calculator

.PHONY : CMakeFiles/Calculator.dir/build

CMakeFiles/Calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Calculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Calculator.dir/clean

CMakeFiles/Calculator.dir/depend:
	cd /home/yuan/Dev/TaskDemos/demo_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuan/Dev/TaskDemos/demo_2 /home/yuan/Dev/TaskDemos/demo_2 /home/yuan/Dev/TaskDemos/demo_2/build /home/yuan/Dev/TaskDemos/demo_2/build /home/yuan/Dev/TaskDemos/demo_2/build/CMakeFiles/Calculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Calculator.dir/depend

