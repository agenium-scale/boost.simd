##==================================================================================================
##                             Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_DOC)
NS_find_package(Git QUIET)
NS_find_package(Doxygen QUIET)

##==================================================================================================
## Setup the documentation
##==================================================================================================

if (NOT DOXYGEN_FOUND)
  NS_say("Doxygen not found; the 'doc' targets will be unavailable.")
  return()
endif()

if (NOT PROJECT_DOC_DIR)
  NS_say("PROJECT_DOC_DIR is not defined; the 'doc' targets will be unavailable.")
  return()
endif()

configure_file(${PROJECT_DOC_DIR}/Doxyfile.in ${PROJECT_DOC_DIR}/Doxyfile @ONLY)

add_custom_target(doc
  COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_DOC_DIR}/Doxyfile
  COMMENT "Generating API documentation with Doxygen"
  VERBATIM
)

if (NOT GIT_FOUND)
  NS_say(
    "Git was not found; the 'web.{clean,copy,update}' targets "
    "will be unavailable."
  )
  return()
endif()

add_custom_target(web.clean
  COMMAND ${CMAKE_COMMAND} -E remove *.png *.css *.js *.html
  COMMAND ${CMAKE_COMMAND} -E remove_directory search
  WORKING_DIRECTORY ${PROJECT_DOC_DIR}/html
  COMMENT "Cleaning up doc/html"
  VERBATIM
)

add_custom_target(web.copy
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/html ${PROJECT_DOC_DIR}/html
  WORKING_DIRECTORY ${PROJECT_DOC_DIR}/html
  COMMENT "Copying the documentation from ${CMAKE_CURRENT_BINARY_DIR}/html to ${PROJECT_DOC_DIR}/html"
  DEPENDS doc web.clean
  VERBATIM
)

execute_process(
  COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  OUTPUT_VARIABLE ${PROJECT_NAME}_GIT_SHORT_SHA
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_custom_target(web.update
  COMMAND ${GIT_EXECUTABLE} add .
  COMMAND ${GIT_EXECUTABLE} commit -m "Update to ${${PROJECT_NAME}_GIT_SHORT_SHA}"
  WORKING_DIRECTORY ${PROJECT_DOC_DIR}/html
  COMMENT "Updating the html branch with freshly built documentation"
  DEPENDS web.copy
  VERBATIM
)
