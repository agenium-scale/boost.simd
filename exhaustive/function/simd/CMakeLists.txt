## -------------------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------

set(SOURCES
  acos.cpp
  acos.accurate.cpp
  asin.cpp
  atan.cpp
  erf.cpp
  exp.cpp
  exp10.cpp
  exp2.cpp
  expm1.cpp
  fast_acos.cpp
  log.cpp
  log1p.cpp
  log10.cpp
  log2.cpp
  nthroot.cpp
 )

make_exhaustive("function.simd" ${SOURCES})

















