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
CMAKE_SOURCE_DIR = /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/build/human_body

# Include any dependencies generated for this target.
include CMakeFiles/human_body_segment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/human_body_segment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/human_body_segment.dir/flags.make

CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o: CMakeFiles/human_body_segment.dir/flags.make
CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o: /home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/build/human_body/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o -c /home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp

CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp > CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.i

CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp -o CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.s

CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o.requires:

.PHONY : CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o.requires

CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o.provides: CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o.requires
	$(MAKE) -f CMakeFiles/human_body_segment.dir/build.make CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o.provides.build
.PHONY : CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o.provides

CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o.provides.build: CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o


CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o: CMakeFiles/human_body_segment.dir/flags.make
CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o: ../../humanbody_segment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/build/human_body/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o -c /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/humanbody_segment.cpp

CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/humanbody_segment.cpp > CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.i

CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/humanbody_segment.cpp -o CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.s

CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o.requires:

.PHONY : CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o.requires

CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o.provides: CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o.requires
	$(MAKE) -f CMakeFiles/human_body_segment.dir/build.make CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o.provides.build
.PHONY : CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o.provides

CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o.provides.build: CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o


# Object files for target human_body_segment
human_body_segment_OBJECTS = \
"CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o" \
"CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o"

# External object files for target human_body_segment
human_body_segment_EXTERNAL_OBJECTS =

human_body_segment: CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o
human_body_segment: CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o
human_body_segment: CMakeFiles/human_body_segment.dir/build.make
human_body_segment: CMakeFiles/human_body_segment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/build/human_body/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable human_body_segment"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/human_body_segment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/human_body_segment.dir/build: human_body_segment

.PHONY : CMakeFiles/human_body_segment.dir/build

CMakeFiles/human_body_segment.dir/requires: CMakeFiles/human_body_segment.dir/home/chengwei/git/AI-Cloud/face++/common/src/json_common.cpp.o.requires
CMakeFiles/human_body_segment.dir/requires: CMakeFiles/human_body_segment.dir/humanbody_segment.cpp.o.requires

.PHONY : CMakeFiles/human_body_segment.dir/requires

CMakeFiles/human_body_segment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/human_body_segment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/human_body_segment.dir/clean

CMakeFiles/human_body_segment.dir/depend:
	cd /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/build/human_body && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/build/human_body /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/build/human_body /home/chengwei/git/AI-Cloud/face++/04_HumanBody_Segment/build/human_body/CMakeFiles/human_body_segment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/human_body_segment.dir/depend

