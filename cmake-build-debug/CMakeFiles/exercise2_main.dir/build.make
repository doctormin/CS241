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
include CMakeFiles/exercise2_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exercise2_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise2_main.dir/flags.make

CMakeFiles/exercise2_main.dir/Assignment/Assignment2/exercise2/exercise2_main.cpp.obj: CMakeFiles/exercise2_main.dir/flags.make
CMakeFiles/exercise2_main.dir/Assignment/Assignment2/exercise2/exercise2_main.cpp.obj: ../Assignment/Assignment2/exercise2/exercise2_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\18123\CLionProjects\CS241\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exercise2_main.dir/Assignment/Assignment2/exercise2/exercise2_main.cpp.obj"
	C:\Users\18123\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\exercise2_main.dir\Assignment\Assignment2\exercise2\exercise2_main.cpp.obj -c C:\Users\18123\CLionProjects\CS241\Assignment\Assignment2\exercise2\exercise2_main.cpp

CMakeFiles/exercise2_main.dir/Assignment/Assignment2/exercise2/exercise2_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exercise2_main.dir/Assignment/Assignment2/exercise2/exercise2_main.cpp.i"
	C:\Users\18123\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\18123\CLionProjects\CS241\Assignment\Assignment2\exercise2\exercise2_main.cpp > CMakeFiles\exercise2_main.dir\Assignment\Assignment2\exercise2\exercise2_main.cpp.i

CMakeFiles/exercise2_main.dir/Assignment/Assignment2/exercise2/exercise2_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exercise2_main.dir/Assignment/Assignment2/exercise2/exercise2_main.cpp.s"
	C:\Users\18123\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\18123\CLionProjects\CS241\Assignment\Assignment2\exercise2\exercise2_main.cpp -o CMakeFiles\exercise2_main.dir\Assignment\Assignment2\exercise2\exercise2_main.cpp.s

# Object files for target exercise2_main
exercise2_main_OBJECTS = \
"CMakeFiles/exercise2_main.dir/Assignment/Assignment2/exercise2/exercise2_main.cpp.obj"

# External object files for target exercise2_main
exercise2_main_EXTERNAL_OBJECTS =

exercise2_main.exe: CMakeFiles/exercise2_main.dir/Assignment/Assignment2/exercise2/exercise2_main.cpp.obj
exercise2_main.exe: CMakeFiles/exercise2_main.dir/build.make
exercise2_main.exe: CMakeFiles/exercise2_main.dir/linklibs.rsp
exercise2_main.exe: CMakeFiles/exercise2_main.dir/objects1.rsp
exercise2_main.exe: CMakeFiles/exercise2_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\18123\CLionProjects\CS241\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exercise2_main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\exercise2_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise2_main.dir/build: exercise2_main.exe

.PHONY : CMakeFiles/exercise2_main.dir/build

CMakeFiles/exercise2_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\exercise2_main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/exercise2_main.dir/clean

CMakeFiles/exercise2_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\18123\CLionProjects\CS241 C:\Users\18123\CLionProjects\CS241 C:\Users\18123\CLionProjects\CS241\cmake-build-debug C:\Users\18123\CLionProjects\CS241\cmake-build-debug C:\Users\18123\CLionProjects\CS241\cmake-build-debug\CMakeFiles\exercise2_main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exercise2_main.dir/depend
