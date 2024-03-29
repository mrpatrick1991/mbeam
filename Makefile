# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/patrick/phd/svn/GEANT4/msis_xray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patrick/phd/svn/GEANT4/msis_xray

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip

.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local

.PHONY : install/local/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/patrick/phd/svn/GEANT4/msis_xray/CMakeFiles /home/patrick/phd/svn/GEANT4/msis_xray/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/patrick/phd/svn/GEANT4/msis_xray/CMakeFiles 0
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
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named msis_xray

# Build rule for target.
msis_xray: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 msis_xray
.PHONY : msis_xray

# fast build rule for target.
msis_xray/fast:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/build
.PHONY : msis_xray/fast

msis_xray.o: msis_xray.cc.o

.PHONY : msis_xray.o

# target to build an object file
msis_xray.cc.o:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/msis_xray.cc.o
.PHONY : msis_xray.cc.o

msis_xray.i: msis_xray.cc.i

.PHONY : msis_xray.i

# target to preprocess a source file
msis_xray.cc.i:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/msis_xray.cc.i
.PHONY : msis_xray.cc.i

msis_xray.s: msis_xray.cc.s

.PHONY : msis_xray.s

# target to generate assembly for a file
msis_xray.cc.s:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/msis_xray.cc.s
.PHONY : msis_xray.cc.s

src/ActionInitialization.o: src/ActionInitialization.cc.o

.PHONY : src/ActionInitialization.o

# target to build an object file
src/ActionInitialization.cc.o:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/ActionInitialization.cc.o
.PHONY : src/ActionInitialization.cc.o

src/ActionInitialization.i: src/ActionInitialization.cc.i

.PHONY : src/ActionInitialization.i

# target to preprocess a source file
src/ActionInitialization.cc.i:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/ActionInitialization.cc.i
.PHONY : src/ActionInitialization.cc.i

src/ActionInitialization.s: src/ActionInitialization.cc.s

.PHONY : src/ActionInitialization.s

# target to generate assembly for a file
src/ActionInitialization.cc.s:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/ActionInitialization.cc.s
.PHONY : src/ActionInitialization.cc.s

src/DetectorConstruction.o: src/DetectorConstruction.cc.o

.PHONY : src/DetectorConstruction.o

# target to build an object file
src/DetectorConstruction.cc.o:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/DetectorConstruction.cc.o
.PHONY : src/DetectorConstruction.cc.o

src/DetectorConstruction.i: src/DetectorConstruction.cc.i

.PHONY : src/DetectorConstruction.i

# target to preprocess a source file
src/DetectorConstruction.cc.i:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/DetectorConstruction.cc.i
.PHONY : src/DetectorConstruction.cc.i

src/DetectorConstruction.s: src/DetectorConstruction.cc.s

.PHONY : src/DetectorConstruction.s

# target to generate assembly for a file
src/DetectorConstruction.cc.s:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/DetectorConstruction.cc.s
.PHONY : src/DetectorConstruction.cc.s

src/EventAction.o: src/EventAction.cc.o

.PHONY : src/EventAction.o

# target to build an object file
src/EventAction.cc.o:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/EventAction.cc.o
.PHONY : src/EventAction.cc.o

src/EventAction.i: src/EventAction.cc.i

.PHONY : src/EventAction.i

# target to preprocess a source file
src/EventAction.cc.i:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/EventAction.cc.i
.PHONY : src/EventAction.cc.i

src/EventAction.s: src/EventAction.cc.s

.PHONY : src/EventAction.s

# target to generate assembly for a file
src/EventAction.cc.s:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/EventAction.cc.s
.PHONY : src/EventAction.cc.s

src/PhysicsList.o: src/PhysicsList.cc.o

.PHONY : src/PhysicsList.o

# target to build an object file
src/PhysicsList.cc.o:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/PhysicsList.cc.o
.PHONY : src/PhysicsList.cc.o

src/PhysicsList.i: src/PhysicsList.cc.i

.PHONY : src/PhysicsList.i

# target to preprocess a source file
src/PhysicsList.cc.i:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/PhysicsList.cc.i
.PHONY : src/PhysicsList.cc.i

src/PhysicsList.s: src/PhysicsList.cc.s

.PHONY : src/PhysicsList.s

# target to generate assembly for a file
src/PhysicsList.cc.s:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/PhysicsList.cc.s
.PHONY : src/PhysicsList.cc.s

src/PrimaryGeneratorAction.o: src/PrimaryGeneratorAction.cc.o

