# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/student/Downloads/clion-2021.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/student/Downloads/clion-2021.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/CLionProjects/msgslot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/CLionProjects/msgslot/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/msgslot.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/msgslot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/msgslot.dir/flags.make

CMakeFiles/msgslot.dir/main.c.o: CMakeFiles/msgslot.dir/flags.make
CMakeFiles/msgslot.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/msgslot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/msgslot.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/msgslot.dir/main.c.o -c /home/student/CLionProjects/msgslot/main.c

CMakeFiles/msgslot.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msgslot.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CLionProjects/msgslot/main.c > CMakeFiles/msgslot.dir/main.c.i

CMakeFiles/msgslot.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msgslot.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CLionProjects/msgslot/main.c -o CMakeFiles/msgslot.dir/main.c.s

CMakeFiles/msgslot.dir/message_slot.c.o: CMakeFiles/msgslot.dir/flags.make
CMakeFiles/msgslot.dir/message_slot.c.o: ../message_slot.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/msgslot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/msgslot.dir/message_slot.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/msgslot.dir/message_slot.c.o -c /home/student/CLionProjects/msgslot/message_slot.c

CMakeFiles/msgslot.dir/message_slot.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msgslot.dir/message_slot.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CLionProjects/msgslot/message_slot.c > CMakeFiles/msgslot.dir/message_slot.c.i

CMakeFiles/msgslot.dir/message_slot.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msgslot.dir/message_slot.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CLionProjects/msgslot/message_slot.c -o CMakeFiles/msgslot.dir/message_slot.c.s

CMakeFiles/msgslot.dir/message_reader.c.o: CMakeFiles/msgslot.dir/flags.make
CMakeFiles/msgslot.dir/message_reader.c.o: ../message_reader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/msgslot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/msgslot.dir/message_reader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/msgslot.dir/message_reader.c.o -c /home/student/CLionProjects/msgslot/message_reader.c

CMakeFiles/msgslot.dir/message_reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msgslot.dir/message_reader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CLionProjects/msgslot/message_reader.c > CMakeFiles/msgslot.dir/message_reader.c.i

CMakeFiles/msgslot.dir/message_reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msgslot.dir/message_reader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CLionProjects/msgslot/message_reader.c -o CMakeFiles/msgslot.dir/message_reader.c.s

CMakeFiles/msgslot.dir/message_sender.c.o: CMakeFiles/msgslot.dir/flags.make
CMakeFiles/msgslot.dir/message_sender.c.o: ../message_sender.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/msgslot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/msgslot.dir/message_sender.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/msgslot.dir/message_sender.c.o -c /home/student/CLionProjects/msgslot/message_sender.c

CMakeFiles/msgslot.dir/message_sender.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msgslot.dir/message_sender.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CLionProjects/msgslot/message_sender.c > CMakeFiles/msgslot.dir/message_sender.c.i

CMakeFiles/msgslot.dir/message_sender.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msgslot.dir/message_sender.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CLionProjects/msgslot/message_sender.c -o CMakeFiles/msgslot.dir/message_sender.c.s

# Object files for target msgslot
msgslot_OBJECTS = \
"CMakeFiles/msgslot.dir/main.c.o" \
"CMakeFiles/msgslot.dir/message_slot.c.o" \
"CMakeFiles/msgslot.dir/message_reader.c.o" \
"CMakeFiles/msgslot.dir/message_sender.c.o"

# External object files for target msgslot
msgslot_EXTERNAL_OBJECTS =

msgslot: CMakeFiles/msgslot.dir/main.c.o
msgslot: CMakeFiles/msgslot.dir/message_slot.c.o
msgslot: CMakeFiles/msgslot.dir/message_reader.c.o
msgslot: CMakeFiles/msgslot.dir/message_sender.c.o
msgslot: CMakeFiles/msgslot.dir/build.make
msgslot: CMakeFiles/msgslot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/CLionProjects/msgslot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable msgslot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/msgslot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/msgslot.dir/build: msgslot
.PHONY : CMakeFiles/msgslot.dir/build

CMakeFiles/msgslot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/msgslot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/msgslot.dir/clean

CMakeFiles/msgslot.dir/depend:
	cd /home/student/CLionProjects/msgslot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/CLionProjects/msgslot /home/student/CLionProjects/msgslot /home/student/CLionProjects/msgslot/cmake-build-debug /home/student/CLionProjects/msgslot/cmake-build-debug /home/student/CLionProjects/msgslot/cmake-build-debug/CMakeFiles/msgslot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/msgslot.dir/depend

