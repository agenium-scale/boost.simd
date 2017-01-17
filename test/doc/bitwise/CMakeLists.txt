##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    bits.cpp
    bitwise_and.cpp
    bitwise_andnot.cpp
    bitwise_cast.cpp
    bitwise_not.cpp
    bitwise_notand.cpp
    bitwise_notor.cpp
    bitwise_or.cpp
    bitwise_ornot.cpp
    bitwise_select.cpp
    bitwise_xor.cpp
    clz.cpp
    complement.cpp
    ctz.cpp
    ffs.cpp
    firstbitset.cpp
    firstbitunset.cpp
    genmask.cpp
    genmaskc.cpp
    hi.cpp
    ilog2.cpp
    lo.cpp
    popcnt.cpp
    reversebits.cpp
    rol.cpp
    ror.cpp
    rrol.cpp
    rror.cpp
    rshl.cpp
    rshr.cpp
    shift_left.cpp
    shift_right.cpp
    shl.cpp
    shr.cpp
    sbits.cpp
    swapbytes.cpp
    twopower.cpp
  )

make_unit( "doc.bitwise" ${SOURCES})
