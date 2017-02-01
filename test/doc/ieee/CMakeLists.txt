##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    bitfloating.cpp
    bitinteger.cpp
    bitofsign.cpp
    copysign.cpp
    eps.cpp
    exponentbits.cpp
    exponent.cpp
    fpclassify.cpp
    frac.cpp
    frexp.cpp
    ifrexp.cpp
    ilogb.cpp
    ldexp.cpp
    mantissa.cpp
    maxmag.cpp
    maxnum.cpp
    maxnummag.cpp
    minmag.cpp
    minnum.cpp
    minnummag.cpp
    modf.cpp
    negate.cpp
    negatenz.cpp
    nextafter.cpp
    next.cpp
    nextpow2.cpp
    predecessor.cpp
    prev.cpp
    safe_max.cpp
    safe_min.cpp
    saturate.cpp
    sbits.cpp
    sign.cpp
    signnz.cpp
    successor.cpp
    ulpdist.cpp
    ulp.cpp
   )
make_unit( "doc.ieee" ${SOURCES})
