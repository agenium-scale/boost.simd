//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/rsqrt.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/half.hpp>

STF_CASE_TPL (" rsqrtreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rsqrt;
  using r_t = decltype(rsqrt(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(rsqrt(bs::Inf<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(rsqrt(bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(rsqrt(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_IEEE_EQUAL(rsqrt(bs::Mone<T>()), bs::Nan<r_t>());
  STF_EQUAL(rsqrt(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(rsqrt(bs::Zero<T>()), bs::Inf<r_t>());
  STF_EQUAL(rsqrt(bs::Four<T>()), bs::Half<r_t>());
} // end of test for floating_

