//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/tan.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/pio_2.hpp>

STF_CASE_TPL (" tan",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tan;

  using r_t = decltype(tan(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(tan(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(tan(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(tan(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(tan(-bs::Pi<T>()), bs::Zero<r_t>(), 0.75);
  STF_ULP_EQUAL(tan(-bs::Pio_4<T>()), bs::Mone<r_t>(), 1.0);
  STF_ULP_EQUAL(tan(bs::Pi<T>()), bs::Zero<r_t>(), 0.75);
  STF_ULP_EQUAL(tan(bs::Pio_4<T>()), bs::One<r_t>(), 1.0);
  STF_ULP_EQUAL(tan(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(tan(bs::Pio_4<T>()*3), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(tan(-bs::Pio_4<T>()*3), bs::One<r_t>(), 0.5);
}
