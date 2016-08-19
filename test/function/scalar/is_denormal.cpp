//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/is_denormal.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" is_denormal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_denormal;

  using r_t = decltype(is_denormal(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(is_denormal(bs::Inf<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Minf<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Nan<T>()), r_t(false));
#endif
  STF_EQUAL(is_denormal(-bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Half<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Mone<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::One<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Quarter<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Two<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Smallestposval<T>()),  r_t(false));
#ifndef STF_NO_DENORMAL
  STF_EQUAL(is_denormal(bs::Mindenormal<T>()), r_t(true));
  STF_EQUAL(is_denormal(bs::Smallestposval<T>()/bs::Two<T>()), r_t(true));
#endif
}

STF_CASE_TPL (" is_denormal signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_denormal;
  using r_t = decltype(is_denormal(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_denormal(bs::Mone<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::One<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Two<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Zero<T>()), r_t(false));
}

STF_CASE_TPL (" is_denormal unsigned_int__1_0",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_denormal;

  using r_t = decltype(is_denormal(T()));
  typedef bs::logical<T> wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(is_denormal(bs::One<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Two<T>()), r_t(false));
  STF_EQUAL(is_denormal(bs::Zero<T>()), r_t(false));
}

STF_CASE ( "is_denormal bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_denormal;
  using r_t = decltype(is_denormal(bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);

  // specific values tests
  STF_EQUAL(is_denormal(true), false);
  STF_EQUAL(is_denormal(false), false);
}


