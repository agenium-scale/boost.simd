##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
   rem.regular.cpp
   rem.ceil.cpp
   rem.floor.cpp
   rem.nearbyint.cpp
   rem.round.cpp
)

make_unit( "function.scalar.rem"   ${SOURCES})
make_coverage("function.scalar.rem"  ${SOURCES})
