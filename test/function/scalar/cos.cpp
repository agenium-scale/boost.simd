//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/cos.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/restricted.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>

STF_CASE_TPL (" cos",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cos;

  using r_t = decltype(cos(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cos(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cos(T(2.0)*bs::Pi<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(-bs::Pi<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(-bs::Pio_2<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(-bs::Pio_4<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Pi<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Pio_2<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Pio_4<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Zero<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(T(3.836536000e+07)), T(-0.38268298167737746507), 0.5);
}

STF_CASE_TPL (" cos restricted_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cos;

  using r_t = decltype(cos(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::restricted_(cos)(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cos)(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cos)(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::restricted_(cos)(-bs::Pi<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cos)(-bs::Pio_2<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cos)(-bs::Pio_4<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cos)(bs::Pi<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cos)(bs::Pio_2<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cos)(bs::Pio_4<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cos)(bs::Zero<T>()), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" cos clipped_small_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bst = bs::tag;
  namespace bd = boost::dispatch;
  using bs::cos;

  using r_t = decltype(cos(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cos(bs::Inf<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Minf<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Nan<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cos(-bs::Pi<T>(), bst::clipped_small_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(-bs::Pio_2<T>(), bst::clipped_small_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(-bs::Pio_4<T>(), bst::clipped_small_), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Pi<T>(), bst::clipped_small_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Pio_2<T>(), bst::clipped_small_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Pio_4<T>(), bst::clipped_small_), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Zero<T>(), bst::clipped_small_), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" cos clipped_medium_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bst = bs::tag;
  namespace bd = boost::dispatch;
  using bs::cos;

  using r_t = decltype(cos(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cos(bs::Inf<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Minf<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Nan<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cos(-bs::Pi<T>(), bst::clipped_medium_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(-bs::Pio_2<T>(), bst::clipped_medium_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(-bs::Pio_4<T>(), bst::clipped_medium_), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Pi<T>(), bst::clipped_medium_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Pio_2<T>(), bst::clipped_medium_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Pio_4<T>(), bst::clipped_medium_), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cos(bs::Zero<T>(), bst::clipped_medium_), bs::One<r_t>(), 0.5);
}
