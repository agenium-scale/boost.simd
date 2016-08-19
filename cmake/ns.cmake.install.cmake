##==================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

include(ExternalProject)

if (NOT NS_CMAKE_INSTALL_DIR)
  set(NS_CMAKE_INSTALL_DIR ${PROJECT_SOURCE_DIR})
endif()

if (NOT NS_CMAKE_EXTERNAL_PROJECTS_WORKSPACE)
    set(NS_CMAKE_EXTERNAL_PROJECTS_WORKSPACE ${PROJECT_BINARY_DIR}/_deps)
endif()

if (NOT NS_CMAKE_GIT_TAG)
  set(NS_CMAKE_GIT_TAG master)
endif()

set(_PROJECT_NAME          NS_CMAKE)
set(_PROJECT_DIR           ${NS_CMAKE_INSTALL_DIR})
set(_PROJECT_WORKSPACE_DIR ${NS_CMAKE_EXTERNAL_PROJECTS_WORKSPACE}/_${_PROJECT_NAME})
set(_PROJECT_SOURCE_DIR    ${_PROJECT_WORKSPACE_DIR}/${_PROJECT_NAME})
set(_PROJECT_BUILD_DIR     ${_PROJECT_WORKSPACE_DIR}/_build)

ExternalProject_Add(
  # The project name
  ${_PROJECT_NAME}

  # Git infos
  GIT_REPOSITORY https://github.com/NumScale/ns.cmake.git
  GIT_TAG        ${NS_CMAKE_GIT_TAG}

  # Where all the temporary stuffs will be located
  PREFIX       ${_PROJECT_WORKSPACE_DIR}
  SOURCE_DIR   ${_PROJECT_SOURCE_DIR}
  BINARY_DIR   ${_PROJECT_BUILD_DIR}
  DOWNLOAD_DIR ${_PROJECT_BUILD_DIR}/_dl
  TMP_DIR      ${_PROJECT_BUILD_DIR}/_tmp
  STAMP_DIR    ${_PROJECT_BUILD_DIR}/_stamp

  # Install (we DO need to add the CMAKE_INSTALL_PREFIX...)
  INSTALL_DIR ${_PROJECT_DIR}
  CMAKE_ARGS  "-DCMAKE_INSTALL_PREFIX=${_PROJECT_DIR}"

  # Steps to generate
  STEP_TARGETS   install
)

if (EXISTS ${NS_CMAKE_INSTALL_DIR}/cmake/ns/ns.cmake)
  message(STATUS "## -----------------------------------------------------------------------------")
  message("")
  message("   ns.cmake is now installed!")
  message("   ns.cmake's (init) targets have been excluded from the `all` target!")
  message("")
  message(STATUS "## -----------------------------------------------------------------------------")
  set_target_properties(NS_CMAKE
    PROPERTIES EXCLUDE_FROM_ALL TRUE
  )
  set(NS_CMAKE_INSTALLED TRUE)
else()
  message(WARNING "You intended to use ns.cmake, but it has not been installed yet!")

  add_custom_command(
    TARGET NS_CMAKE
    COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}
  )
  set(NS_CMAKE_INSTALLED FALSE)
endif()
