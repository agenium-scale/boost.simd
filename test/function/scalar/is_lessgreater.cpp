//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/is_lessgreater.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <cmath>

STF_CASE_TPL (" is_lessgreater real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_lessgreater;
  using r_t = decltype(is_lessgreater(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(is_lessgreater(bs::Inf<T>(), bs::Inf<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Minf<T>(), bs::Minf<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Nan<T>(), bs::Nan<T>()), r_t(false));
#endif
  STF_EQUAL(is_lessgreater(-bs::Zero<T>(), -bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Half<T>(), bs::Half<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Mone<T>(), bs::Mone<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::One<T>(), bs::One<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Quarter<T>(), bs::Quarter<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Two<T>(), bs::Two<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(-bs::Zero<T>(), -bs::One<T>()), r_t(true));
  STF_EQUAL(is_lessgreater(bs::One<T>(), bs::Half<T>()), r_t(true));
}

STF_CASE_TPL (" is_lessgreater signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_lessgreater;
  using r_t = decltype(is_lessgreater(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_lessgreater(bs::Mone<T>(), bs::Mone<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::One<T>(), bs::One<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Two<T>(), bs::Two<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Mone<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(is_lessgreater(bs::One<T>(), bs::Mone<T>()), r_t(true));
}

STF_CASE_TPL (" is_lessgreater unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_lessgreater;
  using r_t = decltype(is_lessgreater(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_lessgreater(bs::One<T>(), bs::One<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Two<T>(), bs::Two<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_lessgreater(bs::Zero<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(is_lessgreater(bs::Two<T>(), bs::Zero<T>()), r_t(true));
}

STF_CASE ( "is_lessgreater bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_lessgreater;
  using r_t = decltype(is_lessgreater(bool(), bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);

  // specific values tests
  STF_EQUAL(is_lessgreater(true, false), true);
  STF_EQUAL(is_lessgreater(false, true), true);
  STF_EQUAL(is_lessgreater(true, true), false);
  STF_EQUAL(is_lessgreater(false, false), false);
}
