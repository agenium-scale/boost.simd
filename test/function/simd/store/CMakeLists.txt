##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  pointer.arithmetic.cpp
  pointer.logical.cpp
##  range.arithmetic.cpp
 ## range.logical.cpp
  scatter.arithmetic.cpp
  scatter.logical.cpp
  mask.arithmetic.cpp
 ## mask.logical.cpp
)

make_unit( "function.simd.store"   ${SOURCES})
make_coverage("function.simd.store"  ${SOURCES})
