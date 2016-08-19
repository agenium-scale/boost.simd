//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/is_ngtz.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" is_ngtz  _real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ngtz;
  using r_t = decltype(is_ngtz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(is_ngtz(bs::Inf<T>()), r_t(false));
  STF_EQUAL(is_ngtz(bs::Minf<T>()), r_t(true));
  STF_EQUAL(is_ngtz(bs::Nan<T>()), r_t(true));
#endif
  STF_EQUAL(is_ngtz(-bs::Zero<T>()), r_t(true));
  STF_EQUAL(is_ngtz(bs::Half<T>()), r_t(false));
  STF_EQUAL(is_ngtz(bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_ngtz(bs::One<T>()), r_t(false));
  STF_EQUAL(is_ngtz(bs::Quarter<T>()), r_t(false));
  STF_EQUAL(is_ngtz(bs::Two<T>()), r_t(false));
  STF_EQUAL(is_ngtz(bs::Zero<T>()), r_t(true));
}

STF_CASE_TPL (" is_ngtz _signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ngtz;
   using r_t = decltype(is_ngtz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_ngtz(bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_ngtz(bs::One<T>()), r_t(false));
  STF_EQUAL(is_ngtz(bs::Two<T>()), r_t(false));
  STF_EQUAL(is_ngtz(bs::Zero<T>()), r_t(true));
}

STF_CASE_TPL (" is_ngtz _unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ngtz;
  using r_t = decltype(is_ngtz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_ngtz(bs::One<T>()), r_t(false));
  STF_EQUAL(is_ngtz(bs::Two<T>()), r_t(false));
  STF_EQUAL(is_ngtz(bs::Zero<T>()), r_t(true));
}

STF_CASE ( "is_ngtz _bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ngtz;
  using r_t = decltype(is_ngtz(bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);

  // specific values tests
  STF_EQUAL(is_ngtz(true), false);
  STF_EQUAL(is_ngtz(false), true);
}

