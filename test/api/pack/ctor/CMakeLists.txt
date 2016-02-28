##===================================================================================================
##                               Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      list.cpp
      default.cpp
      pointer.cpp
      iterator.cpp
      splat.cpp
    )

make_unit( "boost.simd.api.pack.ctor" ${SOURCES})
make_coverage("boost.simd.api.pack.ctor" ${SOURCES})
