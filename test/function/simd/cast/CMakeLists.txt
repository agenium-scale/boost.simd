##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  float.cpp
  double.cpp
  int64.cpp
  int32.cpp
  int16.cpp
  int8.cpp
  uint64.cpp
  uint32.cpp
  uint16.cpp
  uint8.cpp
  type_check.cpp
)

make_unit( "function.simd.cast"   ${SOURCES})
make_coverage("function.simd.cast"  ${SOURCES})
