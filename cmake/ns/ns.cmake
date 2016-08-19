##==================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

## Guard helper
## -------------------------------------------------------------------------------------------------
macro (NS_guard name)
  get_property(IS_INCLUDED GLOBAL PROPERTY ${name})
  if (${IS_INCLUDED})
    return()
  else()
    set_property(GLOBAL PROPERTY ${name} TRUE)
  endif()
endmacro()

NS_guard(NS_CMAKE_INCLUDED)
## -------------------------------------------------------------------------------------------------

include(ExternalProject)

## Associative table
## -------------------------------------------------------------------------------------------------

## -------------------------------------------------------------------------------------------------
function (NS_map_has map key yes_or_no)
  list(FIND map ${key} INDEX)
  if ("${INDEX}" STREQUAL "-1")
    set(${yes_or_no} FALSE PARENT_SCOPE)
  else()
    set(${yes_or_no} TRUE PARENT_SCOPE)
  endif()
endfunction()

## -------------------------------------------------------------------------------------------------
function (NS_map_must_have map key)
  list(FIND map ${key} INDEX)
  if ("${INDEX}" STREQUAL "-1")
    NS_error("${map} MUST CONTAINS the following key: ${key}")
  endif()
endfunction()

## -------------------------------------------------------------------------------------------------
function (NS_map_at map key out)
  NS_map_must_have("${map}" ${key})
  list(FIND map ${key} INDEX)
  math(EXPR INDEX "${INDEX} + 1")
  list(GET map ${INDEX} OUT)
  set(${out} ${OUT} PARENT_SCOPE)
endfunction()

## -------------------------------------------------------------------------------------------------
function (NS_map_remove map key out)
  NS_map_must_have("${map}" ${key})
  list(FIND map ${key} INDEX)
  math(EXPR INDEX2 "${INDEX} + 1")
  list(REMOVE_AT map ${INDEX} ${INDEX2})
  set(${out} "${map}" PARENT_SCOPE)
endfunction()

## Log helpers
## -------------------------------------------------------------------------------------------------

## Display all parameters
function (NS_message kind)
  string(REPLACE ";" " " WHAT "${ARGN}")
  message(${kind} "[${PROJECT_NAME}]: ${WHAT}")
endfunction()

## Display all parameters
function (NS_say)
  NS_message(STATUS ${ARGN})
endfunction()

## Display all parameters
function (NS_warn)
  NS_message(WARNING ${ARGN})
endfunction()

## Same as `NS_say` but will exit after outputting the message
function (NS_error)
  NS_message(FATAL_ERROR ${ARGN})
endfunction()

## Same as `NS_say` but only displayed if NS_ENABLE_DEBUG is defined
function (NS_debug)
  if (DEFINED NS_ENABLE_DEBUG)
    NS_message(STATUS "debug: ${ARGN}")
  endif()
endfunction()

## Macro to easily show `A = ${A}` where `A` is a variable
macro (NS_show var)
  message(STATUS "[${PROJECT_NAME}]: ${var} = ${${var}}")
endmacro()

## Macro to easily show `A = ${A}` where `A` is a variable (only if NS_ENABLE_DEBUG is defined)
macro (NS_debug_show var)
  if (DEFINED NS_ENABLE_DEBUG)
    message(STATUS "[${PROJECT_NAME}]: ${var} = ${${var}}")
  endif()
endmacro()

## General helpers
## -------------------------------------------------------------------------------------------------

## Set both in current scope and parent scope
macro (NS_set name value)
  set(${name} ${value})
  set(${name} ${value} PARENT_SCOPE)
endmacro()

## Ignore expression to prevent some cmake warnings
macro(NS_ignore)
  # Nothing to do here!
endmacro()

## Add path to include module path of cmake
function (NS_cmake_add_path path)
  list(APPEND CMAKE_MODULE_PATH ${path})
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} PARENT_SCOPE)
endfunction()

