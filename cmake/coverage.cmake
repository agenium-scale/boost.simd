##==================================================================================================
##                 Copyright 2009 - 2015   LRI    UMR 8623 CNRS/Univ Paris Sud XI
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================
FUNCTION(ENABLE_COVERAGE root)

    SET(BOOST_FILTER "'${Boost_INCLUDE_DIRS}/*'")

    ADD_CUSTOM_TARGET( coverage

        COMMAND ${CMAKE_COMMAND} -E remove coverage.info coverage.info.cleaned
        COMMAND ${LCOV_PATH} --directory . --zerocounters
        COMMAND ctest -R ^${root}.*.coverage
        COMMAND ${LCOV_PATH} --directory . --capture --output-file coverage.info
        COMMAND ${LCOV_PATH} --remove coverage.info '*tests/*' '*usr/*' '*deps/*' ${BOOST_FILTER} --output-file coverage.info.cleaned
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Processing code coverage counters."
    )

    ADD_DEPENDENCIES(tests coverage)

ENDFUNCTION()

IF(NOT CMAKE_COMPILER_IS_GNUCXX)
    MESSAGE(STATUS "[coverage] Compiler does not support gcov. coverage targets disabled")
    return()
ENDIF() ## NOT CMAKE_COMPILER_IS_GNUCXX

FIND_PROGRAM( GCOV_PATH gcov )
FIND_PROGRAM( LCOV_PATH lcov )

IF(NOT GCOV_PATH)
  MESSAGE(STATUS "[coverage] gcov not found! Coverage disabled")
  return()
ENDIF()

IF(NOT LCOV_PATH)
  MESSAGE(STATUS "[coverage] lcov not found! Coverage disabled")
  return()
ENDIF()

SET(CMAKE_CXX_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C++ compiler during coverage builds."
    FORCE )
SET(CMAKE_C_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C compiler during coverage builds."
    FORCE )
SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE
    "-lgcov -fprofile-arcs "
    CACHE STRING "Flags used for linking binaries during coverage builds."
    FORCE )
SET(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    "-lgcov -fprofile-arcs "
    CACHE STRING "Flags used by the shared libraries linker during coverage builds."
    FORCE )

MARK_AS_ADVANCED(
    CMAKE_CXX_FLAGS_COVERAGE
    CMAKE_C_FLAGS_COVERAGE
    CMAKE_EXE_LINKER_FLAGS_COVERAGE
    CMAKE_SHARED_LINKER_FLAGS_COVERAGE )

SET(COVERAGE_SUPPORTED 1)
