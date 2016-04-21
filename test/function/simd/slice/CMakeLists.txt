##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  arithmetic.cpp
  arithmetic.high.cpp
  arithmetic.low.cpp
  logical.cpp
  logical.high.cpp
  logical.low.cpp
)

make_unit( "function.simd.slice"   ${SOURCES})
make_coverage("function.simd.slice"  ${SOURCES})
