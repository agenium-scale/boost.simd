##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    direct_trigonometric.cpp
    inverse_trigonometric.cpp
    acos.cpp
    acosd.cpp
    acospi.cpp
    acot.cpp
    acotd.cpp
    acotpi.cpp
    acscd.cpp
    acscpi.cpp
    acsc.cpp
    asecd.cpp
    asecpi.cpp
    asec.cpp
    asin.cpp
    asind.cpp
    asinpi.cpp
    atan2.cpp
    atan2d.cpp
    atan2pi.cpp
    atan.cpp
    atand.cpp
    atanpi.cpp
    cos.cpp
    cosd.cpp
    cospi.cpp
    cot.cpp
    cotd.cpp
    cotpi.cpp
    cscd.cpp
    csc.cpp
    cscpi.cpp
    indeg.cpp
    inrad.cpp
    rem_2pi.cpp
    rem_pio2_cephes.cpp
    rem_pio2.cpp
    rem_pio2_medium.cpp
    rem_pio2_straight.cpp
    sec.cpp
    secd.cpp
    secpi.cpp
    sinc.cpp
    sincosd.cpp
    sincos.cpp
    sincospi.cpp
    sincpi.cpp
    sin.cpp
    sind.cpp
    sinpi.cpp
    tan.cpp
    tand.cpp
    tanpi.cpp
  )

make_unit( "doc.trigonometric" ${SOURCES})
