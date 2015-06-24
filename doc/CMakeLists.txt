##==================================================================================================
##                 Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
##                 Copyright 2009 - 2015   LRI    UMR 8623 CNRS/Univ Paris Sud XI
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

##==================================================================================================
## Setup the documentation
##==================================================================================================
if (NOT DOXYGEN_FOUND)
    message(STATUS
    "[boost.simd] Doxygen not found; the 'doc'targets will be unavailable.")
    return()
endif()

configure_file(Doxyfile.in Doxyfile @ONLY)

add_custom_target(doc
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
)

if (NOT GIT_FOUND)
    message(STATUS
    "[boost.simd] Git was not found; the 'web.{clean,copy,update}' targets "
    "will be unavailable.")
    return()
endif()

add_custom_target(web.clean
    COMMAND ${CMAKE_COMMAND} -E remove *.png *.css *.js *.html
    COMMAND ${CMAKE_COMMAND} -E remove_directory search
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/html
    COMMENT "Cleaning up doc/html"
    VERBATIM
)

add_custom_target(web.copy
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/html ${CMAKE_CURRENT_LIST_DIR}/html
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/html
    COMMENT "Copying the documentation from ${CMAKE_CURRENT_BINARY_DIR}/html to doc/html"
    DEPENDS doc web.clean
    VERBATIM
)

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE BOOST_SIMD_GIT_SHORT_SHA
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_custom_target(web.update
    COMMAND ${GIT_EXECUTABLE} add .
    COMMAND ${GIT_EXECUTABLE} commit -m "Update to ${BOOST_SIMD_GIT_SHORT_SHA}"
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/html
    COMMENT "Updating the html branch with freshly built documentation"
    DEPENDS web.copy
    VERBATIM
)
