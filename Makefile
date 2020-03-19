# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/ichi/C++_dir/void-game-

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ichi/C++_dir/void-game-

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ichi/C++_dir/void-game-/CMakeFiles /home/ichi/C++_dir/void-game-/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ichi/C++_dir/void-game-/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named App

# Build rule for target.
App: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 App
.PHONY : App

# fast build rule for target.
App/fast:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/build
.PHONY : App/fast

src/Bullet.o: src/Bullet.cpp.o

.PHONY : src/Bullet.o

# target to build an object file
src/Bullet.cpp.o:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Bullet.cpp.o
.PHONY : src/Bullet.cpp.o

src/Bullet.i: src/Bullet.cpp.i

.PHONY : src/Bullet.i

# target to preprocess a source file
src/Bullet.cpp.i:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Bullet.cpp.i
.PHONY : src/Bullet.cpp.i

src/Bullet.s: src/Bullet.cpp.s

.PHONY : src/Bullet.s

# target to generate assembly for a file
src/Bullet.cpp.s:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Bullet.cpp.s
.PHONY : src/Bullet.cpp.s

src/Enemy.o: src/Enemy.cpp.o

.PHONY : src/Enemy.o

# target to build an object file
src/Enemy.cpp.o:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Enemy.cpp.o
.PHONY : src/Enemy.cpp.o

src/Enemy.i: src/Enemy.cpp.i

.PHONY : src/Enemy.i

# target to preprocess a source file
src/Enemy.cpp.i:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Enemy.cpp.i
.PHONY : src/Enemy.cpp.i

src/Enemy.s: src/Enemy.cpp.s

.PHONY : src/Enemy.s

# target to generate assembly for a file
src/Enemy.cpp.s:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Enemy.cpp.s
.PHONY : src/Enemy.cpp.s

src/Event.o: src/Event.cpp.o

.PHONY : src/Event.o

# target to build an object file
src/Event.cpp.o:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Event.cpp.o
.PHONY : src/Event.cpp.o

src/Event.i: src/Event.cpp.i

.PHONY : src/Event.i

# target to preprocess a source file
src/Event.cpp.i:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Event.cpp.i
.PHONY : src/Event.cpp.i

src/Event.s: src/Event.cpp.s

.PHONY : src/Event.s

# target to generate assembly for a file
src/Event.cpp.s:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Event.cpp.s
.PHONY : src/Event.cpp.s

src/Game.o: src/Game.cpp.o

.PHONY : src/Game.o

# target to build an object file
src/Game.cpp.o:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Game.cpp.o
.PHONY : src/Game.cpp.o

src/Game.i: src/Game.cpp.i

.PHONY : src/Game.i

# target to preprocess a source file
src/Game.cpp.i:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Game.cpp.i
.PHONY : src/Game.cpp.i

src/Game.s: src/Game.cpp.s

.PHONY : src/Game.s

# target to generate assembly for a file
src/Game.cpp.s:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Game.cpp.s
.PHONY : src/Game.cpp.s

src/Game_EventSetup.o: src/Game_EventSetup.cpp.o

.PHONY : src/Game_EventSetup.o

# target to build an object file
src/Game_EventSetup.cpp.o:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Game_EventSetup.cpp.o
.PHONY : src/Game_EventSetup.cpp.o

src/Game_EventSetup.i: src/Game_EventSetup.cpp.i

.PHONY : src/Game_EventSetup.i

# target to preprocess a source file
src/Game_EventSetup.cpp.i:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Game_EventSetup.cpp.i
.PHONY : src/Game_EventSetup.cpp.i

src/Game_EventSetup.s: src/Game_EventSetup.cpp.s

.PHONY : src/Game_EventSetup.s

# target to generate assembly for a file
src/Game_EventSetup.cpp.s:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Game_EventSetup.cpp.s
.PHONY : src/Game_EventSetup.cpp.s

src/Main.o: src/Main.cpp.o

.PHONY : src/Main.o

# target to build an object file
src/Main.cpp.o:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Main.cpp.o
.PHONY : src/Main.cpp.o

src/Main.i: src/Main.cpp.i

.PHONY : src/Main.i

# target to preprocess a source file
src/Main.cpp.i:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Main.cpp.i
.PHONY : src/Main.cpp.i

src/Main.s: src/Main.cpp.s

.PHONY : src/Main.s

# target to generate assembly for a file
src/Main.cpp.s:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Main.cpp.s
.PHONY : src/Main.cpp.s

src/MyShip.o: src/MyShip.cpp.o

.PHONY : src/MyShip.o

# target to build an object file
src/MyShip.cpp.o:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/MyShip.cpp.o
.PHONY : src/MyShip.cpp.o

src/MyShip.i: src/MyShip.cpp.i

.PHONY : src/MyShip.i

# target to preprocess a source file
src/MyShip.cpp.i:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/MyShip.cpp.i
.PHONY : src/MyShip.cpp.i

src/MyShip.s: src/MyShip.cpp.s

.PHONY : src/MyShip.s

# target to generate assembly for a file
src/MyShip.cpp.s:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/MyShip.cpp.s
.PHONY : src/MyShip.cpp.s

src/Object.o: src/Object.cpp.o

.PHONY : src/Object.o

# target to build an object file
src/Object.cpp.o:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Object.cpp.o
.PHONY : src/Object.cpp.o

src/Object.i: src/Object.cpp.i

.PHONY : src/Object.i

# target to preprocess a source file
src/Object.cpp.i:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Object.cpp.i
.PHONY : src/Object.cpp.i

src/Object.s: src/Object.cpp.s

.PHONY : src/Object.s

# target to generate assembly for a file
src/Object.cpp.s:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Object.cpp.s
.PHONY : src/Object.cpp.s

src/Title.o: src/Title.cpp.o

.PHONY : src/Title.o

# target to build an object file
src/Title.cpp.o:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Title.cpp.o
.PHONY : src/Title.cpp.o

src/Title.i: src/Title.cpp.i

.PHONY : src/Title.i

# target to preprocess a source file
src/Title.cpp.i:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Title.cpp.i
.PHONY : src/Title.cpp.i

src/Title.s: src/Title.cpp.s

.PHONY : src/Title.s

# target to generate assembly for a file
src/Title.cpp.s:
	$(MAKE) -f CMakeFiles/App.dir/build.make CMakeFiles/App.dir/src/Title.cpp.s
.PHONY : src/Title.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... App"
	@echo "... edit_cache"
	@echo "... src/Bullet.o"
	@echo "... src/Bullet.i"
	@echo "... src/Bullet.s"
	@echo "... src/Enemy.o"
	@echo "... src/Enemy.i"
	@echo "... src/Enemy.s"
	@echo "... src/Event.o"
	@echo "... src/Event.i"
	@echo "... src/Event.s"
	@echo "... src/Game.o"
	@echo "... src/Game.i"
	@echo "... src/Game.s"
	@echo "... src/Game_EventSetup.o"
	@echo "... src/Game_EventSetup.i"
	@echo "... src/Game_EventSetup.s"
	@echo "... src/Main.o"
	@echo "... src/Main.i"
	@echo "... src/Main.s"
	@echo "... src/MyShip.o"
	@echo "... src/MyShip.i"
	@echo "... src/MyShip.s"
	@echo "... src/Object.o"
	@echo "... src/Object.i"
	@echo "... src/Object.s"
	@echo "... src/Title.o"
	@echo "... src/Title.i"
	@echo "... src/Title.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

