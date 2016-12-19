//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/atan2pi.hpp>
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

STF_CASE_TPL (" atan2pi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::atan2pi;

  using r_t = decltype(bs::pedantic_(atan2pi)(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Inf<T>(), bs::Inf<T>()), T(0.25), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Inf<T>(),bs::One<T>()), T(0.5), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Minf<T>(), bs::Minf<T>()), -T(3.0/4.0), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Minf<T>(),bs::One<T>()), -T(0.5), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Nan<T>(), bs::Zero<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Zero<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::One<T>(),bs::Inf<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::One<T>(),bs::Minf<T>()), T(1.0), 0.5);
#endif
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Half<T>(), bs::Half<T>()), T(0.25), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Mhalf<T>(), bs::Mhalf<T>()), -T(3.0/4.0), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Mone<T>(), bs::Mone<T>()), -T(3.0/4.0), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::One<T>(), bs::One<T>()), T(0.25), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(atan2pi)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
}