.PHONY : src/PrimaryGeneratorAction.o

# target to build an object file
src/PrimaryGeneratorAction.cc.o:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/PrimaryGeneratorAction.cc.o
.PHONY : src/PrimaryGeneratorAction.cc.o

src/PrimaryGeneratorAction.i: src/PrimaryGeneratorAction.cc.i

.PHONY : src/PrimaryGeneratorAction.i

# target to preprocess a source file
src/PrimaryGeneratorAction.cc.i:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/PrimaryGeneratorAction.cc.i
.PHONY : src/PrimaryGeneratorAction.cc.i

src/PrimaryGeneratorAction.s: src/PrimaryGeneratorAction.cc.s

.PHONY : src/PrimaryGeneratorAction.s

# target to generate assembly for a file
src/PrimaryGeneratorAction.cc.s:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/PrimaryGeneratorAction.cc.s
.PHONY : src/PrimaryGeneratorAction.cc.s

src/RunAction.o: src/RunAction.cc.o

.PHONY : src/RunAction.o

# target to build an object file
src/RunAction.cc.o:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/RunAction.cc.o
.PHONY : src/RunAction.cc.o

src/RunAction.i: src/RunAction.cc.i

.PHONY : src/RunAction.i

# target to preprocess a source file
src/RunAction.cc.i:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/RunAction.cc.i
.PHONY : src/RunAction.cc.i

src/RunAction.s: src/RunAction.cc.s

.PHONY : src/RunAction.s

# target to generate assembly for a file
src/RunAction.cc.s:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/RunAction.cc.s
.PHONY : src/RunAction.cc.s

src/TrackerHit.o: src/TrackerHit.cc.o

.PHONY : src/TrackerHit.o

# target to build an object file
src/TrackerHit.cc.o:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/TrackerHit.cc.o
.PHONY : src/TrackerHit.cc.o

src/TrackerHit.i: src/TrackerHit.cc.i

.PHONY : src/TrackerHit.i

# target to preprocess a source file
src/TrackerHit.cc.i:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/TrackerHit.cc.i
.PHONY : src/TrackerHit.cc.i

src/TrackerHit.s: src/TrackerHit.cc.s

.PHONY : src/TrackerHit.s

# target to generate assembly for a file
src/TrackerHit.cc.s:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/TrackerHit.cc.s
.PHONY : src/TrackerHit.cc.s

src/TrackerSD.o: src/TrackerSD.cc.o

.PHONY : src/TrackerSD.o

# target to build an object file
src/TrackerSD.cc.o:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/TrackerSD.cc.o
.PHONY : src/TrackerSD.cc.o

src/TrackerSD.i: src/TrackerSD.cc.i

.PHONY : src/TrackerSD.i

# target to preprocess a source file
src/TrackerSD.cc.i:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/TrackerSD.cc.i
.PHONY : src/TrackerSD.cc.i

src/TrackerSD.s: src/TrackerSD.cc.s

.PHONY : src/TrackerSD.s

# target to generate assembly for a file
src/TrackerSD.cc.s:
	$(MAKE) -f CMakeFiles/msis_xray.dir/build.make CMakeFiles/msis_xray.dir/src/TrackerSD.cc.s
.PHONY : src/TrackerSD.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... msis_xray"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... msis_xray.o"
	@echo "... msis_xray.i"
	@echo "... msis_xray.s"
	@echo "... src/ActionInitialization.o"
	@echo "... src/ActionInitialization.i"
	@echo "... src/ActionInitialization.s"
	@echo "... src/DetectorConstruction.o"
	@echo "... src/DetectorConstruction.i"
	@echo "... src/DetectorConstruction.s"
	@echo "... src/EventAction.o"
	@echo "... src/EventAction.i"
	@echo "... src/EventAction.s"
	@echo "... src/PhysicsList.o"
	@echo "... src/PhysicsList.i"
	@echo "... src/PhysicsList.s"
	@echo "... src/PrimaryGeneratorAction.o"
	@echo "... src/PrimaryGeneratorAction.i"
	@echo "... src/PrimaryGeneratorAction.s"
	@echo "... src/RunAction.o"
	@echo "... src/RunAction.i"
	@echo "... src/RunAction.s"
	@echo "... src/TrackerHit.o"
	@echo "... src/TrackerHit.i"
	@echo "... src/TrackerHit.s"
	@echo "... src/TrackerSD.o"
	@echo "... src/TrackerSD.i"
	@echo "... src/TrackerSD.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

