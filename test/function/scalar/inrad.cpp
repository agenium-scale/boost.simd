//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/inrad.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pi.hpp>

STF_CASE_TPL (" inrad",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::inrad;

  using r_t = decltype(inrad(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(inrad(bs::Inf<T>()), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(inrad(bs::Minf<T>()), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(inrad(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(inrad(T(-180)), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(inrad(T(-45)), -bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(inrad(T(-90)), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(inrad(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(inrad(T(180)), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(inrad(T(45)), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(inrad(T(90)), bs::Pio_2<r_t>(), 0.5);
}
