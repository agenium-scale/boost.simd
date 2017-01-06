## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor ldexp in scalar mode.

set(SOURCES
  regular.float.N.cpp
  regular.double.N.cpp
  pedantic.float.N.cpp
  pedantic.double.N.cpp
)

make_bench("function.scalar.ldexp" ${SOURCES})

## --------------------------------------------------------------------------------------
