##==================================================================================================
##                             Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_MAKE_CODEGEN)
NS_include(compilers)
NS_include(add_target_parent)

##==================================================================================================
## Process a list of source files to generate corresponding codegen target
##==================================================================================================
macro(make_codegen root)
  foreach(cpp ${ARGN})
    string(REPLACE ".cpp" ".codegen" base ${cpp})
    set(codegen "${root}.${base}")

    set(cpp ${CMAKE_CURRENT_LIST_DIR}/${cpp})
    set(asm ${PROJECT_BINARY_DIR}/codegen/${codegen})

    add_custom_target(${codegen})

    if (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
      set(IS_MSVC TRUE)
    else()
      set(IS_MSVC FALSE)
    endif()

    set(INC_FLAGS "")
    get_property(includes DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
    foreach(inc ${includes})
      if (${IS_MSVC})
        set(INC_FLAGS "${INC_FLAGS} /I${inc}")
      else()
        set(INC_FLAGS "${INC_FLAGS} -I${inc}")
      endif()
    endforeach()

    if (${IS_MSVC})
      set(ASM_FLAGS "/c /FA /Fe${asm}")
    else()
      set(ASM_FLAGS "-c -S -o ${asm}")
    endif()

    if (${IS_MSVC})
      set(_COMMAND WINDOWS_COMMAND)
    else()
      set(_COMMAND UNIX_COMMAND)
    endif()

    separate_arguments(_CMAKE_CXX_FLAGS ${_COMMAND} ${CMAKE_CXX_FLAGS})
    separate_arguments(_INC_FLAGS       ${_COMMAND} ${INC_FLAGS})
    separate_arguments(_ASM_FLAGS       ${_COMMAND} ${ASM_FLAGS})

    add_custom_command(
      TARGET ${codegen}
      COMMAND ${CMAKE_CXX_COMPILER} ${cpp} ${_CMAKE_CXX_FLAGS} ${_INC_FLAGS} ${_ASM_FLAGS}
      COMMENT "Creating codegen: ${asm}"
    )

    add_target_parent(${codegen})
    set_target_properties(${codegen}
      PROPERTIES
      EXCLUDE_FROM_DEFAULT_BUILD TRUE
      EXCLUDE_FROM_ALL TRUE
      ${MAKE_CODEGEN_TARGET_PROPERTIES}
    )
    if (MAKE_CODEGEN_TARGET_LINK_LIBRARIES)
        target_link_libraries(${codegen} ${MAKE_CODEGEN_TARGET_LINK_LIBRARIES})
    endif()

    add_dependencies(codegen ${codegen})
  endforeach()
endmacro()

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/codegen)
