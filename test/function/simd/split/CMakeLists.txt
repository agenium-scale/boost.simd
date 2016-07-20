##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  arithmetic.low.cpp
  arithmetic.high.cpp
  arithmetic.pair.cpp
  logical.low.cpp
  logical.high.cpp
  logical.pair.cpp
)

make_unit( "function.simd.split"   ${SOURCES})
make_coverage("function.simd.split"  ${SOURCES})
