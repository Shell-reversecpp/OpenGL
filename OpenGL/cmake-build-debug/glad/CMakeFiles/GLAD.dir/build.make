# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2023.2.2/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /opt/clion-2023.2.2/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/snake0x8/CLionProjects/OpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug

# Include any dependencies generated for this target.
include glad/CMakeFiles/GLAD.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glad/CMakeFiles/GLAD.dir/compiler_depend.make

# Include the progress variables for this target.
include glad/CMakeFiles/GLAD.dir/progress.make

# Include the compile flags for this target's objects.
include glad/CMakeFiles/GLAD.dir/flags.make

glad/CMakeFiles/GLAD.dir/src/glad.c.o: glad/CMakeFiles/GLAD.dir/flags.make
glad/CMakeFiles/GLAD.dir/src/glad.c.o: /home/snake0x8/CLionProjects/OpenGL/glad/src/glad.c
glad/CMakeFiles/GLAD.dir/src/glad.c.o: glad/CMakeFiles/GLAD.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glad/CMakeFiles/GLAD.dir/src/glad.c.o"
	cd /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glad/CMakeFiles/GLAD.dir/src/glad.c.o -MF CMakeFiles/GLAD.dir/src/glad.c.o.d -o CMakeFiles/GLAD.dir/src/glad.c.o -c /home/snake0x8/CLionProjects/OpenGL/glad/src/glad.c

glad/CMakeFiles/GLAD.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GLAD.dir/src/glad.c.i"
	cd /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/snake0x8/CLionProjects/OpenGL/glad/src/glad.c > CMakeFiles/GLAD.dir/src/glad.c.i

glad/CMakeFiles/GLAD.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GLAD.dir/src/glad.c.s"
	cd /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/snake0x8/CLionProjects/OpenGL/glad/src/glad.c -o CMakeFiles/GLAD.dir/src/glad.c.s

# Object files for target GLAD
GLAD_OBJECTS = \
"CMakeFiles/GLAD.dir/src/glad.c.o"

# External object files for target GLAD
GLAD_EXTERNAL_OBJECTS =

glad/libGLAD.a: glad/CMakeFiles/GLAD.dir/src/glad.c.o
glad/libGLAD.a: glad/CMakeFiles/GLAD.dir/build.make
glad/libGLAD.a: glad/CMakeFiles/GLAD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libGLAD.a"
	cd /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/glad && $(CMAKE_COMMAND) -P CMakeFiles/GLAD.dir/cmake_clean_target.cmake
	cd /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GLAD.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glad/CMakeFiles/GLAD.dir/build: glad/libGLAD.a
.PHONY : glad/CMakeFiles/GLAD.dir/build

glad/CMakeFiles/GLAD.dir/clean:
	cd /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/glad && $(CMAKE_COMMAND) -P CMakeFiles/GLAD.dir/cmake_clean.cmake
.PHONY : glad/CMakeFiles/GLAD.dir/clean

glad/CMakeFiles/GLAD.dir/depend:
	cd /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/snake0x8/CLionProjects/OpenGL /home/snake0x8/CLionProjects/OpenGL/glad /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/glad /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/glad/CMakeFiles/GLAD.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glad/CMakeFiles/GLAD.dir/depend

