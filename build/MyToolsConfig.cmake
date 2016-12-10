
# - Config file for the FooBar package
# It defines the following variables
#  MyTools_INCLUDE_DIRS - include directories for FooBar
#  MyTools_LIBS    - libraries to link against
#  MyTools_EXE   - the bar executable
 
# Compute paths
get_filename_component(MyTools_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(MyTools_INCLUDE_DIRS "/home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/Point2dData.h;/home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/CommonFun.h;/home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/Point3dData.h;/home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/DrawPoint2D.h;/home/yuyuyu00/desk/CartographerNew/testPrj/MyTools/src/MapPoint2D.h")
 
# Our library dependencies (contains definitions for IMPORTED targets)
if(NOT TARGET foo AND NOT MyTools_BINARY_DIR)
  include("${MyTools_CMAKE_DIR}/MyToolsTargets.cmake")
endif()
 
# These are IMPORTED targets created by FooBarTargets.cmake
set(MyTools_LIBRARIES MyTools)
#set(MyTools_EXECUTABLE bar)
