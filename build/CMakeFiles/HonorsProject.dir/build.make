# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vena/school/cpp110C/honors

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vena/school/cpp110C/honors/build

# Include any dependencies generated for this target.
include CMakeFiles/HonorsProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HonorsProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HonorsProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HonorsProject.dir/flags.make

CMakeFiles/HonorsProject.dir/src/main.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/HonorsProject.dir/src/main.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HonorsProject.dir/src/main.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/src/main.cpp.o -MF CMakeFiles/HonorsProject.dir/src/main.cpp.o.d -o CMakeFiles/HonorsProject.dir/src/main.cpp.o -c /home/vena/school/cpp110C/honors/src/main.cpp

CMakeFiles/HonorsProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/src/main.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/src/main.cpp > CMakeFiles/HonorsProject.dir/src/main.cpp.i

CMakeFiles/HonorsProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/src/main.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/src/main.cpp -o CMakeFiles/HonorsProject.dir/src/main.cpp.s

CMakeFiles/HonorsProject.dir/src/module.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/src/module.cpp.o: ../src/module.cpp
CMakeFiles/HonorsProject.dir/src/module.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HonorsProject.dir/src/module.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/src/module.cpp.o -MF CMakeFiles/HonorsProject.dir/src/module.cpp.o.d -o CMakeFiles/HonorsProject.dir/src/module.cpp.o -c /home/vena/school/cpp110C/honors/src/module.cpp

CMakeFiles/HonorsProject.dir/src/module.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/src/module.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/src/module.cpp > CMakeFiles/HonorsProject.dir/src/module.cpp.i

CMakeFiles/HonorsProject.dir/src/module.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/src/module.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/src/module.cpp -o CMakeFiles/HonorsProject.dir/src/module.cpp.s

CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.o: ../src/oscillator4.cpp
CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.o -MF CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.o.d -o CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.o -c /home/vena/school/cpp110C/honors/src/oscillator4.cpp

CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/src/oscillator4.cpp > CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.i

CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/src/oscillator4.cpp -o CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.s

CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.o: ../imgui/imgui.cpp
CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.o -MF CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.o.d -o CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.o -c /home/vena/school/cpp110C/honors/imgui/imgui.cpp

CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/imgui/imgui.cpp > CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.i

CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/imgui/imgui.cpp -o CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.s

CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.o: ../imgui/imgui_demo.cpp
CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.o -MF CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.o.d -o CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.o -c /home/vena/school/cpp110C/honors/imgui/imgui_demo.cpp

CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/imgui/imgui_demo.cpp > CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.i

CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/imgui/imgui_demo.cpp -o CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.s

CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.o: ../imgui/imgui_draw.cpp
CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.o -MF CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.o.d -o CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.o -c /home/vena/school/cpp110C/honors/imgui/imgui_draw.cpp

CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/imgui/imgui_draw.cpp > CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.i

CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/imgui/imgui_draw.cpp -o CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.s

CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.o: ../imgui/imgui_tables.cpp
CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.o -MF CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.o.d -o CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.o -c /home/vena/school/cpp110C/honors/imgui/imgui_tables.cpp

CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/imgui/imgui_tables.cpp > CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.i

CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/imgui/imgui_tables.cpp -o CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.s

CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.o: ../imgui/imgui_widgets.cpp
CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.o -MF CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.o -c /home/vena/school/cpp110C/honors/imgui/imgui_widgets.cpp

CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/imgui/imgui_widgets.cpp > CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.i

CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/imgui/imgui_widgets.cpp -o CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.s

CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.o: ../imgui/backends/imgui_impl_glfw.cpp
CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.o -MF CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.o.d -o CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.o -c /home/vena/school/cpp110C/honors/imgui/backends/imgui_impl_glfw.cpp

CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/imgui/backends/imgui_impl_glfw.cpp > CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.i

CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/imgui/backends/imgui_impl_glfw.cpp -o CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.s

CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.o: CMakeFiles/HonorsProject.dir/flags.make
CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.o: ../imgui/backends/imgui_impl_opengl3.cpp
CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.o: CMakeFiles/HonorsProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.o -MF CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.o.d -o CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.o -c /home/vena/school/cpp110C/honors/imgui/backends/imgui_impl_opengl3.cpp

CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vena/school/cpp110C/honors/imgui/backends/imgui_impl_opengl3.cpp > CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.i

CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vena/school/cpp110C/honors/imgui/backends/imgui_impl_opengl3.cpp -o CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.s

# Object files for target HonorsProject
HonorsProject_OBJECTS = \
"CMakeFiles/HonorsProject.dir/src/main.cpp.o" \
"CMakeFiles/HonorsProject.dir/src/module.cpp.o" \
"CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.o" \
"CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.o" \
"CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.o" \
"CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.o" \
"CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.o" \
"CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.o"

# External object files for target HonorsProject
HonorsProject_EXTERNAL_OBJECTS =

HonorsProject: CMakeFiles/HonorsProject.dir/src/main.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/src/module.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/src/oscillator4.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/imgui/imgui.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/imgui/imgui_demo.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/imgui/imgui_draw.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/imgui/imgui_tables.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/imgui/imgui_widgets.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_glfw.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/imgui/backends/imgui_impl_opengl3.cpp.o
HonorsProject: CMakeFiles/HonorsProject.dir/build.make
HonorsProject: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
HonorsProject: ../Gamma/build/lib/libGamma.a
HonorsProject: /usr/lib/x86_64-linux-gnu/libGLX.so
HonorsProject: /usr/lib/x86_64-linux-gnu/libOpenGL.so
HonorsProject: CMakeFiles/HonorsProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vena/school/cpp110C/honors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable HonorsProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HonorsProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HonorsProject.dir/build: HonorsProject
.PHONY : CMakeFiles/HonorsProject.dir/build

CMakeFiles/HonorsProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HonorsProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HonorsProject.dir/clean

CMakeFiles/HonorsProject.dir/depend:
	cd /home/vena/school/cpp110C/honors/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vena/school/cpp110C/honors /home/vena/school/cpp110C/honors /home/vena/school/cpp110C/honors/build /home/vena/school/cpp110C/honors/build /home/vena/school/cpp110C/honors/build/CMakeFiles/HonorsProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HonorsProject.dir/depend

