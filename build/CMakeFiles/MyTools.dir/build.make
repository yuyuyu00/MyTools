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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build

# Include any dependencies generated for this target.
include CMakeFiles/MyTools.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyTools.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyTools.dir/flags.make

CMakeFiles/MyTools.dir/src/Point3dData.cpp.o: CMakeFiles/MyTools.dir/flags.make
CMakeFiles/MyTools.dir/src/Point3dData.cpp.o: ../src/Point3dData.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyTools.dir/src/Point3dData.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyTools.dir/src/Point3dData.cpp.o -c /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/Point3dData.cpp

CMakeFiles/MyTools.dir/src/Point3dData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyTools.dir/src/Point3dData.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/Point3dData.cpp > CMakeFiles/MyTools.dir/src/Point3dData.cpp.i

CMakeFiles/MyTools.dir/src/Point3dData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyTools.dir/src/Point3dData.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/Point3dData.cpp -o CMakeFiles/MyTools.dir/src/Point3dData.cpp.s

CMakeFiles/MyTools.dir/src/Point3dData.cpp.o.requires:
.PHONY : CMakeFiles/MyTools.dir/src/Point3dData.cpp.o.requires

CMakeFiles/MyTools.dir/src/Point3dData.cpp.o.provides: CMakeFiles/MyTools.dir/src/Point3dData.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyTools.dir/build.make CMakeFiles/MyTools.dir/src/Point3dData.cpp.o.provides.build
.PHONY : CMakeFiles/MyTools.dir/src/Point3dData.cpp.o.provides

CMakeFiles/MyTools.dir/src/Point3dData.cpp.o.provides.build: CMakeFiles/MyTools.dir/src/Point3dData.cpp.o

CMakeFiles/MyTools.dir/src/test_orgdata.cc.o: CMakeFiles/MyTools.dir/flags.make
CMakeFiles/MyTools.dir/src/test_orgdata.cc.o: ../src/test_orgdata.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyTools.dir/src/test_orgdata.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyTools.dir/src/test_orgdata.cc.o -c /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/test_orgdata.cc

CMakeFiles/MyTools.dir/src/test_orgdata.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyTools.dir/src/test_orgdata.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/test_orgdata.cc > CMakeFiles/MyTools.dir/src/test_orgdata.cc.i

CMakeFiles/MyTools.dir/src/test_orgdata.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyTools.dir/src/test_orgdata.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/test_orgdata.cc -o CMakeFiles/MyTools.dir/src/test_orgdata.cc.s

CMakeFiles/MyTools.dir/src/test_orgdata.cc.o.requires:
.PHONY : CMakeFiles/MyTools.dir/src/test_orgdata.cc.o.requires

CMakeFiles/MyTools.dir/src/test_orgdata.cc.o.provides: CMakeFiles/MyTools.dir/src/test_orgdata.cc.o.requires
	$(MAKE) -f CMakeFiles/MyTools.dir/build.make CMakeFiles/MyTools.dir/src/test_orgdata.cc.o.provides.build
.PHONY : CMakeFiles/MyTools.dir/src/test_orgdata.cc.o.provides

CMakeFiles/MyTools.dir/src/test_orgdata.cc.o.provides.build: CMakeFiles/MyTools.dir/src/test_orgdata.cc.o

CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o: CMakeFiles/MyTools.dir/flags.make
CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o: ../src/DrawPoint2D.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o -c /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/DrawPoint2D.cpp

CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/DrawPoint2D.cpp > CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.i

CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/DrawPoint2D.cpp -o CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.s

CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o.requires:
.PHONY : CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o.requires

CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o.provides: CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyTools.dir/build.make CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o.provides.build
.PHONY : CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o.provides

CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o.provides.build: CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o

CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o: CMakeFiles/MyTools.dir/flags.make
CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o: ../src/MapPoint2D.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o -c /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/MapPoint2D.cpp

CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/MapPoint2D.cpp > CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.i

CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/MapPoint2D.cpp -o CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.s

CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o.requires:
.PHONY : CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o.requires

CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o.provides: CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyTools.dir/build.make CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o.provides.build
.PHONY : CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o.provides

CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o.provides.build: CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o

CMakeFiles/MyTools.dir/src/Point2dData.cpp.o: CMakeFiles/MyTools.dir/flags.make
CMakeFiles/MyTools.dir/src/Point2dData.cpp.o: ../src/Point2dData.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyTools.dir/src/Point2dData.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyTools.dir/src/Point2dData.cpp.o -c /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/Point2dData.cpp

CMakeFiles/MyTools.dir/src/Point2dData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyTools.dir/src/Point2dData.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/Point2dData.cpp > CMakeFiles/MyTools.dir/src/Point2dData.cpp.i

