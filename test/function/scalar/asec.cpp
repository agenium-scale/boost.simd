//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/asec.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/twopio_3.hpp>
#include <boost/simd/constant/pio_3.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" asec",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::asec;

  using r_t = decltype(asec(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(asec(bs::Inf<T>()), bs::Pio_2<r_t>(), 0);
  STF_ULP_EQUAL(asec(bs::Minf<T>()), bs::Pio_2<r_t>(), 0);
  STF_ULP_EQUAL(asec(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(asec(bs::Zero<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(asec(-bs::Two<T>()), bs::Twopio_3<r_t>(), 0.5);
  STF_ULP_EQUAL(asec(bs::Mone<T>()), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(asec(bs::One<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(asec(bs::Two<T>()), bs::Pio_3<r_t>(), 0.5);
}
