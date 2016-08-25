##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_STF_STANDALONE)

## -------------------------------------------------------------------------------------------------

if (NOT DEFINED STF_GIT_TAG)
  set(STF_GIT_TAG master)
endif()

if (NOT DEFINED STF_STANDALONE_DESTINATION)
  NS_warn("STF_STANDALONE_DESTINATION is not set, stf.standalone targets won't be available!")
  return()
endif()

## -------------------------------------------------------------------------------------------------

NS_project_add(STF_STANDALONE
  GIT_REPOSITORY https://github.com/jfalcou/stf.git
  GIT_TAG        ${STF_GIT_TAG}
  DESTINATION    ${STF_STANDALONE_DESTINATION}

  STEP_TARGETS   configure
  EXCLUDE_FROM_ALL

  ${NS_CMAKE_PROJECT_OPTIONS} ${STF_OPTIONS}
)

add_custom_target(update.stf.standalone
  DEPENDS ${STF_STANDALONE_CONFIGURE_TARGET}
)
add_custom_command(
  TARGET  update.stf.standalone
  COMMAND ${CMAKE_COMMAND} --build . --target standalone
  WORKING_DIRECTORY ${STF_STANDALONE_BUILD_DIR}
)
add_custom_command(
  TARGET  update.stf.standalone
  COMMENT "Updating stf (standalone)"
  COMMAND ${CMAKE_COMMAND} -E copy
    ${STF_STANDALONE_SOURCE_DIR}/standalone/stf.hpp
    ${STF_STANDALONE_DESTINATION}/stf.hpp
)

add_dependencies(update update.stf.standalone)

NS_project_add_git_update_target(stf.standalone
  ${STF_STANDALONE_DESTINATION}/stf.hpp
)

## -------------------------------------------------------------------------------------------------

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  STF_STANDALONE
)
