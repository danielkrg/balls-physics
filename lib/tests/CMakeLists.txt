# # tests/CMakeLists.txt

# # Add an executable for each test file
# add_executable(collision_test collision_test.cpp)
# # add_executable(AnotherTest another_test.cpp)
# target_link_libraries(collision_test PRIVATE sfml-graphics sfml-window sfml-system)

# # Include directories for the test executables
# target_include_directories(collision_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/lib/include)
# # target_include_directories(AnotherTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/lib/include)

# # Link against the libraries
# target_link_libraries(collision_test PRIVATE collision)
# # target_link_libraries(AnotherTest PRIVATE LibTarget1)

# set_target_properties(collision_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")