//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sqrt.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>


STF_CASE_TPL (" sqrt std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrt;
  using r_t = decltype(bs::std_(sqrt)(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::std_(sqrt)(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(sqrt)(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(sqrt)(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(bs::std_(sqrt)(bs::Mone<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(sqrt)(bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(sqrt)(bs::Two<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::std_(sqrt)(bs::Zero<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(sqrt)(bs::Mzero<T>()), bs::Mzero<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(sqrt)(bs::Four<T>()), bs::Two<r_t>(), 0);
/*
  STF_EXPECT(bs::is_negative(sqrt(bs::Mzero<T>())));
  STF_EXPECT(bs::is_positive(sqrt(bs::Zero<T>())));
*/
} // end of test for floating_
