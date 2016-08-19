##==================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_COVERAGE)

function(enable_coverage root)

    set(BOOST_FILTER "'${Boost_INCLUDE_DIRS}/*'")
    add_custom_target( coverage

        COMMAND ${CMAKE_COMMAND} -E remove coverage.info coverage.info.cleaned
        COMMAND ${LCOV_PATH} --directory . --zerocounters
        COMMAND ctest -R ^${root}.*.coverage
        COMMAND ${LCOV_PATH} --directory . --capture --output-file coverage.info
        COMMAND ${LCOV_PATH} --remove coverage.info '*tests/*' '*usr/*' '*deps/*' ${BOOST_FILTER} --output-file coverage.info.cleaned
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Processing code coverage counters."
    )

    add_dependencies(tests coverage)

endfunction()

if(NOT CMAKE_COMPILER_IS_GNUCXX)
  NS_say("Compiler does not support gcov. coverage targets disabled")
  return()
endif() ## NOT CMAKE_COMPILER_IS_GNUCXX

find_program( GCOV_PATH gcov )
find_program( LCOV_PATH lcov )

if(NOT GCOV_PATH)
  NS_say("gcov not found! Coverage disabled")
  return()
endif()

if(NOT LCOV_PATH)
  NS_say("lcov not found! Coverage disabled")
  return()
endif()

set(CMAKE_CXX_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C++ compiler during coverage builds."
    FORCE)
set(CMAKE_C_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C compiler during coverage builds."
    FORCE)
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE
    "-lgcov -fprofile-arcs "
    CACHE STRING "Flags used for linking binaries during coverage builds."
    FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    "-lgcov -fprofile-arcs "
    CACHE STRING "Flags used by the shared libraries linker during coverage builds."
    FORCE)

mark_as_advanced(
    CMAKE_CXX_FLAGS_COVERAGE
    CMAKE_C_FLAGS_COVERAGE
    CMAKE_EXE_LINKER_FLAGS_COVERAGE
    CMAKE_SHARED_LINKER_FLAGS_COVERAGE)

set(COVERAGE_SUPPORTED TRUE)
