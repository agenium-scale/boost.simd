//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/atanh.hpp>
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

STF_CASE_TPL (" atanh",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::atanh;
  using r_t =  decltype(atanh(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(atanh(bs::Inf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(atanh(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(atanh(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(atanh(bs::Mone<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(atanh(bs::One<T>()), bs::Inf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(atanh(bs::Zero<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(atanh(bs::Half<T>()), T(0.549306144334054845697622618461), 0.5);
  STF_ULP_EQUAL(atanh(bs::Mhalf<T>()), T(-0.549306144334054845697622618461), 0.5);
  STF_ULP_EQUAL(atanh(T(0.25)),  T(0.25541281188299536087), 0.5);
}


