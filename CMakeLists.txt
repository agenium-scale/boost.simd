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
project(Boost.SIMD CXX)
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
NS_ignore(${IS_TRAVIS_CI})
NS_ignore(${USE_SELF_BOOST})

## Search for packages
## -------------------------------------------------------------------------------------------------
if (DEFINED IS_TRAVIS_CI)
  # We do not want to find boost here, as we're gonna use the one on NumScale/boost-header-only
  set(GIT_EXECUTABLE git)
  set(USE_SELF_BOOST TRUE)
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
set(STF_STANDALONE_DESTINATION     ${PROJECT_SOURCE_DIR}/test)
set(BRIGAND_STANDALONE_DESTINATION ${PROJECT_SOURCE_DIR}/include/boost/simd/detail)

NS_project_include(brigand.standalone)

if (DEFINED USE_SELF_BOOST)
  set(BOOST_HEADER_ONLY_GIT_TAG develop)
  NS_project_include(boost-header-only)

  # NOTE: (workaround)
  # We DO need to use `CMAKE_ARGS` here otherwise, travis is not able to find boost even when
  # exporting BOOST_ROOT using shell export...
  set(BOOST_DISPATCH_GIT_TAG    develop)
  set(BOOST_DISPATCH_OPTIONS
    CMAKE_ARGS "-DBOOST_ROOT=${BOOST_HEADER_ONLY_DESTINATION}/include"
  )

  set( STF_OPTIONS
       CMAKE_ARGS "-DBOOST_ROOT=${BOOST_HEADER_ONLY_DESTINATION}/include"
      )

  NS_project_include(boost.dispatch)
  add_dependencies(BOOST_DISPATCH BOOST_HEADER_ONLY)
  add_dependencies(BOOST_DISPATCH-install BOOST_HEADER_ONLY)
  add_dependencies(update.boost.dispatch update.boost-header-only)
  set(Boost_INCLUDE_DIRS
    ${BOOST_DISPATCH_DESTINATION}/include
    ${BOOST_HEADER_ONLY_DESTINATION}/include
  )
endif()

NS_project_include(stf.standalone)

## Compute version string and mode + Documentation
## -------------------------------------------------------------------------------------------------
if (NOT DEFINED IS_TRAVIS_CI)
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
  ${Boost_INCLUDE_DIRS}
)

## Setup Unit & Coverage Test
## -------------------------------------------------------------------------------------------------
include(CTest)
add_custom_target(tests)
add_custom_target(unit)
add_dependencies(tests unit)
add_subdirectory(test)

if (NOT DEFINED IS_TRAVIS_CI)
  NS_include(coverage)
  enable_coverage(boost.simd)
endif()
