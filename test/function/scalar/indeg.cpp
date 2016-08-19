//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/indeg.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>

STF_CASE_TPL (" indeg",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::indeg;

  using r_t = decltype(indeg(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(indeg(bs::Inf<T>()), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(indeg(bs::Minf<T>()), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(indeg(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(indeg(-bs::Pi<T>()), -T(180), 0.5);
  STF_ULP_EQUAL(indeg(-bs::Pio_2<T>()), -T(90), 0.5);
  STF_ULP_EQUAL(indeg(-bs::Pio_4<T>()), -T(45), 0.5);
  STF_ULP_EQUAL(indeg(bs::Pi<T>()), T(180), 0.5);
  STF_ULP_EQUAL(indeg(bs::Pio_2<T>()), T(90), 0.5);
  STF_ULP_EQUAL(indeg(bs::Pio_4<T>()), T(45), 0.5);
  STF_ULP_EQUAL(indeg(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
}