CMakeFiles/MyTools.dir/src/Point2dData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyTools.dir/src/Point2dData.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/Point2dData.cpp -o CMakeFiles/MyTools.dir/src/Point2dData.cpp.s

CMakeFiles/MyTools.dir/src/Point2dData.cpp.o.requires:
.PHONY : CMakeFiles/MyTools.dir/src/Point2dData.cpp.o.requires

CMakeFiles/MyTools.dir/src/Point2dData.cpp.o.provides: CMakeFiles/MyTools.dir/src/Point2dData.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyTools.dir/build.make CMakeFiles/MyTools.dir/src/Point2dData.cpp.o.provides.build
.PHONY : CMakeFiles/MyTools.dir/src/Point2dData.cpp.o.provides

CMakeFiles/MyTools.dir/src/Point2dData.cpp.o.provides.build: CMakeFiles/MyTools.dir/src/Point2dData.cpp.o

CMakeFiles/MyTools.dir/src/CommonFun.cpp.o: CMakeFiles/MyTools.dir/flags.make
CMakeFiles/MyTools.dir/src/CommonFun.cpp.o: ../src/CommonFun.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyTools.dir/src/CommonFun.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyTools.dir/src/CommonFun.cpp.o -c /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/CommonFun.cpp

CMakeFiles/MyTools.dir/src/CommonFun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyTools.dir/src/CommonFun.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/CommonFun.cpp > CMakeFiles/MyTools.dir/src/CommonFun.cpp.i

CMakeFiles/MyTools.dir/src/CommonFun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyTools.dir/src/CommonFun.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/CommonFun.cpp -o CMakeFiles/MyTools.dir/src/CommonFun.cpp.s

CMakeFiles/MyTools.dir/src/CommonFun.cpp.o.requires:
.PHONY : CMakeFiles/MyTools.dir/src/CommonFun.cpp.o.requires

CMakeFiles/MyTools.dir/src/CommonFun.cpp.o.provides: CMakeFiles/MyTools.dir/src/CommonFun.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyTools.dir/build.make CMakeFiles/MyTools.dir/src/CommonFun.cpp.o.provides.build
.PHONY : CMakeFiles/MyTools.dir/src/CommonFun.cpp.o.provides

CMakeFiles/MyTools.dir/src/CommonFun.cpp.o.provides.build: CMakeFiles/MyTools.dir/src/CommonFun.cpp.o

# Object files for target MyTools
MyTools_OBJECTS = \
"CMakeFiles/MyTools.dir/src/Point3dData.cpp.o" \
"CMakeFiles/MyTools.dir/src/test_orgdata.cc.o" \
"CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o" \
"CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o" \
"CMakeFiles/MyTools.dir/src/Point2dData.cpp.o" \
"CMakeFiles/MyTools.dir/src/CommonFun.cpp.o"

# External object files for target MyTools
MyTools_EXTERNAL_OBJECTS =

libMyTools.a: CMakeFiles/MyTools.dir/src/Point3dData.cpp.o
libMyTools.a: CMakeFiles/MyTools.dir/src/test_orgdata.cc.o
libMyTools.a: CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o
libMyTools.a: CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o
libMyTools.a: CMakeFiles/MyTools.dir/src/Point2dData.cpp.o
libMyTools.a: CMakeFiles/MyTools.dir/src/CommonFun.cpp.o
libMyTools.a: CMakeFiles/MyTools.dir/build.make
libMyTools.a: CMakeFiles/MyTools.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libMyTools.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MyTools.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyTools.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyTools.dir/build: libMyTools.a
.PHONY : CMakeFiles/MyTools.dir/build

CMakeFiles/MyTools.dir/requires: CMakeFiles/MyTools.dir/src/Point3dData.cpp.o.requires
CMakeFiles/MyTools.dir/requires: CMakeFiles/MyTools.dir/src/test_orgdata.cc.o.requires
CMakeFiles/MyTools.dir/requires: CMakeFiles/MyTools.dir/src/DrawPoint2D.cpp.o.requires
CMakeFiles/MyTools.dir/requires: CMakeFiles/MyTools.dir/src/MapPoint2D.cpp.o.requires
CMakeFiles/MyTools.dir/requires: CMakeFiles/MyTools.dir/src/Point2dData.cpp.o.requires
CMakeFiles/MyTools.dir/requires: CMakeFiles/MyTools.dir/src/CommonFun.cpp.o.requires
.PHONY : CMakeFiles/MyTools.dir/requires

CMakeFiles/MyTools.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyTools.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyTools.dir/clean

CMakeFiles/MyTools.dir/depend:
	cd /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build /home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/build/CMakeFiles/MyTools.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyTools.dir/depend

