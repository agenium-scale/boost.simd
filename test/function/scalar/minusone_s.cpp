//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/minusone_s.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>

STF_CASE_TPL (" MINUSONE_S SIGNED_INT",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minusone_s;

  using r_t = decltype(minusone_s(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(minusone_s(bs::Mone<T>()), bs::Mtwo<T>());
  STF_EQUAL(minusone_s(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(minusone_s(bs::Valmin<T>()), bs::Valmin<T>());
  STF_EQUAL(minusone_s(bs::Zero<T>()), bs::Mone<T>());
}

STF_CASE_TPL (" minusone_s unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minusone_s;

  using r_t = decltype(minusone_s(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(minusone_s(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(minusone_s(bs::Two<T>()), bs::One<T>());
  STF_EQUAL(minusone_s(bs::Zero<T>()), bs::Zero<T>());
}

STF_CASE_TPL(" minusone_s floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minusone_s;

  using r_t = decltype(minusone_s(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(minusone_s(bs::Inf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(minusone_s(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(minusone_s(bs::Minf<T>()), bs::Minf<T>());
#endif
  STF_EQUAL(minusone_s(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(minusone_s(bs::Two<T>()), bs::One<T>());
  STF_EQUAL(minusone_s(bs::Zero<T>()), bs::Mone<T>());
}
