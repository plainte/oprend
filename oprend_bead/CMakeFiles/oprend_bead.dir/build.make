# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead

# Include any dependencies generated for this target.
include CMakeFiles/oprend_bead.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/oprend_bead.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oprend_bead.dir/flags.make

CMakeFiles/oprend_bead.dir/main.c.o: CMakeFiles/oprend_bead.dir/flags.make
CMakeFiles/oprend_bead.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/oprend_bead.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/oprend_bead.dir/main.c.o   -c /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/main.c

CMakeFiles/oprend_bead.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/oprend_bead.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/main.c > CMakeFiles/oprend_bead.dir/main.c.i

CMakeFiles/oprend_bead.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/oprend_bead.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/main.c -o CMakeFiles/oprend_bead.dir/main.c.s

CMakeFiles/oprend_bead.dir/lib/Patient.c.o: CMakeFiles/oprend_bead.dir/flags.make
CMakeFiles/oprend_bead.dir/lib/Patient.c.o: lib/Patient.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/oprend_bead.dir/lib/Patient.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/oprend_bead.dir/lib/Patient.c.o   -c /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/lib/Patient.c

CMakeFiles/oprend_bead.dir/lib/Patient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/oprend_bead.dir/lib/Patient.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/lib/Patient.c > CMakeFiles/oprend_bead.dir/lib/Patient.c.i

CMakeFiles/oprend_bead.dir/lib/Patient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/oprend_bead.dir/lib/Patient.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/lib/Patient.c -o CMakeFiles/oprend_bead.dir/lib/Patient.c.s

CMakeFiles/oprend_bead.dir/io/FileHandler.c.o: CMakeFiles/oprend_bead.dir/flags.make
CMakeFiles/oprend_bead.dir/io/FileHandler.c.o: io/FileHandler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/oprend_bead.dir/io/FileHandler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/oprend_bead.dir/io/FileHandler.c.o   -c /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/io/FileHandler.c

CMakeFiles/oprend_bead.dir/io/FileHandler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/oprend_bead.dir/io/FileHandler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/io/FileHandler.c > CMakeFiles/oprend_bead.dir/io/FileHandler.c.i

CMakeFiles/oprend_bead.dir/io/FileHandler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/oprend_bead.dir/io/FileHandler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/io/FileHandler.c -o CMakeFiles/oprend_bead.dir/io/FileHandler.c.s

CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.o: CMakeFiles/oprend_bead.dir/flags.make
CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.o: util/CircularBuffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.o   -c /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/util/CircularBuffer.c

CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/util/CircularBuffer.c > CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.i

CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/util/CircularBuffer.c -o CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.s

CMakeFiles/oprend_bead.dir/App.c.o: CMakeFiles/oprend_bead.dir/flags.make
CMakeFiles/oprend_bead.dir/App.c.o: App.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/oprend_bead.dir/App.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/oprend_bead.dir/App.c.o   -c /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/App.c

CMakeFiles/oprend_bead.dir/App.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/oprend_bead.dir/App.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/App.c > CMakeFiles/oprend_bead.dir/App.c.i

CMakeFiles/oprend_bead.dir/App.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/oprend_bead.dir/App.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/App.c -o CMakeFiles/oprend_bead.dir/App.c.s

CMakeFiles/oprend_bead.dir/lib/Event.c.o: CMakeFiles/oprend_bead.dir/flags.make
CMakeFiles/oprend_bead.dir/lib/Event.c.o: lib/Event.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/oprend_bead.dir/lib/Event.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/oprend_bead.dir/lib/Event.c.o   -c /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/lib/Event.c

CMakeFiles/oprend_bead.dir/lib/Event.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/oprend_bead.dir/lib/Event.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/lib/Event.c > CMakeFiles/oprend_bead.dir/lib/Event.c.i

CMakeFiles/oprend_bead.dir/lib/Event.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/oprend_bead.dir/lib/Event.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/lib/Event.c -o CMakeFiles/oprend_bead.dir/lib/Event.c.s

CMakeFiles/oprend_bead.dir/types/Defines.c.o: CMakeFiles/oprend_bead.dir/flags.make
CMakeFiles/oprend_bead.dir/types/Defines.c.o: types/Defines.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/oprend_bead.dir/types/Defines.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/oprend_bead.dir/types/Defines.c.o   -c /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/types/Defines.c

CMakeFiles/oprend_bead.dir/types/Defines.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/oprend_bead.dir/types/Defines.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/types/Defines.c > CMakeFiles/oprend_bead.dir/types/Defines.c.i

CMakeFiles/oprend_bead.dir/types/Defines.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/oprend_bead.dir/types/Defines.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/types/Defines.c -o CMakeFiles/oprend_bead.dir/types/Defines.c.s

CMakeFiles/oprend_bead.dir/lib/Cache.c.o: CMakeFiles/oprend_bead.dir/flags.make
CMakeFiles/oprend_bead.dir/lib/Cache.c.o: lib/Cache.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/oprend_bead.dir/lib/Cache.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/oprend_bead.dir/lib/Cache.c.o   -c /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/lib/Cache.c

CMakeFiles/oprend_bead.dir/lib/Cache.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/oprend_bead.dir/lib/Cache.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/lib/Cache.c > CMakeFiles/oprend_bead.dir/lib/Cache.c.i

CMakeFiles/oprend_bead.dir/lib/Cache.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/oprend_bead.dir/lib/Cache.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/lib/Cache.c -o CMakeFiles/oprend_bead.dir/lib/Cache.c.s

# Object files for target oprend_bead
oprend_bead_OBJECTS = \
"CMakeFiles/oprend_bead.dir/main.c.o" \
"CMakeFiles/oprend_bead.dir/lib/Patient.c.o" \
"CMakeFiles/oprend_bead.dir/io/FileHandler.c.o" \
"CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.o" \
"CMakeFiles/oprend_bead.dir/App.c.o" \
"CMakeFiles/oprend_bead.dir/lib/Event.c.o" \
"CMakeFiles/oprend_bead.dir/types/Defines.c.o" \
"CMakeFiles/oprend_bead.dir/lib/Cache.c.o"

# External object files for target oprend_bead
oprend_bead_EXTERNAL_OBJECTS =

oprend_bead: CMakeFiles/oprend_bead.dir/main.c.o
oprend_bead: CMakeFiles/oprend_bead.dir/lib/Patient.c.o
oprend_bead: CMakeFiles/oprend_bead.dir/io/FileHandler.c.o
oprend_bead: CMakeFiles/oprend_bead.dir/util/CircularBuffer.c.o
oprend_bead: CMakeFiles/oprend_bead.dir/App.c.o
oprend_bead: CMakeFiles/oprend_bead.dir/lib/Event.c.o
oprend_bead: CMakeFiles/oprend_bead.dir/types/Defines.c.o
oprend_bead: CMakeFiles/oprend_bead.dir/lib/Cache.c.o
oprend_bead: CMakeFiles/oprend_bead.dir/build.make
oprend_bead: CMakeFiles/oprend_bead.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable oprend_bead"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/oprend_bead.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/oprend_bead.dir/build: oprend_bead

.PHONY : CMakeFiles/oprend_bead.dir/build

CMakeFiles/oprend_bead.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/oprend_bead.dir/cmake_clean.cmake
.PHONY : CMakeFiles/oprend_bead.dir/clean

CMakeFiles/oprend_bead.dir/depend:
	cd /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead /mnt/c/Users/molna/Desktop/programming/cpp/oprend_bead/CMakeFiles/oprend_bead.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/oprend_bead.dir/depend

