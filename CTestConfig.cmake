##==================================================================================================
##                 Copyright 2009 - 2015   LRI    UMR 8623 CNRS/Univ Paris Sud XI
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================
set(CTEST_PROJECT_NAME "Boost.SIMD")
set(CTEST_NIGHTLY_START_TIME "00:00:00 CEST")
set(CTEST_TEST_TIMEOUT "600")

set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "cdash.lri.fr")
set(CTEST_DROP_LOCATION "/submit.php?project=boost.simd")
set(CTEST_DROP_SITE_CDASH TRUE)

if(CMAKE_PROJECT_NAME STREQUAL Boost.SIMD)
  set(SOURCE_DIRECTORY ${PROJECT_SOURCE_DIR})
else()
  get_filename_component(SOURCE_DIRECTORY ${CTEST_SOURCE_DIRECTORY} ABSOLUTE)
endif()

# SITE is host name
if( $ENV{TRAVIS_JOB_NUMBER} )
  set(SITE "travis-$ENV{TRAVIS_JOB_NUMBER}")
elseif( $ENV{APPVEYOR_BUILD_ID})
  set(SITE "appveyor-$ENV{APPVEYOR_BUILD_ID}")
else()
  execute_process(COMMAND hostname OUTPUT_VARIABLE HOST OUTPUT_STRIP_TRAILING_WHITESPACE)
  string(REGEX REPLACE "\\.(local|home)$" "" HOST ${HOST})
  string(TOLOWER ${HOST} SITE)
endif()

# BUILDNAME is generated from OS, architecture, compiler and SIMD level (in-project only)
if(CMAKE_PROJECT_NAME STREQUAL Boost.SIMD)
  set(OS ${CMAKE_SYSTEM_NAME})

  if(TOOLSET)
    set(COMPILER "${TOOLSET}-${SIMD_EXT}-std=c++${CXX_STD}")
  else()
    string(TOLOWER ${CMAKE_CXX_COMPILER_ID} COMPILER)
    string(REGEX REPLACE "([0-9]+)\\.([0-9]+).*" "\\1" VERSION_MAJOR "${CMAKE_CXX_COMPILER_VERSION}")
    string(REGEX REPLACE "([0-9]+)\\.([0-9]+).*" "\\2" VERSION_MINOR "${CMAKE_CXX_COMPILER_VERSION}")

    # Compiler version is that of cl.exe, we convert it to MSVC
    if(MSVC AND VERSION_MAJOR)
      math(EXPR VERSION_MAJOR "${VERSION_MAJOR} - 6")
    endif()

    if(VERSION_MINOR)
      set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR})
    else()
      set(VERSION ${VERSION_MAJOR})
    endif()
    set(COMPILER "${COMPILER}${VERSION}")
  endif()

  set(BUILDNAME "${OS}-${COMPILER}")
  file(WRITE ${PROJECT_BINARY_DIR}/CTestConfigData.cmake "set(BUILDNAME ${BUILDNAME})\nset(CTEST_USE_LAUNCHERS ${CTEST_USE_LAUNCHERS})")

else()
# outside of project, we load a file
  set(PROJECT_SOURCE_DIR ${CTEST_SOURCE_DIRECTORY})
  set(PROJECT_BINARY_DIR ${CTEST_BINARY_DIRECTORY})
  include(${PROJECT_BINARY_DIR}/CTestConfigData.cmake)
endif()

# We add commit tag
find_package(Git QUIET)
if(GIT_EXECUTABLE)
  execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
                  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                  OUTPUT_VARIABLE BRANCH OUTPUT_STRIP_TRAILING_WHITESPACE
                  RESULT_VARIABLE BRANCH_RESULT ERROR_QUIET
                 )

  set(BUILDNAME "${BUILDNAME}-@${BRANCH}")
endif()

set(CTEST_SITE ${SITE})
set(CTEST_BUILD_NAME ${BUILDNAME})
