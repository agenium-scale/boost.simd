##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
## examples for arithmetic.cpp
    saturated_abs.cpp
    roundings.cpp
    divisions.cpp
    remainders.cpp
## examples for individual functors
    abs.cpp
    arg.cpp
    average.cpp
    ceil.cpp
    clamp.cpp
    dec.cpp
    dist.cpp
    div.cpp
    divides.cpp
    fix.cpp
    floor.cpp
    fma.cpp
    fms.cpp
    fnma.cpp
    fnms.cpp
    hypot.cpp
    iceil.cpp
    ifix.cpp
    ifloor.cpp
    inc.cpp
    inearbyint.cpp
    iround.cpp
    max.cpp
    meanof.cpp
    min.cpp
    minus.cpp
    minmod.cpp
    multiplies.cpp
    nearbyint.cpp
    oneminus.cpp
    plus.cpp
    quadrant.cpp
    rec.cpp
    rem.cpp
    remquo.cpp
    round.cpp
    rsqrt.cpp
    signbit.cpp
    sqr_abs.cpp
    sqr.cpp
    sqrt1pm1.cpp
    sqrt.cpp
    tenpower.cpp
    tofloat.cpp
    toint.cpp
    touint.cpp
    trunc.cpp
    two_add.cpp
    two_prod.cpp
    two_split.cpp
    unary_minus.cpp
    unary_plus.cpp
  )

make_unit( "doc.arithmetic" ${SOURCES})
