cmake_minimum_required(VERSION 3.20)
project(CMAKE_TEST)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) linux下动态库和静态库放在一起
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) #静态库目录

#动态库
aux_source_directory(${PROJECT_SOURCE_DIR}/Src SRC_LISTS)
add_library(common
SHARED
${SRC_LISTS})

target_include_directories(common
PUBLIC
${PROJECT_SOURCE_DIR}/Inc)

#可执行文件
add_executable(CMAKE_TEST planning_main.cpp) #生成可执行文件,这里文件名可以自己修改

target_include_directories(CMAKE_TEST
PUBLIC
${PROJECT_SOURCE_DIR}/Inc)

#链接动态库
target_link_libraries(CMAKE_TEST
PRIVATE
common)