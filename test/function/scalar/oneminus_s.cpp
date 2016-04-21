//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/oneminus_s.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" oneminus_s signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneminus_s;
  using r_t = decltype(oneminus_s(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(oneminus_s(bs::Mone<T>()), bs::Two<T>());
  STF_EQUAL(oneminus_s(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(oneminus_s(bs::Valmax<T>()), bs::Valmin<T>()+bs::Two<T>());
  STF_EQUAL(oneminus_s(bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL (" oneminus_s unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneminus_s;
  using r_t = decltype(oneminus_s(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(oneminus_s(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(oneminus_s(bs::Two<T>()), bs::Zero<T>());
  STF_EQUAL(oneminus_s(bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL(" oneminus_s floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneminus_s;
  using r_t = decltype(oneminus_s(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(oneminus_s(bs::Inf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(oneminus_s(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(oneminus_s(bs::Minf<T>()), bs::Inf<T>());
#endif
  STF_EQUAL(oneminus_s(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(oneminus_s(bs::Two<T>()), bs::Mone<T>());
  STF_EQUAL(oneminus_s(bs::Zero<T>()), bs::One<T>());
}

