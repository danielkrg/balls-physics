set(CMAKE_CXX_STANDARD 20)

cmake_minimum_required(VERSION 3.5)

project(BallsPhysics VERSION 1.0)

find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)


# Add the executable and specify the source files
add_executable(balls main.cpp)

# Include the directory where your header file is located
target_link_libraries(balls PRIVATE sfml-graphics sfml-window sfml-system)

# Add the subdirectory containing the library
add_subdirectory(lib)

target_link_libraries(balls PRIVATE ball)