##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      is_aligned.cpp
      preferred_alignment.cpp
    )

make_unit( "api.memory" ${SOURCES})
make_coverage("api.memory" ${SOURCES})
