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
set(PROJECT_VERSION 4.17.6.0) # TODO: Find a way to update this automatically
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
  NS_project_include(stf)
  NS_project_include(ns.bench)

  if (DEFINED USE_SELF_BOOST)
    add_dependencies(update.check update.boost-header-only)
  endif()
endif()

## Extension point for CMake
## -------------------------------------------------------------------------------------------------
include(${PROJECT_SOURCE_DIR}/cmake/extend.cmake)

## Compute version string and mode + Documentation
## -------------------------------------------------------------------------------------------------
if (DEFINED DEV AND NOT DEFINED IS_TRAVIS_CI)
  add_subdirectory(${PROJECT_SOURCE_DIR}/doc)
endif()

## Install target
## -------------------------------------------------------------------------------------------------
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION .)
if (DEFINED USE_SELF_BOOST)
  install(DIRECTORY ${NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION}/include DESTINATION .)
endif()

## Generate Boost.SIMDConfig.cmake that will be installed to make find_package useable
## -------------------------------------------------------------------------------------------------
set(PROJECT_CMAKE_CONFIG         ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake)
set(PROJECT_CMAKE_CONFIG_VERSION ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake)
set(PROJECT_CMAKE_FIND           ${PROJECT_BINARY_DIR}/Find${PROJECT_NAME}.cmake)

## Extract each version components
string(REPLACE "." ";" PROJECT_VERSION_COMPONENTS ${PROJECT_VERSION})
list(GET PROJECT_VERSION_COMPONENTS 0 PROJECT_MAJOR_VERSION)
list(GET PROJECT_VERSION_COMPONENTS 1 PROJECT_MINOR_VERSION)
list(GET PROJECT_VERSION_COMPONENTS 2 PROJECT_SUBMINOR_VERSION)
list(GET PROJECT_VERSION_COMPONENTS 3 PROJECT_SUBSUBMINOR_VERSION)

## Generate final files
configure_file(cmake/Boost.SIMDConfig.cmake.in        ${PROJECT_CMAKE_CONFIG} @ONLY)
configure_file(cmake/Boost.SIMDConfigVersion.cmake.in ${PROJECT_CMAKE_CONFIG_VERSION} @ONLY)
configure_file(cmake/FindBoost.SIMD.cmake.in          ${PROJECT_CMAKE_FIND} @ONLY)

## Install generated files
## See: http://stackoverflow.com/questions/10765885/how-to-install-your-custom-cmake-find-module
if (WIN32 OR WIN64)
  set(CMAKE_CONFIG_INSTALL_DIR cmake)
else ()
  set(CMAKE_CONFIG_INSTALL_DIR share/cmake/${PROJECT_NAME})
endif()
install(
    FILES ${PROJECT_CMAKE_CONFIG} ${PROJECT_CMAKE_CONFIG_VERSION} ${PROJECT_CMAKE_FIND}
    DESTINATION ${CMAKE_CONFIG_INSTALL_DIR}
)

## Add include directories
## -------------------------------------------------------------------------------------------------
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/test
  ${PROJECT_SOURCE_DIR}/bench
  ${PROJECT_SOURCE_DIR}/exhaustive
  ${NS_BENCH_DESTINATION}/include/
  ${STF_DESTINATION}/include/
  ${Boost_INCLUDE_DIRS}
)

## Setup Unit/Bench & Coverage Test
## -------------------------------------------------------------------------------------------------
if (DEFINED DEV)
  include(${PROJECT_SOURCE_DIR}/setup.cmake) # Import compiler specific setup

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

  message(STATUS "## -----------------------------------------------------------------------------")
  message(STATUS "   Unit and performances tests are available.")
  message(STATUS "   Please run the update targets at least once to install pre-requisites:")
  message(STATUS "       make -j1 update / ninja -j1 update")
  message(STATUS "## -----------------------------------------------------------------------------")
else()
  add_custom_target(tests
    COMMENT "Target tests requires 'cmake -DDEV=1 ..'")
  add_custom_target(unit
    COMMENT "Target unit requires 'cmake -DDEV=1 ..'")
  add_custom_target(bench
    COMMENT "Target bench requires 'cmake -DDEV=1 ..'")
  add_custom_target(exhaustive
    COMMENT "Target exhaustive requires 'cmake -DDEV=1 ..'")
endif()

