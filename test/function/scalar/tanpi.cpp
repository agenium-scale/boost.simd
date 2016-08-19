//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/tanpi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/constant/quarter.hpp>

STF_CASE_TPL (" tanpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tanpi;

  using r_t = decltype(tanpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(tanpi(bs::Half<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(tanpi(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(tanpi(bs::Mhalf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(tanpi(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(tanpi(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(tanpi(-bs::Quarter<T>()), bs::Mone<r_t>(), 1.0);
  STF_ULP_EQUAL(tanpi(bs::Mone<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(tanpi(bs::One<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(tanpi(bs::Quarter<T>()), bs::One<r_t>(), 1.0);
  STF_ULP_EQUAL(tanpi(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
}
