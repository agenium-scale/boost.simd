##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

add_subdirectory(ctor)
add_subdirectory(proxy)

set ( SOURCES
      concepts.cpp
      hierarchy.cpp
      iterators.cpp
      assignment.cpp
    )

make_unit( "api.pack" ${SOURCES})
make_coverage("api.pack" ${SOURCES})
