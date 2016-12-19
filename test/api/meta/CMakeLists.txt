##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      as_arithmetic.cpp
      as_logical.cpp
      cardinal_of.cpp
      is_pointing_to.cpp
      is_scalar.cpp
      real_of.cpp
      upgrade.cpp
    )

make_unit( "api.meta" ${SOURCES})
make_coverage("api.meta" ${SOURCES})
