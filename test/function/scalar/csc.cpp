//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/csc.hpp>
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
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>

STF_CASE_TPL (" csc",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::csc;

  using r_t = decltype(csc(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(csc(-bs::Zero<T>()), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Zero<T>()), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(csc(-bs::Pio_2<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(-bs::Pio_4<T>()), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Pio_2<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Pio_4<T>()), bs::Sqrt_2<r_t>(), 0.5);
}

STF_CASE_TPL (" csc restricted_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::csc;

  using r_t = decltype(csc(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::restricted_(csc)(-bs::Zero<T>()), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(csc)(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(csc)(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(csc)(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(csc)(bs::Zero<T>()), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::restricted_(csc)(-bs::Pio_2<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(csc)(-bs::Pio_4<T>()), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(csc)(bs::Pio_2<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(csc)(bs::Pio_4<T>()), bs::Sqrt_2<r_t>(), 0.5);
}

STF_CASE_TPL (" csc clipped_small_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bst = bs::tag;
  namespace bd = boost::dispatch;
  using bs::csc;

  using r_t = decltype(csc(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(csc(-bs::Zero<T>(), bst::clipped_small_), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Inf<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Minf<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Nan<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Zero<T>(), bst::clipped_small_), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(csc(-bs::Pio_2<T>(), bst::clipped_small_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(-bs::Pio_4<T>(), bst::clipped_small_), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Pio_2<T>(), bst::clipped_small_), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Pio_4<T>(), bst::clipped_small_), bs::Sqrt_2<r_t>(), 0.5);
}
