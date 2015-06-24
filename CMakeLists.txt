#===================================================================================================
#                 Copyright 2012 - 2015   NumScale SAS
#
#                   Distributed under the Boost Software License, Version 1.0.
#                        See accompanying file LICENSE.txt or copy at
#                            http://www.boost.org/LICENSE_1_0.txt
#===================================================================================================
cmake_minimum_required(VERSION 3.0)

#===================================================================================================
# Setup target for MSVC
#===================================================================================================
if(NOT CMAKE_GENERATOR MATCHES "Make|Ninja")
  set(CMAKE_CONFIGURATION_TYPES Release Debug SIMDTest SIMDTestDebug SIMDBench CACHE STRING "" FORCE)
endif()

##===================================================================================================
## Setup project
##===================================================================================================
project(Boost.SIMD CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

##===================================================================================================
## Prevent in-source build
##===================================================================================================
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
  message( FATAL_ERROR "Building in-source, not recommended! Build in a separate directory." )
endif()

##===================================================================================================
## Search for packages.
##===================================================================================================
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
                      ${Boost_INCLUDE_DIRS}
                      ${PROJECT_SOURCE_DIR}/deps/include
                    )

##===================================================================================================
## Setup Documentation
##===================================================================================================
add_subdirectory(doc)

##===================================================================================================
## Setup Unit & Coverage Test
##===================================================================================================
add_custom_target(tests)
add_custom_target(unit)

include(coverage)
enable_testing()
enable_coverage(boost.simd)
add_dependencies(tests unit)

#add_subdirectory(test)
