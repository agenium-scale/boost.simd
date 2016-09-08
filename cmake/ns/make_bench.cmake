## -------------------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_MAKE_BENCH)
NS_include(compilers)
NS_include(add_target_parent)

## Process a list of source files to generate corresponding bench target
## -------------------------------------------------------------------------------------------------
function(make_bench root)
  foreach(file ${ARGN})
    string(REPLACE ".cpp" ".bench" base ${file})
    set(bench "${root}.${base}")

    add_executable(${bench} ${file})
    set_property( TARGET ${bench}
                  PROPERTY RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bench"
                )
    set_target_properties ( ${bench} PROPERTIES
                            EXCLUDE_FROM_DEFAULT_BUILD TRUE
                            EXCLUDE_FROM_ALL TRUE
                          )
    if (MAKE_BENCH_TARGET_LINK_LIBRARIES)
        target_link_libraries(${bench} ${MAKE_BENCH_TARGET_LINK_LIBRARIES})
    endif()

    add_target_parent(${bench})
    add_dependencies(bench ${bench})
  endforeach()
endfunction()
