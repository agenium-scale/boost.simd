##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    cbrt.cpp
    exp.cpp
    exp10.cpp
    exp2.cpp
    expm1.cpp
    exprecneg.cpp
    exprecnegc.cpp
    expx2.cpp
    log.cpp
    log10.cpp
    log1p.cpp
    log2.cpp
    nthroot.cpp
    pow.cpp
    pow2.cpp
    pow_abs.cpp
    significants.cpp
   )

make_unit( "doc.exponential" ${SOURCES})
