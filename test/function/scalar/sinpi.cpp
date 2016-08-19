//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sinpi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>

STF_CASE_TPL (" sinpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sinpi;

  using r_t = decltype(sinpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sinpi(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sinpi(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sinpi(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(sinpi(-bs::Quarter<T>()), -bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sinpi(bs::Half<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(sinpi(bs::Mhalf<T>()), -bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(sinpi(bs::One<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(sinpi(bs::Quarter<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sinpi(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
}
