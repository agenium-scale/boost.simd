//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/selinc.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" selinc signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::selinc;

  // return type conformity test
  STF_EXPR_IS( selinc(T(), T()), T );

  // specific values tests
  STF_EQUAL(selinc(bs::One<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(selinc(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(selinc(bs::One<T>(), bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL (" selinc unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::selinc;

  // return type conformity test
  STF_EXPR_IS( selinc(T(), T()), T );

  // specific values tests
  STF_EQUAL(selinc(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(selinc(bs::One<T>(), bs::Valmax<T>()), bs::Zero<T>());
  STF_EQUAL(selinc(bs::One<T>(), bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL(" selinc floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::selinc;

  // return type conformity test
  STF_EXPR_IS( selinc(T(), T()), T );

  // specific values tests
  STF_EQUAL(selinc(bs::One<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(selinc(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(selinc(bs::One<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(selinc(bs::One<T>(), bs::Zero<T>()), bs::One<T>());
}
