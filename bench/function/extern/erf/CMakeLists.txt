## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor erf in extern mode.

set(SOURCES
  std.float.m6_6.cpp
  std.double.m6_6.cpp
)

make_bench("function.extern.erf" ${SOURCES})

## --------------------------------------------------------------------------------------
