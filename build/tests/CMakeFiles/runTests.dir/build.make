# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/pixel/Escritorio/Poyecto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pixel/Escritorio/Poyecto/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/runTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/runTests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/runTests.dir/flags.make

tests/CMakeFiles/runTests.dir/test_mpointer.cpp.o: tests/CMakeFiles/runTests.dir/flags.make
tests/CMakeFiles/runTests.dir/test_mpointer.cpp.o: /home/pixel/Escritorio/Poyecto/tests/test_mpointer.cpp
tests/CMakeFiles/runTests.dir/test_mpointer.cpp.o: tests/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pixel/Escritorio/Poyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/runTests.dir/test_mpointer.cpp.o"
	cd /home/pixel/Escritorio/Poyecto/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/runTests.dir/test_mpointer.cpp.o -MF CMakeFiles/runTests.dir/test_mpointer.cpp.o.d -o CMakeFiles/runTests.dir/test_mpointer.cpp.o -c /home/pixel/Escritorio/Poyecto/tests/test_mpointer.cpp

tests/CMakeFiles/runTests.dir/test_mpointer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runTests.dir/test_mpointer.cpp.i"
	cd /home/pixel/Escritorio/Poyecto/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pixel/Escritorio/Poyecto/tests/test_mpointer.cpp > CMakeFiles/runTests.dir/test_mpointer.cpp.i

tests/CMakeFiles/runTests.dir/test_mpointer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/test_mpointer.cpp.s"
	cd /home/pixel/Escritorio/Poyecto/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pixel/Escritorio/Poyecto/tests/test_mpointer.cpp -o CMakeFiles/runTests.dir/test_mpointer.cpp.s

tests/CMakeFiles/runTests.dir/__/MPointerGC.cpp.o: tests/CMakeFiles/runTests.dir/flags.make
tests/CMakeFiles/runTests.dir/__/MPointerGC.cpp.o: /home/pixel/Escritorio/Poyecto/MPointerGC.cpp
tests/CMakeFiles/runTests.dir/__/MPointerGC.cpp.o: tests/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pixel/Escritorio/Poyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/runTests.dir/__/MPointerGC.cpp.o"
	cd /home/pixel/Escritorio/Poyecto/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/runTests.dir/__/MPointerGC.cpp.o -MF CMakeFiles/runTests.dir/__/MPointerGC.cpp.o.d -o CMakeFiles/runTests.dir/__/MPointerGC.cpp.o -c /home/pixel/Escritorio/Poyecto/MPointerGC.cpp

tests/CMakeFiles/runTests.dir/__/MPointerGC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runTests.dir/__/MPointerGC.cpp.i"
	cd /home/pixel/Escritorio/Poyecto/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pixel/Escritorio/Poyecto/MPointerGC.cpp > CMakeFiles/runTests.dir/__/MPointerGC.cpp.i

tests/CMakeFiles/runTests.dir/__/MPointerGC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/__/MPointerGC.cpp.s"
	cd /home/pixel/Escritorio/Poyecto/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pixel/Escritorio/Poyecto/MPointerGC.cpp -o CMakeFiles/runTests.dir/__/MPointerGC.cpp.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/test_mpointer.cpp.o" \
"CMakeFiles/runTests.dir/__/MPointerGC.cpp.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

tests/runTests: tests/CMakeFiles/runTests.dir/test_mpointer.cpp.o
tests/runTests: tests/CMakeFiles/runTests.dir/__/MPointerGC.cpp.o
tests/runTests: tests/CMakeFiles/runTests.dir/build.make
tests/runTests: /usr/lib/x86_64-linux-gnu/libgtest.a
tests/runTests: tests/CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/pixel/Escritorio/Poyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable runTests"
	cd /home/pixel/Escritorio/Poyecto/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/runTests.dir/build: tests/runTests
.PHONY : tests/CMakeFiles/runTests.dir/build

tests/CMakeFiles/runTests.dir/clean:
	cd /home/pixel/Escritorio/Poyecto/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/runTests.dir/clean

tests/CMakeFiles/runTests.dir/depend:
	cd /home/pixel/Escritorio/Poyecto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pixel/Escritorio/Poyecto /home/pixel/Escritorio/Poyecto/tests /home/pixel/Escritorio/Poyecto/build /home/pixel/Escritorio/Poyecto/build/tests /home/pixel/Escritorio/Poyecto/build/tests/CMakeFiles/runTests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/runTests.dir/depend

