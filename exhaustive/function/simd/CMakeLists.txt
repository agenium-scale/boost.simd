## -------------------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------

set(SOURCES
  exp.cpp
  exp10.cpp
  exp2.cpp
  expm1.cpp
#   expx2.cpp
  log.cpp
  log1p.cpp
#   log10.cpp
#   log2.cpp
#   nthroot.cpp
#   pow.cpp
#   sqrt1pm1.cpp
 )

make_exhaustive("function.simd" ${SOURCES})

















