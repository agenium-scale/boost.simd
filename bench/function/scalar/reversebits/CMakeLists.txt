## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor reversebits in scalar mode.

set(SOURCES
  regular.int8_t.valmin_valmax.cpp
  regular.int16_t.valmin_valmax.cpp
)

make_bench("function.scalar.reversebits" ${SOURCES})

## --------------------------------------------------------------------------------------