## Prevent from calling cmake at project root directory
function (NS_prevent_in_source_build)
  if (NOT DEFINED PROJECT_SOURCE_DIR)
    NS_error("Calling `NS_prevent_in_source_build` requires cmake project!")
  endif()
  if (${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    NS_error("Building in-source, not recommended! Build in a separate directory.")
  endif()
endfunction()

## Find CMake package more strictly (if `REQUIRED` is passed as parameter and that no package has
## been found, then an error will be reported)
macro (NS_find_package name)
  find_package(${name} ${ARGN})
  NS_map_has("${ARGN}" REQUIRED YES)
  if (${YES} AND NOT ${name}_FOUND)
    NS_error("'${name}' package is required but has not been found!")
  endif()
endmacro()

## Include a cmake file that is in ns.cmake
macro (NS_include path)
  set(INC_PATH ${NS_CMAKE_ROOT}/${path})
  if (EXISTS ${INC_PATH})
    include(${INC_PATH})
  elseif(EXISTS ${INC_PATH}.cmake)
    include(${INC_PATH}.cmake)
  else()
    include(${INC_PATH})
  endif()
endmacro()

## Global get
macro (NS_global_get name out)
  get_property(${out} GLOBAL PROPERTY ${name})
endmacro()

## Global set
macro (NS_global_set name value)
  set_property(GLOBAL PROPERTY ${name} ${value})
endmacro()

## -------------------------------------------------------------------------------------------------

## Set the workspace directory for all external projects
function (NS_project_global_workspace dir)
  NS_set(NS_CMAKE_EXTERNAL_PROJECTS_WORKSPACE ${dir})
endfunction()

## Set the destination for all external projects
function (NS_project_global_destination dir)
  NS_set(NS_CMAKE_EXTERNAL_PROJECTS_DESTINATION ${dir})
endfunction()

## Include project configuration
macro (NS_project_include project)
  NS_include(projects/${project})
endmacro()

macro (_NS_project_target_setup name)
  set(GIT ${GIT_EXECUTABLE} -C ${PROJECT_SOURCE_DIR})
  set(_NULL ${CMAKE_CURRENT_BINARY_DIR}/nullbytes)
  set(_DIFF ${CMAKE_CURRENT_BINARY_DIR}/git.update.${name}.diff)
  file(WRITE ${_NULL} "")
endmacro()

macro (_NS_project_is_in_source)
  foreach(SRC ${ARGN})
    get_filename_component(ABSOLUTE_SRC ${SRC} ABSOLUTE)
    string(REGEX MATCH "^\\\${PROJECT_SOURCE_DIR}" YES \${ABSOLUTE_SRC})
    if ("${YES}" STREQUAL "")
      return()
    endif()
  endforeach(SRC)
endmacro()

## 
function (NS_project_add_check_target name)
  _NS_project_is_in_source(${ARGN})
  _NS_project_target_setup(${name})
  add_custom_target(update.${name}.check)
  add_dependencies(update.check update.${name}.check)
  add_custom_command(
    TARGET  update.${name}.check
    COMMENT "Checking updates for: ${name}"
    COMMAND
         ${GIT} reset
      &&
      \( ${GIT} --no-pager diff ${ARGN}
      || ${CMAKE_COMMAND} -E echo ""
      \) >  ${_DIFF}
  )
  add_custom_command(
    TARGET  update.check
    COMMAND
         ${CMAKE_COMMAND} -E compare_files ${_NULL} ${_DIFF}
      && ${CMAKE_COMMAND} -E echo "-- ${name} is up to date!"
      || ${CMAKE_COMMAND} -E echo "-- ${name} needs update!"
  )
endfunction()

## 
function (NS_project_add_git_update_target name)
  # --
  if (NOT TARGET update.${name}.check)
    NS_project_add_check_target(${name} ${ARGN})
  endif()
  # --
  _NS_project_is_in_source(${ARGN})
  _NS_project_target_setup(${name})
  add_custom_target(git.update.${name})
  add_dependencies(git.update git.update.${name})
  add_custom_command(
    TARGET git.update.${name}
    COMMAND
         ${CMAKE_COMMAND} -E echo "" # FIXME: DO NOT REMOVE THIS!
      &&
         ${GIT} ls-files ${ARGN} --error-unmatch
      &&
      \(
         ${CMAKE_COMMAND} -E compare_files ${_NULL} ${_DIFF}
      || ${GIT} add ${ARGN}
      \)
      || ${GIT} add ${ARGN}
  )
endfunction()

## Add an external project. This function accepts same arguments as `ExternalProject_Add`.
## - `name`: The project name
function (NS_project_add name)
  NS_map_must_have("${ARGN}" DESTINATION)
  NS_map_at("${ARGN}" DESTINATION OUT)
  NS_map_remove("${ARGN}" DESTINATION ARGN)
  set(DESTINATION ${OUT})
  # --
  NS_map_has("${ARGN}" CMAKE_ARGS YES)
  if (${YES})
    NS_map_at("${ARGN}" CMAKE_ARGS _CMAKE_ARGS)
    NS_map_remove("${ARGN}" CMAKE_ARGS ARGN)
  endif()
  # --
  set(_PROJECT_NAME          ${name})
  set(_PROJECT_DIR           ${DESTINATION})
  set(_PROJECT_WORKSPACE_DIR ${NS_CMAKE_EXTERNAL_PROJECTS_WORKSPACE}/_${name})
  set(_PROJECT_SOURCE_DIR    ${_PROJECT_WORKSPACE_DIR}/${name})
  set(_PROJECT_BUILD_DIR     ${_PROJECT_WORKSPACE_DIR}/_build)
  # --
  NS_set(${name}_NAME        ${_PROJECT_NAME} PARENT_SCOPE)
  NS_set(${name}_DIR         ${_PROJECT_DIR} PARENT_SCOPE)
  NS_set(${name}_SOURCE_DIR  ${_PROJECT_SOURCE_DIR} PARENT_SCOPE)
  NS_set(${name}_BUILD_DIR   ${_PROJECT_BUILD_DIR} PARENT_SCOPE)
  # --
  NS_say("## Adding external project: ${_PROJECT_NAME}")
  # --
  NS_debug("## Exporting those variables to the PARENT_SCOPE:")
  NS_debug_show(${name}_NAME)
  NS_debug_show(${name}_DIR)
  NS_debug_show(${name}_SOURCE_DIR)
  NS_debug_show(${name}_BUILD_DIR)
  # --
  NS_set(${name}_TARGET           ${name} PARENT_SCOPE)
  NS_set(${name}_TEST_TARGET      ${name}-test PARENT_SCOPE)
  NS_set(${name}_BUILD_TARGET     ${name}-build PARENT_SCOPE)
  NS_set(${name}_INSTALL_TARGET   ${name}-install PARENT_SCOPE)
  NS_set(${name}_DOWNLOAD_TARGET  ${name}-download PARENT_SCOPE)
  NS_set(${name}_CONFIGURE_TARGET ${name}-configure PARENT_SCOPE)
  # --
  NS_debug("## Exporting those targets to the PARENT_SCOPE:")
  NS_debug_show(${name}_TARGET)
  NS_debug_show(${name}_TEST_TARGET)
  NS_debug_show(${name}_BUILD_TARGET)
  NS_debug_show(${name}_INSTALL_TARGET)
  # --
  ExternalProject_Add(
    # The project name
    ${_PROJECT_NAME}

    # Where all the temporary stuffs will be located
    PREFIX       ${_PROJECT_WORKSPACE_DIR}
    SOURCE_DIR   ${_PROJECT_SOURCE_DIR}
    BINARY_DIR   ${_PROJECT_BUILD_DIR}
    DOWNLOAD_DIR ${_PROJECT_BUILD_DIR}/_dl
    TMP_DIR      ${_PROJECT_BUILD_DIR}/_tmp
    STAMP_DIR    ${_PROJECT_BUILD_DIR}/_stamp

    # Install (we DO need to add the CMAKE_INSTALL_PREFIX...)
    INSTALL_DIR ${_PROJECT_DIR}
    CMAKE_ARGS ${_CMAKE_ARGS} "-DCMAKE_INSTALL_PREFIX=${_PROJECT_DIR}"

    # The optional arguments
    ${ARGN}
  )
  # --
  NS_map_has("${ARGN}" EXCLUDE_FROM_ALL YES)
  if (${YES})
    set_target_properties(${name} PROPERTIES EXCLUDE_FROM_ALL TRUE)
  endif()
endfunction()

## Defaults:
## -------------------------------------------------------------------------------------------------
set(NS_CMAKE_ROOT ${CMAKE_CURRENT_LIST_DIR})

add_custom_target(update.check)
add_custom_target(update     DEPENDS update.check)
add_custom_target(git.update)
NS_project_global_workspace(${PROJECT_BINARY_DIR}/_deps)
NS_project_global_destination(${PROJECT_BINARY_DIR}/_install)

## Add target shortcuts for ns.cmake now
## -------------------------------------------------------------------------------------------------

# It is better to do that here instead of `ns.cmake.install.cmake` cause we do have
# all the helpers we need here!

add_custom_target(update.ns.cmake
  DEPENDS ${NS_CMAKE_INSTALL_TARGET}
  COMMENT "Updating ns.cmake"
)

add_dependencies(update update.ns.cmake)

NS_project_add_git_update_target(ns.cmake
  ${NS_CMAKE_INSTALL_DIR}/ns.cmake
)

set(NS_CMAKE_INSTALL_TARGET NS_CMAKE-install)

set(NS_CMAKE_EXTERNAL_PROJECTS
  ${NS_CMAKE_EXTERNAL_PROJECTS}
  NS_CMAKE
)
