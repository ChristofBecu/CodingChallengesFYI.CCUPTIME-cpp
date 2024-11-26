#!/bin/bash

set -e

BUILD_MODE="MinSizeRel" # Debug / Release / RelWithDebInfo / MinSizeRel / None
SOURCE_DIR="."
BUILD_DIR="build"
BUILD_TESTS_OPTION="-DBUILD_TESTS=OFF"

showUsage() {
    echo "Usage: ./build.sh [OPTION]"
    echo 
    echo "Options:"
    echo "  -b | --build  build the project"
    echo "  -t | --test   build & test the project"
    echo "  -c | --clean  clean up the build artifacts"
    echo "  -h | --help   show this help"
}

clean() {
    echo "Cleaning build artifacts..."
    rm -rf "$BUILD_DIR"
    echo "Clean complete."
}

build() {
    # Run CMake to configure and generate build files
    echo "Configuring the project..."
    cmake -S "$SOURCE_DIR" -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$BUILD_MODE" $BUILD_TESTS_OPTION

    # Build the project
    echo "Building the project..."
    cmake --build "$BUILD_DIR"
}

test() {
    # Enable building tests
    BUILD_TESTS_OPTION="-DBUILD_TESTS=ON"
    build
    echo "Running tests..."
    cd "$BUILD_DIR"
    ctest -VV
}

# Parse command line arguments
case "$1" in
    -h|--help)
        showUsage
        exit 0
        ;;
    -c|--clean)
        clean
        ;;
    -t|--test)
        test
        ;;
    -b|--build)
        build
        ;;
    *) 
        echo "Unknown option: $1"
        showUsage
        exit 1
        ;;
esac