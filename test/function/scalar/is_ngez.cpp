//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/is_ngez.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" is_ngez  _real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ngez;
  using r_t = decltype(is_ngez(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(is_ngez(bs::Inf<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Minf<T>()), r_t(true));
  STF_EQUAL(is_ngez(bs::Nan<T>()), r_t(true));
#endif
  STF_EQUAL(is_ngez(bs::Mzero<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Half<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_ngez(bs::One<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Quarter<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Two<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Zero<T>()), r_t(false));
}

STF_CASE_TPL (" is_ngez _signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ngez;
   using r_t = decltype(is_ngez(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_ngez(bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_ngez(bs::One<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Two<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Zero<T>()), r_t(false));
}

STF_CASE_TPL (" is_ngez _unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ngez;
  using r_t = decltype(is_ngez(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_ngez(bs::One<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Two<T>()), r_t(false));
  STF_EQUAL(is_ngez(bs::Zero<T>()), r_t(false));
}

STF_CASE ( "is_ngez _bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ngez;
  using r_t = decltype(is_ngez(bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);

  // specific values tests
  STF_EQUAL(is_ngez(true), false);
  STF_EQUAL(is_ngez(false), false);
}
STF_CASE_TPL ( "is_ngez _logical", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ngez;
  using lT = bs::logical<T>;
  using r_t = decltype(is_ngez(lT()));

  // return type conformity test
  STF_TYPE_IS(r_t, lT);

  // specific values tests
  STF_EQUAL(is_ngez(bs::True<lT>()), bs::False<lT>());
  STF_EQUAL(is_ngez(bs::False<lT>()), bs::False<lT>());
}


