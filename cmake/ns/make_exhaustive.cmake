## -------------------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_MAKE_EXHAUSTIVE)
NS_include(compilers)
NS_include(add_target_parent)

## Process a list of source files to generate corresponding exhaustive target
## -------------------------------------------------------------------------------------------------
function(make_exhaustive root)
  foreach(file ${ARGN})
    string(REPLACE ".cpp" ".exhaustive" base ${file})
    set(exhaustive "${root}.${base}")

    add_executable(${exhaustive} ${file})
    set_property( TARGET ${exhaustive}
                  PROPERTY RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/exhaustive"
                )
    set_target_properties ( ${exhaustive} PROPERTIES
                            EXCLUDE_FROM_DEFAULT_BUILD TRUE
                            EXCLUDE_FROM_ALL TRUE
                            ${MAKE_EXHAUSTIVE_TARGET_PROPERTIES}
                          )
    if (MAKE_EXHAUSTIVE_TARGET_LINK_LIBRARIES)
        target_link_libraries(${exhaustive} ${MAKE_EXHAUSTIVE_TARGET_LINK_LIBRARIES})
    endif()

    add_target_parent(${exhaustive})
    add_dependencies(exhaustive ${exhaustive})
  endforeach()
endfunction()

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()
