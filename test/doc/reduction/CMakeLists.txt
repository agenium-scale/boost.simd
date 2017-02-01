##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    all.cpp
    any.cpp
    compare_equal.cpp
    compare_greater_equal.cpp
    compare_greater.cpp
    compare_less_equal.cpp
    compare_less.cpp
    compare_not_equal.cpp
    cummax.cpp
    cummin.cpp
    cumprod.cpp
    cumsum.cpp
    dot.cpp
    hmsb.cpp
    isincluded_c.cpp
    isincluded.cpp
    maximum.cpp
    minimum.cpp
    nbtrue.cpp
    none.cpp
    prod.cpp
    sum.cpp
  )

make_unit( "doc.reduction" ${SOURCES})
