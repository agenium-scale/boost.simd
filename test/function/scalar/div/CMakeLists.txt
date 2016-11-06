##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
   div.regular.cpp
   div.ceil.cpp
   div.fix.cpp
   div.floor.cpp
   div.nearbyint.cpp
   div.round.cpp
   div.iceil.cpp
   div.ifix.cpp
   div.ifloor.cpp
   div.inearbyint.cpp
   div.iround.cpp
)

make_unit( "function.scalar.div"   ${SOURCES})
make_coverage("function.scalar.div"  ${SOURCES})
