//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/rsqrt.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/sqrt_2.hpp>

STF_CASE_TPL (" rsqrt regular",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rsqrt;
  using r_t = decltype(rsqrt(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(rsqrt(bs::Inf<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(rsqrt(bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(rsqrt(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_IEEE_EQUAL(rsqrt(bs::Mone<T>()), bs::Nan<r_t>());
  STF_ULP_EQUAL(rsqrt(bs::One<T>()), bs::One<r_t>(), 0.5);
  STF_EQUAL(rsqrt(bs::Zero<T>()), bs::Inf<r_t>());
  STF_ULP_EQUAL(rsqrt(bs::Four<T>()), bs::Half<r_t>(), 0.5);
  STF_ULP_EQUAL(rsqrt(T(0.5)), bs::Sqrt_2<T>(), 0.5);
  STF_ULP_EQUAL(rsqrt(T(0.01)), T(10), 0.5);
  STF_ULP_EQUAL(rsqrt(T(0.0001)), T(100), 0.5);
} // end of test for floating_
