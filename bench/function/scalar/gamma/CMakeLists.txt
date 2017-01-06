## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor gamma in scalar mode.

set(SOURCES
  regular.float.0.0_35.0.cpp
  regular.double.0.0_35.0.cpp
)

make_bench("function.scalar.gamma" ${SOURCES})

## --------------------------------------------------------------------------------------
