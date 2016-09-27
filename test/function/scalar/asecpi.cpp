//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/asecpi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" asecpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::asecpi;

  using r_t = decltype(asecpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(asecpi(bs::Inf<T>()), 0.5, 0.5);
  STF_ULP_EQUAL(asecpi(bs::Minf<T>()), 0.5, 0.5);
  STF_IEEE_EQUAL(asecpi(bs::Nan<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(asecpi(bs::Zero<T>()), bs::Nan<r_t>());
#endif

  STF_ULP_EQUAL(asecpi(-bs::Two<T>()), T(2.0/3.0), 0.5);
  STF_ULP_EQUAL(asecpi(bs::Mone<T>()), T(1.0), 0.5);
  STF_ULP_EQUAL(asecpi(bs::One<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(asecpi(bs::Two<T>()), T(1/3.0), 0.5);
}


