# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\18123\CLionProjects\CS241

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\18123\CLionProjects\CS241\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment6_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment6_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment6_main.dir/flags.make

CMakeFiles/Assignment6_main.dir/Assignment/Assignment6/Assignment6_main.cpp.obj: CMakeFiles/Assignment6_main.dir/flags.make
CMakeFiles/Assignment6_main.dir/Assignment/Assignment6/Assignment6_main.cpp.obj: ../Assignment/Assignment6/Assignment6_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\18123\CLionProjects\CS241\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment6_main.dir/Assignment/Assignment6/Assignment6_main.cpp.obj"
	C:\Users\18123\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment6_main.dir\Assignment\Assignment6\Assignment6_main.cpp.obj -c C:\Users\18123\CLionProjects\CS241\Assignment\Assignment6\Assignment6_main.cpp

CMakeFiles/Assignment6_main.dir/Assignment/Assignment6/Assignment6_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment6_main.dir/Assignment/Assignment6/Assignment6_main.cpp.i"
	C:\Users\18123\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\18123\CLionProjects\CS241\Assignment\Assignment6\Assignment6_main.cpp > CMakeFiles\Assignment6_main.dir\Assignment\Assignment6\Assignment6_main.cpp.i

CMakeFiles/Assignment6_main.dir/Assignment/Assignment6/Assignment6_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment6_main.dir/Assignment/Assignment6/Assignment6_main.cpp.s"
	C:\Users\18123\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\18123\CLionProjects\CS241\Assignment\Assignment6\Assignment6_main.cpp -o CMakeFiles\Assignment6_main.dir\Assignment\Assignment6\Assignment6_main.cpp.s

# Object files for target Assignment6_main
Assignment6_main_OBJECTS = \
"CMakeFiles/Assignment6_main.dir/Assignment/Assignment6/Assignment6_main.cpp.obj"

# External object files for target Assignment6_main
Assignment6_main_EXTERNAL_OBJECTS =

Assignment6_main.exe: CMakeFiles/Assignment6_main.dir/Assignment/Assignment6/Assignment6_main.cpp.obj
Assignment6_main.exe: CMakeFiles/Assignment6_main.dir/build.make
Assignment6_main.exe: CMakeFiles/Assignment6_main.dir/linklibs.rsp
Assignment6_main.exe: CMakeFiles/Assignment6_main.dir/objects1.rsp
Assignment6_main.exe: CMakeFiles/Assignment6_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\18123\CLionProjects\CS241\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Assignment6_main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment6_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment6_main.dir/build: Assignment6_main.exe

.PHONY : CMakeFiles/Assignment6_main.dir/build

CMakeFiles/Assignment6_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment6_main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment6_main.dir/clean

CMakeFiles/Assignment6_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\18123\CLionProjects\CS241 C:\Users\18123\CLionProjects\CS241 C:\Users\18123\CLionProjects\CS241\cmake-build-debug C:\Users\18123\CLionProjects\CS241\cmake-build-debug C:\Users\18123\CLionProjects\CS241\cmake-build-debug\CMakeFiles\Assignment6_main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment6_main.dir/depend
