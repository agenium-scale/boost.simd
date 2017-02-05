//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acosd.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>


STF_CASE_TPL ("pedantic  acosd ",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acosd;
  using bs::pedantic_;

  using r_t = decltype(pedantic_(acosd)(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(pedantic_(acosd)(bs::Inf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(pedantic_(acosd)(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(pedantic_(acosd)(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(pedantic_(acosd)(bs::Half<T>()), 60, 0.5);
  STF_ULP_EQUAL(pedantic_(acosd)(bs::Mhalf<T>()), 120, 0.5);
  STF_ULP_EQUAL(pedantic_(acosd)(bs::Mone<T>()), 180, 0.5);
  STF_ULP_EQUAL(pedantic_(acosd)(bs::One<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(pedantic_(acosd)(bs::Zero<T>()), 90, 0.5);
}
