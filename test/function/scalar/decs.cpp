//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/decs.hpp>
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

STF_CASE_TPL (" DECS SIGNED_INT",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::decs;

  using r_t = decltype(decs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(decs(bs::Mone<T>()), bs::Mtwo<T>());
  STF_EQUAL(decs(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(decs(bs::Valmin<T>()), bs::Valmin<T>());
  STF_EQUAL(decs(bs::Zero<T>()), bs::Mone<T>());
}

STF_CASE_TPL (" decs unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::decs;

  using r_t = decltype(decs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(decs(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(decs(bs::Two<T>()), bs::One<T>());
  STF_EQUAL(decs(bs::Zero<T>()), bs::Zero<T>());
}

STF_CASE_TPL(" decs floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::decs;

  using r_t = decltype(decs(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(decs(bs::Inf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(decs(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(decs(bs::Minf<T>()), bs::Minf<T>());
#endif
  STF_EQUAL(decs(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(decs(bs::Two<T>()), bs::One<T>());
  STF_EQUAL(decs(bs::Zero<T>()), bs::Mone<T>());
}
