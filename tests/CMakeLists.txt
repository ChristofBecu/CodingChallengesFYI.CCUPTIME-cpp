# tests/CMakeLists.txt

# Find all .cpp files in the current directory (tests/)
file(GLOB_RECURSE TEST_SOURCES "*.cpp")

# Create a test executable from all test files
add_executable(tests ${TEST_SOURCES})

# Link the test executable with GTest and your project's main library
target_link_libraries(tests gtest gtest_main pthread ${PROJECT_NAME}_library)

# Add the test target to CTest
add_test(NAME all_tests COMMAND tests)
