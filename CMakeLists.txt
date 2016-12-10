cmake_minimum_required(VERSION 2.8.7)

project(MyTools)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV  REQUIRED )

#link_directories = (  )
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 指定静态库的输出名称
#set_target_properties(MyTools PROPERTIES OUTPUT_NAME "person")

export(PACKAGE MyTools)


#set(CMAKE_INSTALL_PREFIX

message("sdf" ${CMAKE_INSTALL_PREFIX})

aux_source_directory(src SRC)
add_executable(tst1 ${SRC})

ADD_LIBRARY(MyTools STATIC ${SRC})

file(GLOB incfile "src/*.h")

#遍历并进行string操作  
FOREACH(F ${incfile})
	#MESSAGE(${F})
	STRING( REGEX REPLACE "^.*/(.*h)$" "\\1" dirName ${F})
	LIST(APPEND dirNameList ${CMAKE_INSTALL_PREFIX}/include/${dirName})
     
ENDFOREACH(F)
MESSAGE( ${dirNameList} )


include_directories(${OPENCV_INCLUDE_DIRS})
message("current---"  ${OPENCV_LIBS} )
target_link_libraries(tst1 ${OpenCV_LIBS})

message(${OpenCV_DIR})
set(OpenCV_DIR "${OpenCV_DIR}")
set(CONF_INCLUDE_DIRS  "${dirNameList}")
set(CONF_LIBS "${CMAKE_INSTALL_PREFIX}/lib/libMyTools.a")
#configure_file(MyToolsConfig.cmake.in  "${PROJECT_BINARY_DIR}/MyToolsConfig.cmake" @ONLY)
configure_file(MyToolsConfig.cmake.in   "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MyToolsConfig.cmake" @ONLY)



install(TARGETS tst1 RUNTIME DESTINATION bin)
INSTALL(TARGETS MyTools  ARCHIVE DESTINATION lib)
INSTALL(FILES ${incfile} DESTINATION include/MyTools)
install(FILES   "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MyToolsConfig.cmake"  DESTINATION share/MyTools)
  





#SET(CMAKE_MODULE_PATH "/home/yuyuyu00/desk/CartographerNew/install/share/cartographer/") 
#find_package(cartographer REQUIRED HINTS "/home/yuyuyu00/desk/CartographerNew/install/share/cartographer")

#include_directories(${CARTOGRAPHER_INCLUDE_DIRS})
#target_link_libraries(test1 ${CARTOGRAPHER_LIBRARIES})
#message("current---"  ${CARTOGRAPHER_LIBRARIES} )
#target_link_libraries(test1 ${GFLAGS_LIBRARIES})


