##==================================================================================================
##                 Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_PARSE_REVISION)

##==================================================================================================
## Parse revision number in variables
##==================================================================================================
function(parse_revision version_string prefix)
  set(version_regex_release ".*([0-9]+)\\.([0-9]+)\\.([0-9]+)$")
  set(version_regex_prerelease ".*([0-9]+)\\.([0-9]+)[\\.-]([0-9]+)-([0-9A-Za-z.-]+)$")

  if ("${version_string}" MATCHES ${version_regex_release})
    set(version_regex ${version_regex_release})
  elseif ("${version_string}" MATCHES ${version_regex_prerelease})
    set(version_regex ${version_regex_prerelease})
  else()
    NS_error("Unknown version format")
    return()
  endif()

  string(REGEX REPLACE ${version_regex} "\\1" ${prefix}_MAJOR "${version_string}")
  string(REGEX REPLACE ${version_regex} "\\2" ${prefix}_MINOR "${version_string}")
  string(REGEX REPLACE ${version_regex} "\\3" ${prefix}_PATCH "${version_string}")

  set(${version_name}_IS_PRERELEASE 0)

  if ("${version_string}" MATCHES ${version_regex_prerelease})
    string(REGEX REPLACE ${version_regex} "\\4" ${prefix}_PRERELEASE "${version_string}")
    set(${prefix}_IS_PRERELEASE 1)
  endif()

  math(EXPR ${prefix} "${${prefix}_MAJOR} * 10000 + ${${prefix}_MINOR} * 100 + ${${prefix}_PATCH}")

  foreach(ARG "" _MAJOR _MINOR _PATCH _PRERELEASE _IS_PRERELEASE)
    set(${prefix}${ARG} ${${prefix}${ARG}} PARENT_SCOPE)
  endforeach()

endfunction()

##==================================================================================================
## Setup revision ID
##==================================================================================================
if (GIT_EXECUTABLE AND NOT EXISTS GIT_EXECUTABLE)
  unset(GIT_EXECUTABLE CACHE)
endif()

NS_find_package(Git QUIET)
if (GIT_EXECUTABLE)
  execute_process(COMMAND ${GIT_EXECUTABLE} fetch --tags
                  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                 )
  execute_process(COMMAND ${GIT_EXECUTABLE} describe --tags
                  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                  OUTPUT_VARIABLE PROJECT_VERSION_STRING
                  OUTPUT_STRIP_TRAILING_WHITESPACE

                  ERROR_VARIABLE GIT_TAG_IS_AVAILABLE
                 )
endif()

if (NOT PROJECT_VERSION_STRING OR NOT "${GIT_TAG_IS_AVAILABLE}" STREQUAL "")
  set(PROJECT_VERSION_STRING "0.0.0-alpha")
endif()

parse_revision("${PROJECT_VERSION_STRING}" PROJECT_VERSION)

NS_say("Project version is ${PROJECT_VERSION}")

set(PROJECT_RELEASE "(release)")
if (PROJECT_VERSION_IS_PRERELEASE)
  set(PROJECT_RELEASE "(pre-release)")
endif()

NS_say("Configuring project version ${PROJECT_VERSION_STRING} ${PROJECT_RELEASE}")
