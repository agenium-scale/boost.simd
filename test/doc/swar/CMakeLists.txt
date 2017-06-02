##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    fmasubadd.cpp
    lookup.cpp
    shuffle.unary.cpp
    shuffle.binary.cpp
    shuffle.perm.cpp
    shuffle.perm2.cpp
    subadd.cpp
  )

make_unit( "doc.swar" ${SOURCES})
