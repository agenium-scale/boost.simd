##==================================================================================================
##                               Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

include(ExternalProject)

if (NOT NS_CMAKE_INSTALL_DIR)
  set(NS_CMAKE_INSTALL_DIR ${PROJECT_SOURCE_DIR})
endif()

if (NOT NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION)
  set(NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION ${PROJECT_BINARY_DIR}/_install)
endif()

if (NOT NS_CMAKE_GIT_TAG)
  set(NS_CMAKE_GIT_TAG master)
endif()

ExternalProject_Add(NS_CMAKE
  GIT_REPOSITORY https://github.com/NumScale/ns.cmake.git
  GIT_TAG        ${NS_CMAKE_GIT_TAG}
  PREFIX         ${NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION}

  STEP_TARGETS   install

  INSTALL_DIR    ${NS_CMAKE_INSTALL_DIR}
  CMAKE_ARGS     "-DCMAKE_INSTALL_PREFIX=${NS_CMAKE_INSTALL_DIR}"
)
set(NS_CMAKE_INSTALL_TARGET NS_CMAKE-install)
set(NS_CMAKE_SOURCES ${NS_CMAKE_INSTALL_DIR}/cmake)

set(NS_CMAKE_EXTERNAL_PROJECTS
  NS_CMAKE
)

add_custom_target(ns.cmake.update
  DEPENDS ${NS_CMAKE_INSTALL_TARGET}
)

add_custom_target(ns.cmake.installed
  DEPENDS ns.cmake.update
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
