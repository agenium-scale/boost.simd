##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_BRIGAND_STANDALONE)

## -------------------------------------------------------------------------------------------------

if (NOT DEFINED BRIGAND_GIT_TAG)
  set(BRIGAND_GIT_TAG master)
endif()

if (NOT DEFINED BRIGAND_STANDALONE_DESTINATION)
  NS_warn("BRIGAND_STANDALONE_DESTINATION is not set, brigand.standalone targets won't be available!")
  return()
endif()

## -------------------------------------------------------------------------------------------------

NS_project_add(BRIGAND_STANDALONE
  GIT_REPOSITORY https://github.com/edouarda/brigand.git
  GIT_TAG        ${BRIGAND_GIT_TAG}
  DESTINATION    ${BRIGAND_STANDALONE_DESTINATION}

  STEP_TARGETS   configure
  EXCLUDE_FROM_ALL

  ${NS_CMAKE_PROJECT_OPTIONS} ${BRIGAND_OPTIONS}
)

add_custom_target(update.brigand.standalone
  DEPENDS ${BRIGAND_STANDALONE_CONFIGURE_TARGET}
)
add_custom_command(
  TARGET  update.brigand.standalone
  COMMAND ${CMAKE_COMMAND} --build . --target standalone
  WORKING_DIRECTORY ${BRIGAND_STANDALONE_BUILD_DIR}
)
add_custom_command(
  TARGET  update.brigand.standalone
  COMMENT "Updating brigand (standalone)"
  COMMAND ${CMAKE_COMMAND} -E copy
    ${BRIGAND_STANDALONE_SOURCE_DIR}/standalone/brigand.hpp
    ${BRIGAND_STANDALONE_DESTINATION}/brigand.hpp
)

add_dependencies(update update.brigand.standalone)

NS_project_add_git_update_target(brigand.standalone
  ${BRIGAND_STANDALONE_DESTINATION}/brigand.hpp
)

## -------------------------------------------------------------------------------------------------

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  BRIGAND_STANDALONE
)
