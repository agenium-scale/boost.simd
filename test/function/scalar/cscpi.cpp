//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/cscpi.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>

STF_CASE_TPL (" cscpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cscpi;

  using r_t = decltype(cscpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cscpi(-bs::Zero<T>()), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mone<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::One<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Zero<T>()), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cscpi(-bs::Quarter<T>()), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Half<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mhalf<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Quarter<T>()), bs::Sqrt_2<r_t>(), 0.5);
}
STF_CASE_TPL (" cscpi fast",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cscpi;

  using r_t = decltype(cscpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cscpi(-bs::Zero<T>(), bs::fast_), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Inf<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Minf<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mone<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Nan<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::One<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Zero<T>(), bs::fast_), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cscpi(-bs::Quarter<T>(), bs::fast_), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Half<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mhalf<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Quarter<T>(), bs::fast_), bs::Sqrt_2<r_t>(), 0.5);
}

STF_CASE_TPL (" cscpi clipped_smal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cscpi;

  using r_t = decltype(cscpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cscpi(-bs::Zero<T>(), bs::clipped_small_), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Inf<T>(), bs::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Minf<T>(), bs::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mone<T>(), bs::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Nan<T>(), bs::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::One<T>(), bs::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Zero<T>(), bs::clipped_small_), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cscpi(-bs::Quarter<T>(), bs::clipped_small_), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Half<T>(), bs::clipped_small_), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mhalf<T>(), bs::clipped_small_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Quarter<T>(), bs::clipped_small_), bs::Sqrt_2<r_t>(), 0.5);
}

STF_CASE_TPL (" cscpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cscpi;

  using r_t = decltype(cscpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cscpi(-bs::Zero<T>(), bs::clipped_medium_), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Inf<T>(), bs::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Minf<T>(), bs::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mone<T>(), bs::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Nan<T>(), bs::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::One<T>(), bs::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Zero<T>(), bs::clipped_medium_), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cscpi(-bs::Quarter<T>(), bs::clipped_medium_), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Half<T>(), bs::clipped_medium_), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mhalf<T>(), bs::clipped_medium_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Quarter<T>(), bs::clipped_medium_), bs::Sqrt_2<r_t>(), 0.5);
}
