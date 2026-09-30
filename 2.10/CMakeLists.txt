cmake_minimum_required(VERSION 3.20)

project(quick_sort_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(
    run
    src/main.cpp
    src/sort.cpp
)

target_include_directories(
    run
    PRIVATE
    src
)

add_executable(
    runtest
    tests/test.cpp
    src/sort.cpp
)

target_include_directories(
    runtest
    PRIVATE
    src
)

target_link_libraries(
    runtest
    PRIVATE
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(runtest)