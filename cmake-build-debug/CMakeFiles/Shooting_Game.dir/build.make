# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Added Program Files\CLion\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Added Program Files\CLion\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Study\programming\C_Plus_Plus\Shooting_Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Shooting_Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Shooting_Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shooting_Game.dir/flags.make

CMakeFiles/Shooting_Game.dir/main.cpp.obj: CMakeFiles/Shooting_Game.dir/flags.make
CMakeFiles/Shooting_Game.dir/main.cpp.obj: CMakeFiles/Shooting_Game.dir/includes_CXX.rsp
CMakeFiles/Shooting_Game.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Shooting_Game.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Shooting_Game.dir\main.cpp.obj -c D:\Study\programming\C_Plus_Plus\Shooting_Game\main.cpp

CMakeFiles/Shooting_Game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shooting_Game.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\programming\C_Plus_Plus\Shooting_Game\main.cpp > CMakeFiles\Shooting_Game.dir\main.cpp.i

CMakeFiles/Shooting_Game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shooting_Game.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Study\programming\C_Plus_Plus\Shooting_Game\main.cpp -o CMakeFiles\Shooting_Game.dir\main.cpp.s

CMakeFiles/Shooting_Game.dir/character.cpp.obj: CMakeFiles/Shooting_Game.dir/flags.make
CMakeFiles/Shooting_Game.dir/character.cpp.obj: CMakeFiles/Shooting_Game.dir/includes_CXX.rsp
CMakeFiles/Shooting_Game.dir/character.cpp.obj: ../character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Shooting_Game.dir/character.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Shooting_Game.dir\character.cpp.obj -c D:\Study\programming\C_Plus_Plus\Shooting_Game\character.cpp

CMakeFiles/Shooting_Game.dir/character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shooting_Game.dir/character.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\programming\C_Plus_Plus\Shooting_Game\character.cpp > CMakeFiles\Shooting_Game.dir\character.cpp.i

CMakeFiles/Shooting_Game.dir/character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shooting_Game.dir/character.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Study\programming\C_Plus_Plus\Shooting_Game\character.cpp -o CMakeFiles\Shooting_Game.dir\character.cpp.s

CMakeFiles/Shooting_Game.dir/player.cpp.obj: CMakeFiles/Shooting_Game.dir/flags.make
CMakeFiles/Shooting_Game.dir/player.cpp.obj: CMakeFiles/Shooting_Game.dir/includes_CXX.rsp
CMakeFiles/Shooting_Game.dir/player.cpp.obj: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Shooting_Game.dir/player.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Shooting_Game.dir\player.cpp.obj -c D:\Study\programming\C_Plus_Plus\Shooting_Game\player.cpp

CMakeFiles/Shooting_Game.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shooting_Game.dir/player.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\programming\C_Plus_Plus\Shooting_Game\player.cpp > CMakeFiles\Shooting_Game.dir\player.cpp.i

CMakeFiles/Shooting_Game.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shooting_Game.dir/player.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Study\programming\C_Plus_Plus\Shooting_Game\player.cpp -o CMakeFiles\Shooting_Game.dir\player.cpp.s

CMakeFiles/Shooting_Game.dir/bullet.cpp.obj: CMakeFiles/Shooting_Game.dir/flags.make
CMakeFiles/Shooting_Game.dir/bullet.cpp.obj: CMakeFiles/Shooting_Game.dir/includes_CXX.rsp
CMakeFiles/Shooting_Game.dir/bullet.cpp.obj: ../bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Shooting_Game.dir/bullet.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Shooting_Game.dir\bullet.cpp.obj -c D:\Study\programming\C_Plus_Plus\Shooting_Game\bullet.cpp

CMakeFiles/Shooting_Game.dir/bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shooting_Game.dir/bullet.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\programming\C_Plus_Plus\Shooting_Game\bullet.cpp > CMakeFiles\Shooting_Game.dir\bullet.cpp.i

CMakeFiles/Shooting_Game.dir/bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shooting_Game.dir/bullet.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Study\programming\C_Plus_Plus\Shooting_Game\bullet.cpp -o CMakeFiles\Shooting_Game.dir\bullet.cpp.s

CMakeFiles/Shooting_Game.dir/game.cpp.obj: CMakeFiles/Shooting_Game.dir/flags.make
CMakeFiles/Shooting_Game.dir/game.cpp.obj: CMakeFiles/Shooting_Game.dir/includes_CXX.rsp
CMakeFiles/Shooting_Game.dir/game.cpp.obj: ../game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Shooting_Game.dir/game.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Shooting_Game.dir\game.cpp.obj -c D:\Study\programming\C_Plus_Plus\Shooting_Game\game.cpp

