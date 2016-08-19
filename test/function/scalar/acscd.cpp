//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acscd.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" acscd",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acscd;

  using r_t = decltype(acscd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(acscd(bs::Inf<T>()), T(0), 0.5);
  STF_ULP_EQUAL(acscd(bs::Minf<T>()), T(0), 0.5);
  STF_ULP_EQUAL(acscd(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(acscd(bs::Zero<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(acscd(-bs::Two<T>()), T(-30), 0.5);
  STF_ULP_EQUAL(acscd(bs::Mone<T>()), T(-90), 0.5);
  STF_ULP_EQUAL(acscd(bs::One<T>()),  T(90), 0.5);
  STF_ULP_EQUAL(acscd(bs::Two<T>()),  T(30), 0.5);
}
