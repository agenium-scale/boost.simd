##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_BRIGAND)

## -------------------------------------------------------------------------------------------------

if (NOT DEFINED BRIGAND_GIT_TAG)
  set(BRIGAND_GIT_TAG master)
endif()

if (NOT DEFINED BRIGAND_DESTINATION)
  set(BRIGAND_DESTINATION ${NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION})
endif()

NS_project_add(BRIGAND
  GIT_REPOSITORY https://github.com/edouarda/brigand.git
  GIT_TAG        ${BRIGAND_GIT_TAG}
  DESTINATION    ${BRIGAND_DESTINATION}

  STEP_TARGETS   install
  EXCLUDE_FROM_ALL

  ${NS_CMAKE_PROJECT_OPTIONS} ${BRIGAND_OPTIONS}
)

add_custom_target(update.brigand
  DEPENDS ${BRIGAND_INSTALL_TARGET}
  COMMENT "Updating brigand"
)

add_dependencies(update update.brigand)

NS_project_add_git_update_target(brigand
  ${BRIGAND_DESTINATION}/brigand
)

## -------------------------------------------------------------------------------------------------

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  BRIGAND
)
