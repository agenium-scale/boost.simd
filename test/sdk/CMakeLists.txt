##===================================================================================================
##                               Copyright 2015 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      as_arithmetic.cpp
      as_logical.cpp
      masked.cpp
      real_of.cpp
    )

make_unit( "boost.simd.sdk" ${SOURCES})
make_coverage("boost.simd.sdk" ${SOURCES})
