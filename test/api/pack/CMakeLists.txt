##===================================================================================================
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

add_definitions(-DBOOST_ENABLE_ASSERT_HANDLER)

set ( SOURCES
      concepts.cpp
      hierarchy.cpp
      iterators.cpp
      proxy.cpp
    )

make_unit( "boost.simd.api.pack" ${SOURCES})
make_coverage("boost.simd.api.pack" ${SOURCES})

add_subdirectory(ctor)
