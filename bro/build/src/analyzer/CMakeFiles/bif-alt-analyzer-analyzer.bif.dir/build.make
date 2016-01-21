# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/rhost/Downloads/bro-2.4.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rhost/Downloads/bro-2.4.1/build

# Utility rule file for bif-alt-analyzer-analyzer.bif.

# Include the progress variables for this target.
include src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/progress.make

src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif: src/analyzer/analyzer.bif.h
src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif: src/analyzer/analyzer.bif.cc

src/analyzer/analyzer.bif.h: ../src/analyzer/analyzer.bif
src/analyzer/analyzer.bif.h: src/bifcl
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rhost/Downloads/bro-2.4.1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "[BIFCL] Processing analyzer.bif"
	cd /home/rhost/Downloads/bro-2.4.1/build/src/analyzer && ../bifcl -s /home/rhost/Downloads/bro-2.4.1/src/analyzer/analyzer.bif || ( rm -f analyzer.bif.h analyzer.bif.cc analyzer.bif.init.cc && exit 1 )
	cd /home/rhost/Downloads/bro-2.4.1/build/src/analyzer && /usr/bin/cmake -E copy analyzer.bif.bro /home/rhost/Downloads/bro-2.4.1/build/scripts/base/bif/analyzer.bif.bro
	cd /home/rhost/Downloads/bro-2.4.1/build/src/analyzer && /usr/bin/cmake -E remove -f analyzer.bif.bro

src/analyzer/analyzer.bif.cc: src/analyzer/analyzer.bif.h

src/analyzer/analyzer.bif.init.cc: src/analyzer/analyzer.bif.h

scripts/base/bif/analyzer.bif.bro: src/analyzer/analyzer.bif.h

bif-alt-analyzer-analyzer.bif: src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif
bif-alt-analyzer-analyzer.bif: src/analyzer/analyzer.bif.h
bif-alt-analyzer-analyzer.bif: src/analyzer/analyzer.bif.cc
bif-alt-analyzer-analyzer.bif: src/analyzer/analyzer.bif.init.cc
bif-alt-analyzer-analyzer.bif: scripts/base/bif/analyzer.bif.bro
bif-alt-analyzer-analyzer.bif: src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/build.make
.PHONY : bif-alt-analyzer-analyzer.bif

# Rule to build all files generated by this target.
src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/build: bif-alt-analyzer-analyzer.bif
.PHONY : src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/build

src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/clean:
	cd /home/rhost/Downloads/bro-2.4.1/build/src/analyzer && $(CMAKE_COMMAND) -P CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/cmake_clean.cmake
.PHONY : src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/clean

src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/depend:
	cd /home/rhost/Downloads/bro-2.4.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rhost/Downloads/bro-2.4.1 /home/rhost/Downloads/bro-2.4.1/src/analyzer /home/rhost/Downloads/bro-2.4.1/build /home/rhost/Downloads/bro-2.4.1/build/src/analyzer /home/rhost/Downloads/bro-2.4.1/build/src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/CMakeFiles/bif-alt-analyzer-analyzer.bif.dir/depend
