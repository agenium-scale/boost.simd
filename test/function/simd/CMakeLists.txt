##===================================================================================================
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  aligned_load.cpp
  extract.cpp
  insert.cpp
  load.cpp
  splat.cpp
)

make_unit( "boost.simd.function.simd"   ${SOURCES})
make_coverage("boost.simd.function.simd"  ${SOURCES})
