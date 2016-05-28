//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/subs.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" subssigned_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::subs;

  // return type conformity test
  STF_EXPR_IS(subs(T(), T()), T);

  // specific values tests
  STF_EQUAL(subs(T(-2), bs::Valmin<T>()), bs::Valmax<T>()-bs::One<T>());
  STF_EQUAL(subs(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(subs(bs::Mone<T>(), bs::Valmax<T>()), bs::Valmin<T>());
  STF_EQUAL(subs(bs::Mone<T>(), bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(subs(bs::One<T>(),bs::Mone<T>()), bs::Two<T>());
  STF_EQUAL(subs(bs::Valmin<T>(),bs::Mone<T>()), bs::Valmin<T>()+bs::One<T>());
  STF_EQUAL(subs(bs::Valmin<T>(),bs::One<T>()), bs::Valmin<T>());
  STF_EQUAL(subs(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(subs(bs::Zero<T>(), bs::Valmin<T>()), bs::Valmax<T>());
} // end of test for signed_int_

STF_CASE_TPL (" subs unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::subs;

  // return type conformity test
  STF_EXPR_IS(subs(T(), T()), T);

  // specific values tests
  STF_EQUAL(subs(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(subs(bs::One<T>(),bs::Valmax<T>()), bs::Valmin<T>());
  STF_EQUAL(subs(bs::Valmin<T>(),bs::One<T>()), bs::Valmin<T>());
  STF_EQUAL(subs(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" subs real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::subs;
  // return type conformity test
  STF_EXPR_IS(subs(T(), T()), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(subs(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(subs(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(subs(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(subs(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(subs(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(subs(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for floating_

