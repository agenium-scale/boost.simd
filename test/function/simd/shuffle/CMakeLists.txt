##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  cardinal.1.cpp
  cardinal.2.unary.cpp
  cardinal.2.binary.cpp
  cardinal.4.avx.shuffle.cpp
  cardinal.8.avx.shuffle.cpp
  cardinal.4.avx.blend.cpp
  cardinal.8.avx.blend.unary.cpp
  cardinal.4.avx.perm2.cpp
  broadcast.binary.cpp
  broadcast.unary.cpp
  deinterleave.full.cpp
  deinterleave.front.cpp
  deinterleave.back.cpp
  interleave.even.cpp
  interleave.first.cpp
  interleave.odd.cpp
  interleave.second.cpp
  identity.cpp
  repeat.cpp
  reverse.cpp
  slide.cpp
)

make_unit( "function.simd.shuffle"   ${SOURCES})
make_coverage("function.simd.shuffle"  ${SOURCES})
