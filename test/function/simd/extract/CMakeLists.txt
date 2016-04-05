##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  dynamic.arithmetic.cpp
  dynamic.logical.cpp
  static.arithmetic.cpp
  static.logical.cpp
)

make_unit( "boost.simd.function.simd.extract"   ${SOURCES})
make_coverage("boost.simd.function.simd.extract"  ${SOURCES})
