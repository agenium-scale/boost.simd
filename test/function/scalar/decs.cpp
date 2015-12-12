//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/decs.hpp>
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

STF_CASE_TPL (" decs signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::decs;
  using r_t = decltype(decs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(decs(bs::Mone<T>()), bs::Two<T>());
  STF_EQUAL(decs(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(decs(bs::Valmax<T>()), bs::Valmin<T>()+bs::Two<T>());
  STF_EQUAL(decs(bs::Zero<T>()), bs::One<T>());
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
  STF_EQUAL(decs(bs::Two<T>()), bs::Zero<T>());
  STF_EQUAL(decs(bs::Zero<T>()), bs::One<T>());
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
  STF_EQUAL(decs(bs::Inf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(decs(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(decs(bs::Minf<T>()), bs::Inf<T>());
#endif
  STF_EQUAL(decs(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(decs(bs::Two<T>()), bs::Mone<T>());
  STF_EQUAL(decs(bs::Zero<T>()), bs::One<T>());
}

