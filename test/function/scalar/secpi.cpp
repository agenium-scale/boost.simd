//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/secpi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>

STF_CASE_TPL (" secpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::secpi;

  using r_t = decltype(secpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(secpi(bs::Half<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secpi(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secpi(bs::Mhalf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secpi(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secpi(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(secpi(-bs::Quarter<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(secpi(bs::One<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(secpi(bs::Quarter<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(secpi(bs::Zero<T>()), bs::One<r_t>(), 0.5);
}
