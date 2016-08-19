//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acsc.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_6.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" acsc",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acsc;

  using r_t = decltype(acsc(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(acsc(bs::Inf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(acsc(bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(acsc(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(acsc(bs::Zero<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(acsc(-bs::Two<T>()), -bs::Pio_6<r_t>(), 0.5);
  STF_ULP_EQUAL(acsc(bs::Mone<T>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(acsc(bs::One<T>()), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(acsc(bs::Two<T>()), bs::Pio_6<r_t>(), 0.5);
}

