//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/cotpi.hpp>
#include <simd_test.hpp>
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
STF_CASE_TPL (" cotpi fast_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cotpi;

  using r_t = decltype(cotpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cotpi(-bs::Zero<T>(), bs::fast_), -bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Inf<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Minf<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Nan<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::One<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Zero<T>(), bs::fast_), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cotpi(-bs::Quarter<T>(), bs::fast_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Half<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Mhalf<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cotpi(bs::Quarter<T>(), bs::fast_), bs::One<r_t>(), 0.5);
}
