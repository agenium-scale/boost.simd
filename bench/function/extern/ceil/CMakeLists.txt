## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor ceil in extern mode.

set(SOURCES
  std.float.m10_10.cpp
  std.double.m10_10.cpp
)

make_bench("function.extern.ceil" ${SOURCES})

## --------------------------------------------------------------------------------------
