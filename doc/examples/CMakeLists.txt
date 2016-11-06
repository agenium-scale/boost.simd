#![runtime-cmake]
cmake_minimum_required(VERSION 2.8)

set(CWD ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
set(CMAKE_BUILD_TYPE Release)

include_directories($ENV{BOOST_ROOT})
include_directories($ENV{SIMD_ROOT})

add_library(test_sse SHARED compute.cpp)
add_library(test_sse2 SHARED compute.cpp)
add_library(test_sse3 SHARED compute.cpp)
add_library(test_sse4.1 SHARED compute.cpp)
add_library(test_sse4.2 SHARED compute.cpp)
add_library(test_avx SHARED compute.cpp)
add_library(test_avx2 SHARED compute.cpp)

set_target_properties(test_sse2 PROPERTIES COMPILE_FLAGS "-msse2")
set_target_properties(test_sse3 PROPERTIES COMPILE_FLAGS "-msse3")
set_target_properties(test_sse4.1 PROPERTIES COMPILE_FLAGS "-msse4.1")
set_target_properties(test_sse4.2 PROPERTIES COMPILE_FLAGS "-msse4.2")
set_target_properties(test_avx PROPERTIES COMPILE_FLAGS "-mavx")
set_target_properties(test_avx2 PROPERTIES COMPILE_FLAGS "-mavx2")

add_executable(runtime_extension runtime_extension.cpp)

target_link_libraries(runtime_extension test_sse2 test_sse3 test_sse4.1 test_sse4.2 test_avx test_avx2)
#![runtime-cmake]
