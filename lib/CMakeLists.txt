# lib/CMakeLists.txt

# Add the source files in the lib directory
add_library(ball ball.cpp)

target_include_directories(ball PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include the directory with header files
target_link_libraries(ball PRIVATE sfml-graphics sfml-window sfml-system)
# Optionally, you can set up other properties or dependencies for the library
