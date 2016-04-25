##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  unary.arithmetic.cpp
  unary.logical.cpp
  binary.arithmetic.cpp
  binary.logical.cpp
)

make_unit( "function.simd.slide"   ${SOURCES})
make_coverage("function.simd.slide"  ${SOURCES})
