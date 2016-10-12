//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_dec.hpp>
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

STF_CASE_TPL (" if_dec signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_dec;

  // return type conformity test
  STF_EXPR_IS( if_dec(T(), T()), T );

  // specific values tests
  STF_EQUAL(if_dec(bs::One<T>(), bs::Mone<T>()), bs::Mtwo<T>());
  STF_EQUAL(if_dec(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(if_dec(bs::One<T>(), bs::Zero<T>()), bs::Mone<T>());
}

STF_CASE_TPL (" if_dec unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_dec;

  // return type conformity test
  STF_EXPR_IS( if_dec(T(), T()), T );

  // specific values tests
  STF_EQUAL(if_dec(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(if_dec(bs::One<T>(), bs::Two<T>()), bs::One<T>());
  STF_EQUAL(if_dec(bs::One<T>(), bs::Zero<T>()), bs::Valmax<T>());
}

STF_CASE_TPL(" if_dec floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_dec;

  // return type conformity test
  STF_EXPR_IS( if_dec(T(), T()), T );

  // specific values tests
  STF_EQUAL(if_dec(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(if_dec(bs::One<T>(), bs::Two<T>()), bs::One<T>());
  STF_EQUAL(if_dec(bs::One<T>(), bs::Zero<T>()), bs::Mone<T>());
}


