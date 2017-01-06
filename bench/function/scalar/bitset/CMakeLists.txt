## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor bitset in scalar mode.

set(SOURCES
  regular.float..cpp
  regular.double..cpp
)

make_bench("function.scalar.bitset" ${SOURCES})

## --------------------------------------------------------------------------------------
