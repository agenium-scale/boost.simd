//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/cscpi.hpp>
#include <boost/simd/function/restricted.hpp>
#include <scalar_test.hpp>
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
STF_CASE_TPL (" cscpi restricted",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cscpi;

  using r_t = decltype(cscpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::restricted_(cscpi)(-bs::Zero<T>()), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cscpi)(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cscpi)(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cscpi)(bs::Mone<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cscpi)(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cscpi)(bs::One<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cscpi)(bs::Zero<T>()), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::restricted_(cscpi)(-bs::Quarter<T>()), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cscpi)(bs::Half<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cscpi)(bs::Mhalf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cscpi)(bs::Quarter<T>()), bs::Sqrt_2<r_t>(), 0.5);
}

STF_CASE_TPL (" cscpi clipped_smal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bst = bs::tag;
  namespace bd = boost::dispatch;
  using bs::cscpi;

  using r_t = decltype(cscpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cscpi(-bs::Zero<T>(), bst::clipped_small_), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Inf<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Minf<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mone<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Nan<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::One<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Zero<T>(), bst::clipped_small_), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cscpi(-bs::Quarter<T>(), bst::clipped_small_), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Half<T>(), bst::clipped_small_), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mhalf<T>(), bst::clipped_small_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Quarter<T>(), bst::clipped_small_), bs::Sqrt_2<r_t>(), 0.5);
}

STF_CASE_TPL (" cscpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bst = bs::tag;
  namespace bd = boost::dispatch;
  using bs::cscpi;

  using r_t = decltype(cscpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cscpi(-bs::Zero<T>(), bst::clipped_medium_), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Inf<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Minf<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mone<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Nan<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::One<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Zero<T>(), bst::clipped_medium_), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cscpi(-bs::Quarter<T>(), bst::clipped_medium_), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Half<T>(), bst::clipped_medium_), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Mhalf<T>(), bst::clipped_medium_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cscpi(bs::Quarter<T>(), bst::clipped_medium_), bs::Sqrt_2<r_t>(), 0.5);
}
