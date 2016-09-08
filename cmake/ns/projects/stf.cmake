##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_STF)

## -------------------------------------------------------------------------------------------------

if (NOT DEFINED STF_GIT_TAG)
  set(STF_GIT_TAG master)
endif()

if (NOT DEFINED STF_DESTINATION)
  set(STF_DESTINATION ${NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION})
endif()

## -------------------------------------------------------------------------------------------------

NS_project_add(STF
  GIT_REPOSITORY https://github.com/jfalcou/stf.git
  GIT_TAG        ${STF_GIT_TAG}
  DESTINATION    ${STF_DESTINATION}

  STEP_TARGETS   install
  EXCLUDE_FROM_ALL

  ${NS_CMAKE_PROJECT_OPTIONS} ${STF_OPTIONS}
)

add_custom_target(update.stf
  DEPENDS ${STF_INSTALL_TARGET}
  COMMENT "Updating stf"
)

add_dependencies(update update.stf)

NS_project_add_git_update_target(stf
  ${STF_DESTINATION}/include/stf
)

## -------------------------------------------------------------------------------------------------

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  STF
)
