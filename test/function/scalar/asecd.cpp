//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/asecd.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" asecd",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::asecd;

  using r_t = decltype(asecd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(asecd(bs::Inf<T>()), 90, 0.5);
  STF_ULP_EQUAL(asecd(bs::Minf<T>()), 90, 0.5);
  STF_IEEE_EQUAL(asecd(bs::Nan<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(asecd(bs::Zero<T>()), bs::Nan<r_t>());
#endif

  STF_ULP_EQUAL(asecd(-bs::Two<T>()), T(120), 0.5);
  STF_ULP_EQUAL(asecd(bs::Mone<T>()), T(180), 0.5);
  STF_ULP_EQUAL(asecd(bs::One<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(asecd(bs::Two<T>()), T(60), 0.5);
}


