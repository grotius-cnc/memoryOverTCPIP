# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/user/XCreator/vendor/memoryOverTCPIP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/XCreator/vendor/memoryOverTCPIP/build

# Include any dependencies generated for this target.
include server/CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include server/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include server/CMakeFiles/server.dir/flags.make

server/CMakeFiles/server.dir/main.cpp.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/main.cpp.o: ../server/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/XCreator/vendor/memoryOverTCPIP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object server/CMakeFiles/server.dir/main.cpp.o"
	cd /home/user/XCreator/vendor/memoryOverTCPIP/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/main.cpp.o -c /home/user/XCreator/vendor/memoryOverTCPIP/server/main.cpp

server/CMakeFiles/server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/main.cpp.i"
	cd /home/user/XCreator/vendor/memoryOverTCPIP/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/XCreator/vendor/memoryOverTCPIP/server/main.cpp > CMakeFiles/server.dir/main.cpp.i

server/CMakeFiles/server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/main.cpp.s"
	cd /home/user/XCreator/vendor/memoryOverTCPIP/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/XCreator/vendor/memoryOverTCPIP/server/main.cpp -o CMakeFiles/server.dir/main.cpp.s

server/CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.o: ../include/lodepng/lodepng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/XCreator/vendor/memoryOverTCPIP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object server/CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.o"
	cd /home/user/XCreator/vendor/memoryOverTCPIP/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.o -c /home/user/XCreator/vendor/memoryOverTCPIP/include/lodepng/lodepng.cpp

server/CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.i"
	cd /home/user/XCreator/vendor/memoryOverTCPIP/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/XCreator/vendor/memoryOverTCPIP/include/lodepng/lodepng.cpp > CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.i

server/CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.s"
	cd /home/user/XCreator/vendor/memoryOverTCPIP/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/XCreator/vendor/memoryOverTCPIP/include/lodepng/lodepng.cpp -o CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/main.cpp.o" \
"CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server/server: server/CMakeFiles/server.dir/main.cpp.o
server/server: server/CMakeFiles/server.dir/__/include/lodepng/lodepng.cpp.o
server/server: server/CMakeFiles/server.dir/build.make
server/server: server/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/XCreator/vendor/memoryOverTCPIP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable server"
	cd /home/user/XCreator/vendor/memoryOverTCPIP/build/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server/CMakeFiles/server.dir/build: server/server

.PHONY : server/CMakeFiles/server.dir/build

server/CMakeFiles/server.dir/clean:
	cd /home/user/XCreator/vendor/memoryOverTCPIP/build/server && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : server/CMakeFiles/server.dir/clean

server/CMakeFiles/server.dir/depend:
	cd /home/user/XCreator/vendor/memoryOverTCPIP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/XCreator/vendor/memoryOverTCPIP /home/user/XCreator/vendor/memoryOverTCPIP/server /home/user/XCreator/vendor/memoryOverTCPIP/build /home/user/XCreator/vendor/memoryOverTCPIP/build/server /home/user/XCreator/vendor/memoryOverTCPIP/build/server/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server/CMakeFiles/server.dir/depend

