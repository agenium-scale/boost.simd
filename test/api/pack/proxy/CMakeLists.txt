##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      cast.cpp
      comparison.cpp
      divides.cpp
      minus.cpp
      multiplies.cpp
      not.cpp
      plus.cpp
    )

make_unit( "api.pack.proxy" ${SOURCES})
make_coverage("api.pack.proxy" ${SOURCES})
