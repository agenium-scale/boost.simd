##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_BOOST_DISPATCH)

## -------------------------------------------------------------------------------------------------

if (NOT DEFINED BOOST_DISPATCH_GIT_TAG)
  set(BOOST_DISPATCH_GIT_TAG master)
endif()

if (NOT DEFINED BOOST_DISPATCH_DESTINATION)
  set(BOOST_DISPATCH_DESTINATION ${NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION})
endif()

NS_project_add(BOOST_DISPATCH
  GIT_REPOSITORY https://github.com/NumScale/boost.dispatch.git
  GIT_TAG        ${BOOST_DISPATCH_GIT_TAG}
  DESTINATION    ${BOOST_DISPATCH_DESTINATION}

  STEP_TARGETS   install
  EXCLUDE_FROM_ALL

  ${NS_CMAKE_PROJECT_OPTIONS} ${BOOST_DISPATCH_OPTIONS}
)

add_custom_target(update.boost.dispatch
  DEPENDS ${BOOST_DISPATCH_INSTALL_TARGET}
  COMMENT "Updating boost.dispatch"
)

add_dependencies(update update.boost.dispatch)

NS_project_add_git_update_target(boost.dispatch
  ${BOOST_DISPATCH_DESTINATION}/boost.dispatch
)

## -------------------------------------------------------------------------------------------------

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  BOOST_DISPATCH
)
