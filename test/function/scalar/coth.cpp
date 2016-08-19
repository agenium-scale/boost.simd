//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/coth.hpp>
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

STF_CASE_TPL (" coth",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::coth;
  using r_t = decltype(coth(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(coth(bs::Inf<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(coth(bs::Minf<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(coth(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(coth(bs::Mzero<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(coth(bs::Zero<T>()), bs::Inf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(coth(bs::Mhalf<T>()), T(-2.16395341373865284877000401022), 0);
  STF_ULP_EQUAL(coth(bs::Half<T>()), T(2.16395341373865284877000401022), 0);
}
