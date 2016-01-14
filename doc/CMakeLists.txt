#===================================================================================================
#                 Copyright 2012 - 2015   NumScale SAS
#
#                   Distributed under the Boost Software License, Version 1.0.
#                        See accompanying file LICENSE.txt or copy at
#                            http://www.boost.org/LICENSE_1_0.txt
#===================================================================================================

#===================================================================================================
# Setup doc target
#===================================================================================================
if (NOT DOXYGEN_FOUND)
  message(STATUS "Doxygen not found; the 'doc' target will be unavailable.")
  return()
endif()

configure_file(Doxyfile.in Doxyfile @ONLY)

add_custom_target ( doc COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
                        COMMENT "Generating API documentation with Doxygen"
                  #     DEPENDS benchmarks
                        VERBATIM
)
