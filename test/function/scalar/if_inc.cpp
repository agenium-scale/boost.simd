//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_inc.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" if_inc signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_inc;

  // return type conformity test
  STF_EXPR_IS( if_inc(T(), T()), T );

  // specific values tests
  STF_EQUAL(if_inc(bs::One<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(if_inc(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(if_inc(bs::One<T>(), bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL (" if_inc unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_inc;

  // return type conformity test
  STF_EXPR_IS( if_inc(T(), T()), T );

  // specific values tests
  STF_EQUAL(if_inc(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(if_inc(bs::One<T>(), bs::Valmax<T>()), bs::Zero<T>());
  STF_EQUAL(if_inc(bs::One<T>(), bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL(" if_inc floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_inc;

  // return type conformity test
  STF_EXPR_IS( if_inc(T(), T()), T );

  // specific values tests
  STF_EQUAL(if_inc(bs::One<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(if_inc(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(if_inc(bs::One<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(if_inc(bs::One<T>(), bs::Zero<T>()), bs::One<T>());
}
