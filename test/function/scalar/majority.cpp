//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/majority.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/quarter.hpp>

STF_CASE_TPL (" majorityreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::majority;
  using r_t = decltype(majority(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(majority(bs::Inf<T>(), bs::Inf<T>(), bs::Inf<T>()), r_t(true));
  STF_EQUAL(majority(bs::Minf<T>(), bs::Minf<T>(), bs::Minf<T>()), r_t(true));
  STF_EQUAL(majority(bs::Nan<T>(), bs::Nan<T>(), bs::Nan<T>()), r_t(true));
#endif
  STF_EQUAL(majority(-bs::Zero<T>(), -bs::Zero<T>(), -bs::Zero<T>()), r_t(false));
  STF_EQUAL(majority(bs::Half<T>(), bs::Half<T>(), bs::Half<T>()), r_t(true));
  STF_EQUAL(majority(bs::Mone<T>(), bs::Mone<T>(), bs::Mone<T>()), r_t(true));
  STF_EQUAL(majority(bs::One<T>(), bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(majority(bs::Quarter<T>(), bs::Quarter<T>(), bs::Quarter<T>()), r_t(true));
  STF_EQUAL(majority(bs::Two<T>(), bs::Two<T>(), bs::Two<T>()), r_t(true));
  STF_EQUAL(majority(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), r_t(false));
}

STF_CASE_TPL (" majoritysigned_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::majority;
  using r_t = decltype(majority(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);


  // specific values tests
  STF_EQUAL(majority(bs::Mone<T>(), bs::Mone<T>(), bs::Mone<T>()), r_t(true));
  STF_EQUAL(majority(bs::One<T>(), bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(majority(bs::Two<T>(), bs::Two<T>(), bs::Two<T>()), r_t(true));
  STF_EQUAL(majority(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), r_t(false));
}

STF_CASE_TPL (" majorityunsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::majority;
  using r_t = decltype(majority(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(majority(bs::One<T>(), bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(majority(bs::Two<T>(), bs::Two<T>(), bs::Two<T>()), r_t(true));
  STF_EQUAL(majority(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), r_t(false));
}
STF_CASE ( "majority bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::majority;
  using r_t = decltype(majority(bool(),bool(),bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);


  // specific values tests
  STF_EQUAL(majority(true, false, true), true);
  STF_EQUAL(majority(false, true, true), true);
  STF_EQUAL(majority(true, true, false), true);
  STF_EQUAL(majority(false, false, true), false);
}
