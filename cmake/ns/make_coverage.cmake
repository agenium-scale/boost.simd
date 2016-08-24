##==================================================================================================
##                             Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_MAKE_COVERAGE)
NS_include(compilers)
NS_include(add_target_parent)

##==================================================================================================
## Process a list of source files to generate corresponding coverage target
##==================================================================================================
function(make_coverage root)

  if(DEFINED COVERAGE_SUPPORTED)

    foreach(file ${ARGN})

      string(REPLACE ".cpp" ".coverage" base ${file})
      set(test "${root}.${base}")

      add_executable(${test} ${file})

      set_property( TARGET ${test}
                    PROPERTY COMPILE_FLAGS  ${CMAKE_CXX_FLAGS_COVERAGE}
                  )

      set_property( TARGET ${test}
                    PROPERTY LINK_FLAGS ${CMAKE_EXE_LINKER_FLAGS_COVERAGE}
                  )

      set_property( TARGET ${test}
                    PROPERTY RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/test"
                  )

      add_target_parent(${test})

      add_test( NAME ${test}
                WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/test"
                COMMAND $<TARGET_FILE:${test}>
              )

      set_target_properties ( ${test} PROPERTIES
                              EXCLUDE_FROM_DEFAULT_BUILD TRUE
                              EXCLUDE_FROM_ALL TRUE
                              ${MAKE_COVERAGE_TARGET_PROPERTIES}
                            )

      add_dependencies(coverage ${test})

    endforeach()

  endif()

endfunction()
