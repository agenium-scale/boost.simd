##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_BOOST_SIMD)

## -------------------------------------------------------------------------------------------------

if (NOT DEFINED BOOST_SIMD_GIT_TAG)
  set(BOOST_SIMD_GIT_TAG master)
endif()

if (NOT DEFINED BOOST_SIMD_DESTINATION)
  set(BOOST_SIMD_DESTINATION ${NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION})
endif()

NS_project_add(BOOST_SIMD
  GIT_REPOSITORY https://github.com/NumScale/boost.simd.git
  GIT_TAG        ${BOOST_SIMD_GIT_TAG}
  DESTINATION    ${BOOST_SIMD_DESTINATION}

  STEP_TARGETS   install
  EXCLUDE_FROM_ALL

  ${NS_CMAKE_PROJECT_OPTIONS} ${BOOST_SIMD_OPTIONS}
)

add_custom_target(update.boost.simd
  DEPENDS ${BOOST_SIMD_INSTALL_TARGET}
  COMMENT "Updating boost.simd"
)

add_dependencies(update update.boost.simd)

NS_project_add_git_update_target(boost.simd
  ${BOOST_SIMD_DESTINATION}/boost.simd
)

## -------------------------------------------------------------------------------------------------

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  BOOST_SIMD
)
