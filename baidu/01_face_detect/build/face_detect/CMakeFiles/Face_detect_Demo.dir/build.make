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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/chengwei/git/AI-Cloud/baidu/01_face_detect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chengwei/git/AI-Cloud/baidu/01_face_detect/build/face_detect

# Include any dependencies generated for this target.
include CMakeFiles/Face_detect_Demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Face_detect_Demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Face_detect_Demo.dir/flags.make

CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o: CMakeFiles/Face_detect_Demo.dir/flags.make
CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o: /home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chengwei/git/AI-Cloud/baidu/01_face_detect/build/face_detect/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o -c /home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp

CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp > CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.i

CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp -o CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.s

CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o.requires:

.PHONY : CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o.requires

CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o.provides: CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o.requires
	$(MAKE) -f CMakeFiles/Face_detect_Demo.dir/build.make CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o.provides.build
.PHONY : CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o.provides

CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o.provides.build: CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o


CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o: CMakeFiles/Face_detect_Demo.dir/flags.make
CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o: ../../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chengwei/git/AI-Cloud/baidu/01_face_detect/build/face_detect/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o -c /home/chengwei/git/AI-Cloud/baidu/01_face_detect/src/main.cpp

CMakeFiles/Face_detect_Demo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Face_detect_Demo.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chengwei/git/AI-Cloud/baidu/01_face_detect/src/main.cpp > CMakeFiles/Face_detect_Demo.dir/src/main.cpp.i

CMakeFiles/Face_detect_Demo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Face_detect_Demo.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chengwei/git/AI-Cloud/baidu/01_face_detect/src/main.cpp -o CMakeFiles/Face_detect_Demo.dir/src/main.cpp.s

CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o.requires

CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o.provides: CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Face_detect_Demo.dir/build.make CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o.provides

CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o.provides.build: CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o


# Object files for target Face_detect_Demo
Face_detect_Demo_OBJECTS = \
"CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o" \
"CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o"

# External object files for target Face_detect_Demo
Face_detect_Demo_EXTERNAL_OBJECTS =

Face_detect_Demo: CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o
Face_detect_Demo: CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o
Face_detect_Demo: CMakeFiles/Face_detect_Demo.dir/build.make
Face_detect_Demo: CMakeFiles/Face_detect_Demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chengwei/git/AI-Cloud/baidu/01_face_detect/build/face_detect/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Face_detect_Demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Face_detect_Demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Face_detect_Demo.dir/build: Face_detect_Demo

.PHONY : CMakeFiles/Face_detect_Demo.dir/build

CMakeFiles/Face_detect_Demo.dir/requires: CMakeFiles/Face_detect_Demo.dir/home/chengwei/git/AI-Cloud/baidu/common/json_common.cpp.o.requires
CMakeFiles/Face_detect_Demo.dir/requires: CMakeFiles/Face_detect_Demo.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/Face_detect_Demo.dir/requires

CMakeFiles/Face_detect_Demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Face_detect_Demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Face_detect_Demo.dir/clean

CMakeFiles/Face_detect_Demo.dir/depend:
	cd /home/chengwei/git/AI-Cloud/baidu/01_face_detect/build/face_detect && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chengwei/git/AI-Cloud/baidu/01_face_detect /home/chengwei/git/AI-Cloud/baidu/01_face_detect /home/chengwei/git/AI-Cloud/baidu/01_face_detect/build/face_detect /home/chengwei/git/AI-Cloud/baidu/01_face_detect/build/face_detect /home/chengwei/git/AI-Cloud/baidu/01_face_detect/build/face_detect/CMakeFiles/Face_detect_Demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Face_detect_Demo.dir/depend
