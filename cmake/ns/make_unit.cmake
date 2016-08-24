##==================================================================================================
##                 Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_MAKE_UNIT)
NS_include(compilers)
NS_include(add_target_parent)

##===================================================================================================
## Process a list of source files to generate corresponding test target
##===================================================================================================
function(make_unit root)

  foreach(file ${ARGN})

    string(REPLACE ".cpp" ".unit" base ${file})
    set(test "${root}.${base}")

    add_executable(${test} ${file})
    set_property( TARGET ${test}
                  PROPERTY RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/test"
                )

    if (CMAKE_CROSSCOMPILING_CMD)
      add_test( NAME ${test}
                WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/test"
                COMMAND ${CMAKE_CROSSCOMPILING_CMD} $<TARGET_FILE:${test}>
              )
    else()
      add_test( NAME ${test}
                WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/test"
                COMMAND $<TARGET_FILE:${test}>
              )
    endif()

    set_target_properties ( ${test} PROPERTIES
                            EXCLUDE_FROM_DEFAULT_BUILD TRUE
                            EXCLUDE_FROM_ALL TRUE
                            ${MAKE_UNIT_TARGET_PROPERTIES}
                          )

    add_target_parent(${test})

    add_dependencies(unit ${test})

  endforeach()

endfunction()
