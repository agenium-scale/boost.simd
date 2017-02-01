//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ifnot_neg.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" ifnot_neg real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::ifnot_neg;
  using bs::logical;
  using r_t = decltype(ifnot_neg(logical<T>(),T()));
  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(ifnot_neg(logical<T>(T(0)),T(1)), -1);
  STF_EQUAL(ifnot_neg(logical<T>(T(1)),T(1)), 1);
  STF_EQUAL(ifnot_neg(logical<T>(bs::Inf<T>()),T(1)), 1);
  STF_EQUAL(ifnot_neg(logical<T>(bs::Minf<T>()),T(1)), 1);
  STF_IEEE_EQUAL(ifnot_neg(logical<T>(bs::Nan<T>()),T(1)), 1);
  STF_EQUAL(ifnot_neg(logical<T>(bs::Zero<T>()),T(1)), -1);
} // end of test for floating_

STF_CASE_TPL (" ifnot_neg signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnot_neg;
  using bs::logical;
  using r_t = decltype(ifnot_neg(logical<T>(),T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(ifnot_neg(logical<T>(T(0)),T(1)), -1);
  STF_EQUAL(ifnot_neg(logical<T>(T(1)),T(1)), 1);
} // end of test for signed_int_
