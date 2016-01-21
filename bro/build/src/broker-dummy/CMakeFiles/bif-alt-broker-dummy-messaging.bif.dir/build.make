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

# Utility rule file for bif-alt-broker-dummy-messaging.bif.

# Include the progress variables for this target.
include src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/progress.make

src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif: src/broker-dummy/messaging.bif.h
src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif: src/broker-dummy/messaging.bif.cc

src/broker-dummy/messaging.bif.h: ../src/broker-dummy/messaging.bif
src/broker-dummy/messaging.bif.h: src/bifcl
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rhost/Downloads/bro-2.4.1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "[BIFCL] Processing messaging.bif"
	cd /home/rhost/Downloads/bro-2.4.1/build/src/broker-dummy && ../bifcl -s /home/rhost/Downloads/bro-2.4.1/src/broker-dummy/messaging.bif || ( rm -f messaging.bif.h messaging.bif.cc messaging.bif.init.cc && exit 1 )
	cd /home/rhost/Downloads/bro-2.4.1/build/src/broker-dummy && /usr/bin/cmake -E copy messaging.bif.bro /home/rhost/Downloads/bro-2.4.1/build/scripts/base/bif/messaging.bif.bro
	cd /home/rhost/Downloads/bro-2.4.1/build/src/broker-dummy && /usr/bin/cmake -E remove -f messaging.bif.bro

src/broker-dummy/messaging.bif.cc: src/broker-dummy/messaging.bif.h

src/broker-dummy/messaging.bif.init.cc: src/broker-dummy/messaging.bif.h

scripts/base/bif/messaging.bif.bro: src/broker-dummy/messaging.bif.h

bif-alt-broker-dummy-messaging.bif: src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif
bif-alt-broker-dummy-messaging.bif: src/broker-dummy/messaging.bif.h
bif-alt-broker-dummy-messaging.bif: src/broker-dummy/messaging.bif.cc
bif-alt-broker-dummy-messaging.bif: src/broker-dummy/messaging.bif.init.cc
bif-alt-broker-dummy-messaging.bif: scripts/base/bif/messaging.bif.bro
bif-alt-broker-dummy-messaging.bif: src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/build.make
.PHONY : bif-alt-broker-dummy-messaging.bif

# Rule to build all files generated by this target.
src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/build: bif-alt-broker-dummy-messaging.bif
.PHONY : src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/build

src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/clean:
	cd /home/rhost/Downloads/bro-2.4.1/build/src/broker-dummy && $(CMAKE_COMMAND) -P CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/cmake_clean.cmake
.PHONY : src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/clean

src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/depend:
	cd /home/rhost/Downloads/bro-2.4.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rhost/Downloads/bro-2.4.1 /home/rhost/Downloads/bro-2.4.1/src/broker-dummy /home/rhost/Downloads/bro-2.4.1/build /home/rhost/Downloads/bro-2.4.1/build/src/broker-dummy /home/rhost/Downloads/bro-2.4.1/build/src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-messaging.bif.dir/depend
