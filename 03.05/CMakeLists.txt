cmake_minimum_required(VERSION 3.20)

project(gcd_and_lcm_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(
    run
    src/entity.cpp
)

target_include_directories(
    run
    PRIVATE
    src
)

add_executable(
    runtest
    tests/test.cpp
   
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