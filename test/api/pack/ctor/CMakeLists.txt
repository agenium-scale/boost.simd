##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      array.cpp
      list.cpp
      default.cpp
      pointer.cpp
      iterator.cpp
      rebind.cpp
      splat.cpp
    )

make_unit( "api.pack.ctor" ${SOURCES})
make_coverage("api.pack.ctor" ${SOURCES})
