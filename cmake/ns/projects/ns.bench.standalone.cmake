##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_NS_BENCH_STANDALONE)

## -------------------------------------------------------------------------------------------------

if (NOT DEFINED NS_BENCH_GIT_TAG)
  set(NS_BENCH_GIT_TAG master)
endif()

if (NOT DEFINED NS_BENCH_STANDALONE_DESTINATION)
  NS_warn("NS_BENCH_STANDALONE_DESTINATION is not set, ns.bench.standalone targets won't be available!")
  return()
endif()

## -------------------------------------------------------------------------------------------------

NS_project_add(NS_BENCH_STANDALONE
  GIT_REPOSITORY https://github.com/NumScale/ns.bench.git
  GIT_TAG        ${NS_BENCH_GIT_TAG}
  DESTINATION    ${NS_BENCH_STANDALONE_DESTINATION}

  STEP_TARGETS   configure
  EXCLUDE_FROM_ALL

  ${NS_CMAKE_PROJECT_OPTIONS} ${NS_BENCH_OPTIONS}
)

add_custom_target(update.ns.bench.standalone
  DEPENDS ${NS_BENCH_STANDALONE_CONFIGURE_TARGET}
)
add_custom_command(
  TARGET  update.ns.bench.standalone
  COMMAND ${CMAKE_COMMAND} --build . --target standalone
  WORKING_DIRECTORY ${NS_BENCH_STANDALONE_BUILD_DIR}
)
add_custom_command(
  TARGET  update.ns.bench.standalone
  COMMENT "Updating ns.bench (standalone)"
  COMMAND ${CMAKE_COMMAND} -E copy
    ${NS_BENCH_STANDALONE_SOURCE_DIR}/standalone/ns.bench.hpp
    ${NS_BENCH_STANDALONE_DESTINATION}/ns.bench.hpp
)

add_dependencies(update update.ns.bench.standalone)

NS_project_add_git_update_target(ns.bench.standalone
  ${NS_BENCH_STANDALONE_DESTINATION}/ns.bench.hpp
)

## -------------------------------------------------------------------------------------------------

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  NS_BENCH_STANDALONE
)
