## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor nthroot in scalar mode.

set(SOURCES
  regular.float.2.cpp
  regular.double.2.cpp
  raw.float.2.cpp
  raw.double.2.cpp
)

make_bench("function.scalar.nthroot" ${SOURCES})

## --------------------------------------------------------------------------------------
