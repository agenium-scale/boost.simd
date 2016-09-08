##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_BOOST_HEADER_ONLY)

## -------------------------------------------------------------------------------------------------

if (NOT DEFINED BOOST_HEADER_ONLY_GIT_TAG)
  set(BOOST_HEADER_ONLY_GIT_TAG master)
endif()

if (NOT DEFINED BOOST_HEADER_ONLY_DESTINATION)
  set(BOOST_HEADER_ONLY_DESTINATION ${NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION})
endif()

NS_project_add(BOOST_HEADER_ONLY
  GIT_REPOSITORY https://github.com/NumScale/boost-header-only.git
  GIT_TAG        ${BOOST_HEADER_ONLY_GIT_TAG}
  DESTINATION    ${BOOST_HEADER_ONLY_DESTINATION}

  STEP_TARGETS   install
  EXCLUDE_FROM_ALL

  ${NS_CMAKE_PROJECT_OPTIONS} ${BOOST_HEADER_ONLY_OPTIONS}
)

add_custom_target(update.boost-header-only
  DEPENDS ${BOOST_HEADER_ONLY_INSTALL_TARGET}
  COMMENT "Updating boost-header-only"
)

add_dependencies(update update.boost-header-only)

NS_project_add_git_update_target(boost-header-only
  ${BOOST_HEADER_ONLY_DESTINATION}/boost-header-only
)

## -------------------------------------------------------------------------------------------------

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  BOOST_HEADER_ONLY
)