CMakeFiles/Shooting_Game.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shooting_Game.dir/game.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\programming\C_Plus_Plus\Shooting_Game\game.cpp > CMakeFiles\Shooting_Game.dir\game.cpp.i

CMakeFiles/Shooting_Game.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shooting_Game.dir/game.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Study\programming\C_Plus_Plus\Shooting_Game\game.cpp -o CMakeFiles\Shooting_Game.dir\game.cpp.s

CMakeFiles/Shooting_Game.dir/enemy.cpp.obj: CMakeFiles/Shooting_Game.dir/flags.make
CMakeFiles/Shooting_Game.dir/enemy.cpp.obj: CMakeFiles/Shooting_Game.dir/includes_CXX.rsp
CMakeFiles/Shooting_Game.dir/enemy.cpp.obj: ../enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Shooting_Game.dir/enemy.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Shooting_Game.dir\enemy.cpp.obj -c D:\Study\programming\C_Plus_Plus\Shooting_Game\enemy.cpp

CMakeFiles/Shooting_Game.dir/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shooting_Game.dir/enemy.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\programming\C_Plus_Plus\Shooting_Game\enemy.cpp > CMakeFiles\Shooting_Game.dir\enemy.cpp.i

CMakeFiles/Shooting_Game.dir/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shooting_Game.dir/enemy.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Study\programming\C_Plus_Plus\Shooting_Game\enemy.cpp -o CMakeFiles\Shooting_Game.dir\enemy.cpp.s

CMakeFiles/Shooting_Game.dir/boss.cpp.obj: CMakeFiles/Shooting_Game.dir/flags.make
CMakeFiles/Shooting_Game.dir/boss.cpp.obj: CMakeFiles/Shooting_Game.dir/includes_CXX.rsp
CMakeFiles/Shooting_Game.dir/boss.cpp.obj: ../boss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Shooting_Game.dir/boss.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Shooting_Game.dir\boss.cpp.obj -c D:\Study\programming\C_Plus_Plus\Shooting_Game\boss.cpp

CMakeFiles/Shooting_Game.dir/boss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shooting_Game.dir/boss.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\programming\C_Plus_Plus\Shooting_Game\boss.cpp > CMakeFiles\Shooting_Game.dir\boss.cpp.i

CMakeFiles/Shooting_Game.dir/boss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shooting_Game.dir/boss.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Study\programming\C_Plus_Plus\Shooting_Game\boss.cpp -o CMakeFiles\Shooting_Game.dir\boss.cpp.s

# Object files for target Shooting_Game
Shooting_Game_OBJECTS = \
"CMakeFiles/Shooting_Game.dir/main.cpp.obj" \
"CMakeFiles/Shooting_Game.dir/character.cpp.obj" \
"CMakeFiles/Shooting_Game.dir/player.cpp.obj" \
"CMakeFiles/Shooting_Game.dir/bullet.cpp.obj" \
"CMakeFiles/Shooting_Game.dir/game.cpp.obj" \
"CMakeFiles/Shooting_Game.dir/enemy.cpp.obj" \
"CMakeFiles/Shooting_Game.dir/boss.cpp.obj"

# External object files for target Shooting_Game
Shooting_Game_EXTERNAL_OBJECTS =

Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/main.cpp.obj
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/character.cpp.obj
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/player.cpp.obj
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/bullet.cpp.obj
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/game.cpp.obj
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/enemy.cpp.obj
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/boss.cpp.obj
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/build.make
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/linklibs.rsp
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/objects1.rsp
Shooting_Game.exe: CMakeFiles/Shooting_Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Shooting_Game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Shooting_Game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shooting_Game.dir/build: Shooting_Game.exe

.PHONY : CMakeFiles/Shooting_Game.dir/build

CMakeFiles/Shooting_Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Shooting_Game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Shooting_Game.dir/clean

CMakeFiles/Shooting_Game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Study\programming\C_Plus_Plus\Shooting_Game D:\Study\programming\C_Plus_Plus\Shooting_Game D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug D:\Study\programming\C_Plus_Plus\Shooting_Game\cmake-build-debug\CMakeFiles\Shooting_Game.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Shooting_Game.dir/depend

