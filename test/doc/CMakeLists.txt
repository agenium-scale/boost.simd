##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================
SET( SOURCES
    reduce.simple.cpp
    reduce.phases.cpp
    reduce.phase.cpp
    transform.unary.cpp
    transform.binary.cpp
  )

make_unit( "doc" ${SOURCES})
