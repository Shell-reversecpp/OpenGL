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
include CMakeFiles/OpenGl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenGl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGl.dir/flags.make

CMakeFiles/OpenGl.dir/main.cpp.o: CMakeFiles/OpenGl.dir/flags.make
CMakeFiles/OpenGl.dir/main.cpp.o: /home/snake0x8/CLionProjects/OpenGL/main.cpp
CMakeFiles/OpenGl.dir/main.cpp.o: CMakeFiles/OpenGl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGl.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGl.dir/main.cpp.o -MF CMakeFiles/OpenGl.dir/main.cpp.o.d -o CMakeFiles/OpenGl.dir/main.cpp.o -c /home/snake0x8/CLionProjects/OpenGL/main.cpp

CMakeFiles/OpenGl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGl.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/snake0x8/CLionProjects/OpenGL/main.cpp > CMakeFiles/OpenGl.dir/main.cpp.i

CMakeFiles/OpenGl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGl.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/snake0x8/CLionProjects/OpenGL/main.cpp -o CMakeFiles/OpenGl.dir/main.cpp.s

CMakeFiles/OpenGl.dir/Shaders.cpp.o: CMakeFiles/OpenGl.dir/flags.make
CMakeFiles/OpenGl.dir/Shaders.cpp.o: /home/snake0x8/CLionProjects/OpenGL/Shaders.cpp
CMakeFiles/OpenGl.dir/Shaders.cpp.o: CMakeFiles/OpenGl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGl.dir/Shaders.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGl.dir/Shaders.cpp.o -MF CMakeFiles/OpenGl.dir/Shaders.cpp.o.d -o CMakeFiles/OpenGl.dir/Shaders.cpp.o -c /home/snake0x8/CLionProjects/OpenGL/Shaders.cpp

CMakeFiles/OpenGl.dir/Shaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGl.dir/Shaders.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/snake0x8/CLionProjects/OpenGL/Shaders.cpp > CMakeFiles/OpenGl.dir/Shaders.cpp.i

CMakeFiles/OpenGl.dir/Shaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGl.dir/Shaders.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/snake0x8/CLionProjects/OpenGL/Shaders.cpp -o CMakeFiles/OpenGl.dir/Shaders.cpp.s

CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.o: CMakeFiles/OpenGl.dir/flags.make
CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.o: /home/snake0x8/CLionProjects/OpenGL/HighResolutionTimer.cpp
CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.o: CMakeFiles/OpenGl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.o -MF CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.o.d -o CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.o -c /home/snake0x8/CLionProjects/OpenGL/HighResolutionTimer.cpp

CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/snake0x8/CLionProjects/OpenGL/HighResolutionTimer.cpp > CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.i

CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/snake0x8/CLionProjects/OpenGL/HighResolutionTimer.cpp -o CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.s

CMakeFiles/OpenGl.dir/GameWindow.cpp.o: CMakeFiles/OpenGl.dir/flags.make
CMakeFiles/OpenGl.dir/GameWindow.cpp.o: /home/snake0x8/CLionProjects/OpenGL/GameWindow.cpp
CMakeFiles/OpenGl.dir/GameWindow.cpp.o: CMakeFiles/OpenGl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OpenGl.dir/GameWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGl.dir/GameWindow.cpp.o -MF CMakeFiles/OpenGl.dir/GameWindow.cpp.o.d -o CMakeFiles/OpenGl.dir/GameWindow.cpp.o -c /home/snake0x8/CLionProjects/OpenGL/GameWindow.cpp

CMakeFiles/OpenGl.dir/GameWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGl.dir/GameWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/snake0x8/CLionProjects/OpenGL/GameWindow.cpp > CMakeFiles/OpenGl.dir/GameWindow.cpp.i

CMakeFiles/OpenGl.dir/GameWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGl.dir/GameWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/snake0x8/CLionProjects/OpenGL/GameWindow.cpp -o CMakeFiles/OpenGl.dir/GameWindow.cpp.s

CMakeFiles/OpenGl.dir/Game.cpp.o: CMakeFiles/OpenGl.dir/flags.make
CMakeFiles/OpenGl.dir/Game.cpp.o: /home/snake0x8/CLionProjects/OpenGL/Game.cpp
CMakeFiles/OpenGl.dir/Game.cpp.o: CMakeFiles/OpenGl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OpenGl.dir/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGl.dir/Game.cpp.o -MF CMakeFiles/OpenGl.dir/Game.cpp.o.d -o CMakeFiles/OpenGl.dir/Game.cpp.o -c /home/snake0x8/CLionProjects/OpenGL/Game.cpp

CMakeFiles/OpenGl.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGl.dir/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/snake0x8/CLionProjects/OpenGL/Game.cpp > CMakeFiles/OpenGl.dir/Game.cpp.i

CMakeFiles/OpenGl.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGl.dir/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/snake0x8/CLionProjects/OpenGL/Game.cpp -o CMakeFiles/OpenGl.dir/Game.cpp.s

# Object files for target OpenGl
OpenGl_OBJECTS = \
"CMakeFiles/OpenGl.dir/main.cpp.o" \
"CMakeFiles/OpenGl.dir/Shaders.cpp.o" \
"CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.o" \
"CMakeFiles/OpenGl.dir/GameWindow.cpp.o" \
"CMakeFiles/OpenGl.dir/Game.cpp.o"

# External object files for target OpenGl
OpenGl_EXTERNAL_OBJECTS =

OpenGl: CMakeFiles/OpenGl.dir/main.cpp.o
OpenGl: CMakeFiles/OpenGl.dir/Shaders.cpp.o
OpenGl: CMakeFiles/OpenGl.dir/HighResolutionTimer.cpp.o
OpenGl: CMakeFiles/OpenGl.dir/GameWindow.cpp.o
OpenGl: CMakeFiles/OpenGl.dir/Game.cpp.o
OpenGl: CMakeFiles/OpenGl.dir/build.make
OpenGl: /usr/lib/x86_64-linux-gnu/libOpenGL.so
OpenGl: /usr/lib/x86_64-linux-gnu/libGLX.so
OpenGl: /usr/lib/x86_64-linux-gnu/libGLU.so
OpenGl: /usr/lib/x86_64-linux-gnu/libglut.so
OpenGl: /usr/lib/x86_64-linux-gnu/libGLEW.so
OpenGl: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
OpenGl: glad/libGLAD.a
OpenGl: glad/libGLAD.a
OpenGl: CMakeFiles/OpenGl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable OpenGl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGl.dir/build: OpenGl
.PHONY : CMakeFiles/OpenGl.dir/build

CMakeFiles/OpenGl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGl.dir/clean

CMakeFiles/OpenGl.dir/depend:
	cd /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/snake0x8/CLionProjects/OpenGL /home/snake0x8/CLionProjects/OpenGL /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug /home/snake0x8/CLionProjects/OpenGL/cmake-build-debug/CMakeFiles/OpenGl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGl.dir/depend

