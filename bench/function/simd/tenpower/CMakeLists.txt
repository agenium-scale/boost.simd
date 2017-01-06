## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor tenpower in simd mode.

set(SOURCES
  regular.float.0_10.cpp
  regular.double.0_10.cpp
)

make_bench("function.simd.tenpower" ${SOURCES})

## --------------------------------------------------------------------------------------
