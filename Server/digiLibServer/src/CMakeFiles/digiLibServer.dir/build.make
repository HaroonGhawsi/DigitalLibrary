# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/haroon01/DigitalLibrary/Server/digiLibServer/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haroon01/DigitalLibrary/Server/digiLibServer/src

# Include any dependencies generated for this target.
include CMakeFiles/digiLibServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/digiLibServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/digiLibServer.dir/flags.make

CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o: CMakeFiles/digiLibServer.dir/flags.make
CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o: digiLibServer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/haroon01/DigitalLibrary/Server/digiLibServer/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o -c /home/haroon01/DigitalLibrary/Server/digiLibServer/src/digiLibServer.cpp

CMakeFiles/digiLibServer.dir/digiLibServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/digiLibServer.dir/digiLibServer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/haroon01/DigitalLibrary/Server/digiLibServer/src/digiLibServer.cpp > CMakeFiles/digiLibServer.dir/digiLibServer.cpp.i

CMakeFiles/digiLibServer.dir/digiLibServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/digiLibServer.dir/digiLibServer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/haroon01/DigitalLibrary/Server/digiLibServer/src/digiLibServer.cpp -o CMakeFiles/digiLibServer.dir/digiLibServer.cpp.s

CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o.requires:
.PHONY : CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o.requires

CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o.provides: CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/digiLibServer.dir/build.make CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o.provides.build
.PHONY : CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o.provides

CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o.provides.build: CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o

# Object files for target digiLibServer
digiLibServer_OBJECTS = \
"CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o"

# External object files for target digiLibServer
digiLibServer_EXTERNAL_OBJECTS =

digiLibServer: CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o
digiLibServer: CMakeFiles/digiLibServer.dir/build.make
digiLibServer: CMakeFiles/digiLibServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable digiLibServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/digiLibServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/digiLibServer.dir/build: digiLibServer
.PHONY : CMakeFiles/digiLibServer.dir/build

CMakeFiles/digiLibServer.dir/requires: CMakeFiles/digiLibServer.dir/digiLibServer.cpp.o.requires
.PHONY : CMakeFiles/digiLibServer.dir/requires

CMakeFiles/digiLibServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/digiLibServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/digiLibServer.dir/clean

CMakeFiles/digiLibServer.dir/depend:
	cd /home/haroon01/DigitalLibrary/Server/digiLibServer/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haroon01/DigitalLibrary/Server/digiLibServer/src /home/haroon01/DigitalLibrary/Server/digiLibServer/src /home/haroon01/DigitalLibrary/Server/digiLibServer/src /home/haroon01/DigitalLibrary/Server/digiLibServer/src /home/haroon01/DigitalLibrary/Server/digiLibServer/src/CMakeFiles/digiLibServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/digiLibServer.dir/depend

