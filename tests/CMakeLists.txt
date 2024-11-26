cmake_minimum_required(VERSION 3.10)

# Project name
project(CCUPTIME_TESTS)

# Set source and output directories
set(SRC_DIR "src")
set(TEST_DIR "tests")
set(OUTPUT_DIR "output/tests")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})

# Automatically add all source files as libraries
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

foreach(SRC_FILE ${SRC_FILES})
  get_filename_component(LIB_NAME ${SRC_FILE} NAME_WE)
  add_library(${LIB_NAME} SHARED ${SRC_FILE})
endforeach()

# Automatically add all test files
file(GLOB TEST_SOURCES "${TEST_DIR}/*.cpp")

foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_NAME} ${LIB_NAME} GTest::GTest GTest::Main)
endforeach()

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add global tests if needed
# add_executable(globalTests globalTests.cpp)
# target_link_libraries(globalTests ${LIB_NAME} GTest::GTest GTest::Main)