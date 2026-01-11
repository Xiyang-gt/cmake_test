cmake_minimum_required(VERSION 3.20)
project(CMAKE_TEST)
set(CMAKE_CXX_STANDARD 11)

#可执行文件目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
aux_source_directory(. SRC_LIST) #把目录下面的所有源文件加入到SRC_LIST变量中
add_executable(CMAKE_TEST ${SRC_LIST}) #生成可执行文件
# tree可以列出目录结构