## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor erf in std mode.

set(SOURCES
  float.m6_6.cpp
  double.m6_6.cpp
)

make_bench("function.std.erf" ${SOURCES})

## --------------------------------------------------------------------------------------
