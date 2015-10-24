##===================================================================================================
##                 Copyright 2009 - 2015   LRI    UMR 8623 CNRS/Univ Paris Sud XI
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================
cmake_minimum_required(VERSION 2.8.7)

##===================================================================================================
## Setup project
##===================================================================================================
project(Boost.SIMD CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/test")

##===================================================================================================
## Prevent in-source build
##===================================================================================================
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
  message( FATAL_ERROR "Building in-source, not recommended! Build in a separate directory." )
endif()

##===================================================================================================
## Search for packages.
##===================================================================================================
set(Boost_ADDITIONAL_VERSIONS "1.59")
find_package(Boost   1.58)
find_package(Doxygen QUIET)

##===================================================================================================
## Install pre-commit git hook
##===================================================================================================
execute_process(COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/script/git/pre-commit
                ${PROJECT_SOURCE_DIR}/.git/hooks
               )

##===================================================================================================
## Compute version string and mode
##===================================================================================================
include(parse_revision)

##===================================================================================================
## Add include directories
##===================================================================================================
include_directories ( ${PROJECT_SOURCE_DIR}/include
                      ${PROJECT_SOURCE_DIR}/test
                      ${Boost_INCLUDE_DIRS}
                    )

##===================================================================================================
## Setup Documentation
##===================================================================================================
add_subdirectory(doc)

##===================================================================================================
## Setup Unit & Coverage Test
##===================================================================================================
include(CTest)
add_custom_target(tests)
add_custom_target(unit)

include(coverage)
enable_testing()
enable_coverage(boost.simd)
add_dependencies(tests unit)

add_subdirectory(test)
