//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/scalar/broadcast.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check broadcast behavior", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::broadcast;

  STF_EQUAL(broadcast<0 >(T(2)),  T(2));
  STF_EQUAL(broadcast<42>(T(2)),  T(0));
  STF_EQUAL(broadcast<-1>(T(2)),  T(0));
}
