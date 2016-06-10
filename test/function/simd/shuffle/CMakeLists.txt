##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  cardinal_1.cpp
  cardinal_2.cpp
  broadcast.binary.cpp
  broadcast.unary.cpp
  deinterleave.full.cpp
  deinterleave.front.cpp
  deinterleave.back.cpp
  identity.cpp
  repeat.cpp
  reverse.cpp
  slide.cpp
)

make_unit( "function.simd.shuffle"   ${SOURCES})
make_coverage("function.simd.shuffle"  ${SOURCES})
