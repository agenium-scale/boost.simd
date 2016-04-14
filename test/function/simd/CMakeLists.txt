##===================================================================================================
##                               Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

## Larger test suites go there
add_subdirectory(extract)
add_subdirectory(genmask)
add_subdirectory(insert)
add_subdirectory(load)
add_subdirectory(make)
add_subdirectory(splat)

set ( SOURCES
  aligned_load.cpp
  aligned_store.cpp
  bitwise_cast.cpp
  enumerate.cpp
  store.cpp
  automap.cpp
  autofold.cpp
  autosplat.cpp
)

make_unit( "boost.simd.function.simd"   ${SOURCES})
make_coverage("boost.simd.function.simd"  ${SOURCES})
