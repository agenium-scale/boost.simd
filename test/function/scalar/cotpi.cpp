//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/cotpi.hpp>
#include <boost/simd/function/restricted.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" cotpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cotpi;

  using r_t = decltype(cotpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cotpi(-bs::Zero<T>()), -bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::One<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Zero<T>()), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cotpi(-bs::Quarter<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Half<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Mhalf<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Quarter<T>()), bs::One<r_t>(), 0.5);
}
STF_CASE_TPL (" cotpi restricted_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cotpi;

  using r_t = decltype(cotpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::restricted_(cotpi)(-bs::Zero<T>()), -bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cotpi)(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cotpi)(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cotpi)(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cotpi)(bs::One<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cotpi)(bs::Zero<T>()), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::restricted_(cotpi)(-bs::Quarter<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cotpi)(bs::Half<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cotpi)(bs::Mhalf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cotpi)(bs::Quarter<T>()), bs::One<r_t>(), 0.5);
}
