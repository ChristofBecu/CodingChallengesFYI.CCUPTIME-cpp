cmake_minimum_required(VERSION 3.18)

project(ccuptime
    VERSION 1.0
    LANGUAGES CXX
    DESCRIPTION "My C++ solution of Coding Challenge Uptime Monitoring Service"
    HOMEPAGE_URL "https://github.com/ChristofBecu/CodingChallengesFYI.CCUPTIME-cpp"
)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
endif()

# Source directories
set(SRC_DIR "src")
set(INCLUDE_DIR "include")
set(TEST_DIR "tests")

# Output directories
set(OUTPUT_DIR "output")

# Include directories
include_directories(${INCLUDE_DIR})

# Add the src directory
add_subdirectory(${SRC_DIR})

# Tests
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(${TEST_DIR})
endif()