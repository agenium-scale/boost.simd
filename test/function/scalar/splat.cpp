//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/splat.hpp>
#include <scalar_test.hpp>
#include <boost/simd/as.hpp>


STF_CASE_TPL( "Check splat behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::splat;

  STF_EQUAL(splat<T>(1),  T(1));
}

