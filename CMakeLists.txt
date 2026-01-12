cmake_minimum_required(VERSION 3.20)
project(CMAKE_TEST)

# Tooling: export compile_commands.json for clangd, etc.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) linux下动态库和静态库放在一起
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) #静态库目录

#动态库
add_library(common SHARED
	${PROJECT_SOURCE_DIR}/Src/pnc_map.cpp
	${PROJECT_SOURCE_DIR}/Src/process.cpp
)

target_include_directories(common
PUBLIC
${PROJECT_SOURCE_DIR}/Inc)

#可执行文件
add_executable(CMAKE_TEST planning_main.cpp) #生成可执行文件,这里文件名可以自己修改

#链接动态库
target_link_libraries(CMAKE_TEST
PRIVATE
common)