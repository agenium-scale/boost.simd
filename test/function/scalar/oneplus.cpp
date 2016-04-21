//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/oneplus.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" oneplus signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneplus;
  using r_t = decltype(oneplus(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(oneplus(bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(oneplus(bs::One<T>()), bs::Two<T>());
  STF_EQUAL(oneplus(bs::Valmax<T>()), bs::Valmin<T>());
  STF_EQUAL(oneplus(bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL (" oneplus unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneplus;
  using r_t = decltype(oneplus(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(oneplus(bs::One<T>()), bs::Two<T>());
  STF_EQUAL(oneplus(bs::Two<T>()), bs::Three<T>());
  STF_EQUAL(oneplus(bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL(" oneplus floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneplus;
  using r_t = decltype(oneplus(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(oneplus(bs::Inf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(oneplus(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(oneplus(bs::Minf<T>()), bs::Minf<T>());
#endif
  STF_EQUAL(oneplus(bs::One<T>()), bs::Two<T>());
  STF_EQUAL(oneplus(bs::Two<T>()), bs::Three<T>());
  STF_EQUAL(oneplus(bs::Zero<T>()), bs::One<T>());
}
