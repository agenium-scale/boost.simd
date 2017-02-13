##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      issue_18.cpp
      issue_21.cpp
      pythran.cpp
      issue_440.cpp
    )

make_unit( "regression" ${SOURCES})
make_coverage("regression" ${SOURCES})
