//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/maximum.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" splatted_maximum ",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;

  using bs::maximum;

  // return type conformity test
  STF_EXPR_IS(bs::splatted_(bs::maximum)(T()), T);

  // specific values tests
   STF_EQUAL(bs::splatted_(bs::maximum)(bs::One<T>()), bs::One<T>());
   STF_EQUAL(bs::splatted_(bs::maximum)(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_


