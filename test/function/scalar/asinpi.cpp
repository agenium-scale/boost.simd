//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/asinpi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>


STF_CASE_TPL (" asinpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::asinpi;

  using r_t = decltype(asinpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(asinpi(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(asinpi(bs::Half<T>()), T(1)/6, 0.5);
  STF_ULP_EQUAL(asinpi(bs::Mhalf<T>()), -T(1)/6, 0.5);
  STF_ULP_EQUAL(asinpi(bs::Mone<T>()), -0.5, 0.5);
  STF_ULP_EQUAL(asinpi(bs::One<T>()), 0.5, 0.5);
  STF_ULP_EQUAL(asinpi(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
}
