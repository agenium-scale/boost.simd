##===================================================================================================
##                 Copyright 2009 - 2015   LRI    UMR 8623 CNRS/Univ Paris Sud XI
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

add_definitions(-DBOOST_ENABLE_ASSERT_HANDLER)

set ( SOURCES
  abs.cpp
  divides.cpp
#  is_equal.cpp
  minus.cpp
  modulus.cpp
  multiplies.cpp
  plus.cpp
  )

make_unit( "boost.simd.function.scalar"     ${SOURCES})
make_coverage("boost.simd.function.scalar"  ${SOURCES})
