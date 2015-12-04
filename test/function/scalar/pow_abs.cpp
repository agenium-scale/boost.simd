//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/pow_abs.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/eight.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/constant/half.hpp>

STF_CASE_TPL (" pow_abs",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow_abs;

  using r_t = decltype(pow_abs(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(pow_abs(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(bs::Inf<T>(), bs::Half<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(bs::Inf<T>(), bs::Mhalf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(bs::Inf<T>(), bs::Zero<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(bs::Two<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(bs::Half<T>(), bs::Inf<T>()), bs::Zero<r_t>(), 0);
#endif
  STF_ULP_EQUAL(pow_abs(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(bs::One<T>(), bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(bs::Zero<T>(), bs::Zero<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow_abs(T(-1),T(5)), T(1), 0);
  STF_ULP_EQUAL(pow_abs(T(-1),T(6)), T(1), 0);
}


