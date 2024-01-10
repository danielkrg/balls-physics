# # lib/CMakeLists.txt

# # Add the source files in the lib directory
# add_library(ball ball.cpp)
# add_library(collision collision_test.cpp)

# target_include_directories(collision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_include_directories(ball PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# set(SFML_LIBS sfml-graphics sfml-window sfml-system)

# # Include the directory with header files
# target_link_libraries(ball PRIVATE SFML_LIBS)
# target_link_libraries(collision PRIVATE SFML_LIBS)
# # Optionally, you can set up other properties or dependencies for the library

# Add the source files in the lib directory
add_library(ball ball.cpp)

# Include the directory with header files
target_include_directories(ball PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link SFML libraries to the library target
target_link_libraries(ball PRIVATE sfml-graphics sfml-window sfml-system)

# Repeat the same process for LibTarget2
add_library(collision collision.cpp)
target_include_directories(collision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(collision PRIVATE sfml-graphics sfml-window sfml-system)

