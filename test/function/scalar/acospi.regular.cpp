//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acospi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>


STF_CASE_TPL (" acospi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acospi;

  using r_t = decltype(acospi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(acospi(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(acospi(bs::Half<T>()), T(1)/3, 0.5);
  STF_ULP_EQUAL(acospi(bs::Mhalf<T>()), T(2)/3, 0.5);
  STF_ULP_EQUAL(acospi(bs::Mone<T>()), 1, 0.5);
  STF_ULP_EQUAL(acospi(bs::One<T>()), 0, 0.5);
  STF_ULP_EQUAL(acospi(bs::Zero<T>()), 0.5, 0.5);
}


