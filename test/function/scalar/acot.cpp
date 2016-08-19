//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acot.hpp>
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


STF_CASE_TPL (" acot",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acot;

  using r_t = decltype(acot(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(acot(bs::Inf<T>()), 0, 1.5);
  STF_ULP_EQUAL(acot(bs::Minf<T>()), 0, 1.5);
  STF_ULP_EQUAL(acot(bs::Nan<T>()), bs::Nan<r_t>(), 1.5);
#endif
  STF_ULP_EQUAL(acot(bs::Half<T>()), T(1.107148717794090e+00), 1.5);
  STF_ULP_EQUAL(acot(bs::Mhalf<T>()), T(-1.107148717794090e+00), 1.5);
  STF_ULP_EQUAL(acot(bs::Mone<T>()), T(-7.853981633974483e-01), 1.5);
  STF_ULP_EQUAL(acot(bs::One<T>()), T(7.853981633974483e-01), 1.5);
  STF_ULP_EQUAL(acot(bs::Zero<T>()), T(1.570796326794897e+00), 1.5);
  STF_ULP_EQUAL(acot(bs::rec(bs::Eps<T>())), bs::Eps<T>(), 1.5);
}
