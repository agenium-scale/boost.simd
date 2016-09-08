##==================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

set ( SOURCES
      logical.cpp
      mask.cpp
    )

make_unit( "api.helper" ${SOURCES})
make_coverage("api.helper" ${SOURCES})
