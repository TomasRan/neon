# disable in source compile, prevent conflicts with source file directories
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "in-source builds are not allowed.
    You should create a separate directory for build files.")
endif()

if(CMAKE_GENERATOR MATCHES Xcode)
    cmake_minimum_required(VERSION 3.12)
else()
    cmake_minimum_required(VERSION 3.10)
endif()

project(neon_test C CXX)

add_definitions(-std=c++11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)

add_subdirectory(third_party/gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE test_sources test/*.cpp)

add_executable(neon_test ${test_sources})

target_link_libraries(neon_test gtest)