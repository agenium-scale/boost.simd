##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      tags.cpp
      limits.cpp
      is_iterator.cpp
      has_native_storage.cpp
    )

make_unit( "architecture" ${SOURCES})
make_coverage("architecture" ${SOURCES})
