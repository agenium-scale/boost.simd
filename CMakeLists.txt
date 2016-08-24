## -------------------------------------------------------------------------------------------------
##                              Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.7)

## Setup project
## -------------------------------------------------------------------------------------------------
project(Boost.SIMD)
set(PROJECT_DOC_DIR ${PROJECT_SOURCE_DIR}/doc)

## Requirements for ns.cmake:
## -------------------------------------------------------------------------------------------------
set(NS_CMAKE_GIT_TAG master)
include(cmake/ns.cmake.install.cmake)
if (NOT NS_CMAKE_INSTALLED)
  return()
endif()
include(cmake/ns/ns.cmake)
## -------------------------------------------------------------------------------------------------

## Potential warnings fixup
## -------------------------------------------------------------------------------------------------
NS_ignore(${DEV})
NS_ignore(${IS_TRAVIS_CI})
NS_ignore(${USE_SELF_BOOST})

## Search for packages
## -------------------------------------------------------------------------------------------------
if (DEFINED IS_TRAVIS_CI)
  # We do not want to find boost here, as we're gonna use the one on NumScale/boost-header-only
  set(GIT_EXECUTABLE git)
  set(USE_SELF_BOOST TRUE)
  set(DEV TRUE)
else()
  NS_find_package(Git QUIET)
  if (NOT DEFINED USE_SELF_BOOST)
    NS_find_package(Boost 1.60 REQUIRED)
  endif()
endif()

##
NS_prevent_in_source_build()

## External projects
## -------------------------------------------------------------------------------------------------
set(STF_STANDALONE_DESTINATION      ${PROJECT_SOURCE_DIR}/test)
set(BRIGAND_STANDALONE_DESTINATION  ${PROJECT_SOURCE_DIR}/include/boost/simd/detail)
set(NS_BENCH_STANDALONE_DESTINATION ${PROJECT_SOURCE_DIR}/bench)

set(NS_CMAKE_PROJECT_OPTIONS
  CMAKE_ARGS "-DBOOST_ROOT=${BOOST_HEADER_ONLY_DESTINATION}/include"
)
if (DEFINED USE_SELF_BOOST)
  set(BOOST_HEADER_ONLY_GIT_TAG develop)
  NS_project_include(boost-header-only)
  set(Boost_INCLUDE_DIRS ${BOOST_HEADER_ONLY_DESTINATION}/include)
endif()

# Use the same BOOST_ROOT for every projects
set(NS_CMAKE_PROJECT_OPTIONS
  CMAKE_ARGS "-DBOOST_ROOT=${Boost_INCLUDE_DIRS}"
)

if (DEFINED DEV)
  set(NS_BENCH_GIT_TAG develop)
  set(BRIGAND_GIT_TAG 1.2.0)
  NS_project_include(ns.bench.standalone)
  NS_project_include(brigand.standalone)
  NS_project_include(stf.standalone)
endif()

## Compute version string and mode + Documentation
## -------------------------------------------------------------------------------------------------
if (DEFINED DEV AND NOT DEFINED IS_TRAVIS_CI)
  NS_include(parse_revision)
  NS_include(doc/doxygen)
endif()

## Install target
## -------------------------------------------------------------------------------------------------
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION .)
if (DEFINED USE_SELF_BOOST)
  install(DIRECTORY ${NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION}/include DESTINATION .)
endif()

## Add include directories
## -------------------------------------------------------------------------------------------------
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/test
  ${PROJECT_SOURCE_DIR}/bench
  ${PROJECT_SOURCE_DIR}/exhaustive
  ${Boost_INCLUDE_DIRS}
)

## Extension point for CMake
## -------------------------------------------------------------------------------------------------
include(./cmake/extend.cmake)

## Setup Unit/Bench & Coverage Test
## -------------------------------------------------------------------------------------------------
if (DEFINED DEV)
  include(./setup.cmake) # Import compiler specific setup

  include(CTest)
  add_custom_target(tests)
  add_custom_target(unit)
  add_dependencies(tests unit)
  add_subdirectory(test)

  add_custom_target(bench)
  add_subdirectory(bench)

  add_custom_target(exhaustive)
  add_subdirectory(exhaustive)

  if (NOT DEFINED IS_TRAVIS_CI)
    NS_include(coverage)
    enable_coverage(boost.simd)
  endif()
endif()

