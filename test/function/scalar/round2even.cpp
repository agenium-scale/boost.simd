//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/round2even.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>

STF_CASE_TPL ( "round2even real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::round2even;
  using r_t = decltype(round2even(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_ULP_EQUAL(round2even(T(1.4)), 1, 0);
  STF_ULP_EQUAL(round2even(T(1.5)), 2, 0);
  STF_ULP_EQUAL(round2even(T(1.6)), 2, 0);
  STF_ULP_EQUAL(round2even(T(2.5)), 2, 0);
  STF_ULP_EQUAL(round2even(bs::Half<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::Mhalf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::Minf<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::Mone<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::Zero<T>()), bs::Zero<r_t>(), 0);
} // end of test for floating_

STF_CASE_TPL (" round2evenunsigned_int__1_0",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::round2even;
  using r_t = decltype(round2even(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_ULP_EQUAL(round2even(bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::Zero<T>()), bs::Zero<r_t>(), 0);
} // end of test for unsigned_int_

STF_CASE_TPL (" round2evensigned_ int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::round2even;
  using r_t = decltype(round2even(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_ULP_EQUAL(round2even(bs::Mone<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(round2even(bs::Zero<T>()), bs::Zero<T>(), 0);
} // end of test for signed_int_
