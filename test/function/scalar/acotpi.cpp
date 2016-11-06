//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acotpi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/function/rec.hpp>


STF_CASE_TPL (" acotpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acotpi;

  using r_t = decltype(acotpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(acotpi(bs::Inf<T>()), 0, 0);
  STF_ULP_EQUAL(acotpi(bs::Minf<T>()), 0, 0);
  STF_ULP_EQUAL(acotpi(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(acotpi(bs::Half<T>()), T(0.352416382349567), 2.5);
  STF_ULP_EQUAL(acotpi(bs::Mhalf<T>()), T(-0.352416382349567), 2.5);
  STF_ULP_EQUAL(acotpi(bs::Mone<T>()), T(-0.25), 0);
  STF_ULP_EQUAL(acotpi(bs::One<T>()), T(0.25), 0);
  STF_ULP_EQUAL(acotpi(bs::Zero<T>()), T(0.5), 0);
}
