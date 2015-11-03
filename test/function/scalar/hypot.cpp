//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/hypot.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <boost/simd/options.hpp>


STF_CASE_TPL (" hypot real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::hypot;
  using r_t = decltype(hypot(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_ULP_EQUAL(hypot(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(hypot(bs::Minf<T>(), bs::Minf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(hypot(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(hypot(bs::Nan<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(hypot(bs::Inf<T>(), bs::Nan<T>()), bs::Inf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(hypot(bs::Mone<T>(), bs::Mone<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(hypot(bs::One<T>(), bs::One<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(hypot(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>(), 0);
  STF_ULP_EQUAL(hypot(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>(), 0.5);
  STF_ULP_EQUAL(hypot(bs::Zero<T>(), bs::Valmax<T>()), bs::Valmax<T>(), 0.5);
} // end of test for floating_


STF_CASE_TPL (" hypot real fast",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::hypot;
  using r_t = decltype(hypot(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_ULP_EQUAL(hypot(bs::Inf<T>(), bs::Inf<T>(), bs::fast_), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(hypot(bs::Minf<T>(), bs::Minf<T>(), bs::fast_), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(hypot(bs::Nan<T>(), bs::Nan<T>(), bs::fast_), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(hypot(bs::Nan<T>(), bs::Inf<T>(), bs::fast_), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(hypot(bs::Inf<T>(), bs::Nan<T>(), bs::fast_), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(hypot(bs::Mone<T>(), bs::Mone<T>(), bs::fast_), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(hypot(bs::One<T>(), bs::One<T>(), bs::fast_), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(hypot(bs::Zero<T>(), bs::Zero<T>(), bs::fast_), bs::Zero<T>(), 0);
  STF_ULP_EQUAL(hypot(bs::Valmax<T>(), bs::Zero<T>(), bs::fast_), bs::Inf<T>(), 0.5);
  STF_ULP_EQUAL(hypot(bs::Zero<T>(), bs::Valmax<T>(), bs::fast_), bs::Inf<T>(), 0.5);
} // end of test for floating_
