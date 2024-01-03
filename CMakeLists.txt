
cmake_minimum_required(VERSION 3.1)

project(YourProjectName VERSION 1.0)

find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 20)

add_executable(YourTargetName main.cpp)

target_link_libraries(YourTargetName PRIVATE sfml-graphics sfml-window sfml-system)