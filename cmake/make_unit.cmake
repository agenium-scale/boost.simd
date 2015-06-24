##==================================================================================================
##                 Copyright 2009 - 2015   LRI    UMR 8623 CNRS/Univ Paris Sud XI
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================
include(compilers)
include(add_target_parent)

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

    add_test( NAME ${test}
              WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/test"
              COMMAND $<TARGET_FILE:${test}>
            )

    set_target_properties ( ${test} PROPERTIES
                            EXCLUDE_FROM_DEFAULT_BUILD TRUE
                            EXCLUDE_FROM_ALL TRUE
                          )

    add_target_parent(${test})

    add_dependencies(unit ${test})

  endforeach()

endfunction()
