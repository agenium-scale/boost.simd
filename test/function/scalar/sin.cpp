//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sin.hpp>
#include <boost/simd/function/restricted.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>

STF_CASE_TPL (" sin",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sin;

  using r_t = decltype(sin(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sin(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(sin(-bs::Pio_2<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(-bs::Pio_4<T>()), -bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Pio_2<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Pio_4<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
  STF_EXPECT(bs::is_negative(sin(bs::Mzero<T>())));
  STF_EXPECT(bs::is_positive(sin(bs::Zero<T>())));
}

STF_CASE_TPL (" sin restricted ",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sin;
  using r_t = decltype(sin(T()));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::restricted_(sin)(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(sin)(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(sin)(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::restricted_(sin)(-bs::Pio_2<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(sin)(-bs::Pio_4<T>()), -bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(sin)(bs::Pio_2<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(sin)(bs::Pio_4<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(sin)(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
  STF_EXPECT(bs::is_negative(bs::restricted_(sin)(bs::Mzero<T>())));
  STF_EXPECT(bs::is_positive(bs::restricted_(sin)(bs::Zero<T>())));
}

STF_CASE_TPL (" sin",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bst = bs::tag;
  namespace bd = boost::dispatch;
  using bs::sin;

  using r_t = decltype(sin(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sin(bs::Inf<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Minf<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Nan<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(sin(-bs::Pio_2<T>(), bst::clipped_small_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(-bs::Pio_4<T>(), bst::clipped_small_), -bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Pio_2<T>(), bst::clipped_small_), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Pio_4<T>(), bst::clipped_small_), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Zero<T>(), bst::clipped_small_), bs::Zero<r_t>(), 0.5);
  STF_EXPECT(bs::is_negative(sin(bs::Mzero<T>(), bst::clipped_small_)));
  STF_EXPECT(bs::is_positive(sin(bs::Zero<T>(), bst::clipped_small_)));
}
STF_CASE_TPL (" sin",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bst = bs::tag;
  namespace bd = boost::dispatch;
  using bs::sin;

  using r_t = decltype(sin(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sin(bs::Inf<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Minf<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Nan<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(sin(-bs::Pio_2<T>(), bst::clipped_medium_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(-bs::Pio_4<T>(), bst::clipped_medium_), -bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Pio_2<T>(), bst::clipped_medium_), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Pio_4<T>(), bst::clipped_medium_), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sin(bs::Zero<T>(), bst::clipped_medium_), bs::Zero<r_t>(), 0.5);
  STF_EXPECT(bs::is_negative(sin(bs::Mzero<T>(), bst::clipped_medium_)));
  STF_EXPECT(bs::is_positive(sin(bs::Zero<T>(), bst::clipped_medium_)));
}
