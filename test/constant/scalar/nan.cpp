//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/nan.hpp>
#include <limits>
#include <stf.hpp>

STF_CASE_TPL( "Check plus behavior with floating", (double)(float) )
{
  using boost::simd::nan;
  using boost::simd::NaN;

  STF_IEEE_EQUAL( NaN<T>(), std::numeric_limits<T>::quiet_NaN());
  STF_IEEE_EQUAL( NaN<int>(), 0);
}
