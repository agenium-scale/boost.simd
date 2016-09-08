##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_NS_BENCH)

## -------------------------------------------------------------------------------------------------

if (NOT DEFINED NS_BENCH_GIT_TAG)
  set(NS_BENCH_GIT_TAG master)
endif()

if (NOT DEFINED NS_BENCH_DESTINATION)
  set(NS_BENCH_DESTINATION ${NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION})
endif()

NS_project_add(NS_BENCH
  GIT_REPOSITORY https://github.com/NumScale/ns.bench.git
  GIT_TAG        ${NS_BENCH_GIT_TAG}
  DESTINATION    ${NS_BENCH_DESTINATION}

  STEP_TARGETS   install
  EXCLUDE_FROM_ALL

  ${NS_CMAKE_PROJECT_OPTIONS} ${NS_BENCH_OPTIONS}
)

add_custom_target(update.ns.bench
  DEPENDS ${NS_BENCH_INSTALL_TARGET}
  COMMENT "Updating ns.bench"
)

add_dependencies(update update.ns.bench)

NS_project_add_git_update_target(ns.bench
  ${NS_BENCH_DESTINATION}/ns.bench
)

## -------------------------------------------------------------------------------------------------

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  NS_BENCH
)
