//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/asind.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" asind",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::asind;

  using r_t = decltype(asind(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(asind(bs::Inf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(asind(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(asind(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(asind(bs::Half<T>()), T(30), 0.5);
  STF_ULP_EQUAL(asind(bs::Mhalf<T>()), T(-30), 0.5);
  STF_ULP_EQUAL(asind(bs::Mone<T>()), T(-90), 0.5);
  STF_ULP_EQUAL(asind(bs::One<T>()), T(90), 0.5);
  STF_ULP_EQUAL(asind(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
}

