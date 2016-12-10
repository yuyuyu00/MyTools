cmake_minimum_required(VERSION 2.8.7)

project(MyTools)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV  REQUIRED )
#link_directories = (  )


aux_source_directory(. SRC)
add_executable(tst1 ${SRC})
include_directories(${OPENCV_INCLUDE_DIRS})
message("current---"  ${OPENCV_LIBS} )
target_link_libraries(tst1 ${OpenCV_LIBS})


install(TARGETS tst1 RUNTIME DESTINATION bin)






#SET(CMAKE_MODULE_PATH "/home/yuyuyu00/desk/CartographerNew/install/share/cartographer/") 
#find_package(cartographer REQUIRED HINTS "/home/yuyuyu00/desk/CartographerNew/install/share/cartographer")

#include_directories(${CARTOGRAPHER_INCLUDE_DIRS})
#target_link_libraries(test1 ${CARTOGRAPHER_LIBRARIES})
#message("current---"  ${CARTOGRAPHER_LIBRARIES} )
#target_link_libraries(test1 ${GFLAGS_LIBRARIES})


