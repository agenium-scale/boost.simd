//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/multiplies.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" bs::saturated_(bs::multiplies) signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using r_t = decltype(bs::saturated_(bs::multiplies)(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::Mone<T>(), bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::Valmax<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::Valmax<T>(),T(2)), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::Valmax<T>(),bs::Mone<T>()), bs::Valmin<T>()+bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::Valmin<T>(),bs::Mone<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

STF_CASE_TPL (" bs::saturated_(bs::multiplies)unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using r_t = decltype(bs::saturated_(bs::multiplies)(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::Valmax<T>(),T(2)), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE("mul sspecial")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::splat;
  using bs::Valmin;

  typedef short int T1;
  STF_EQUAL(bs::saturated_(bs::multiplies)(splat<T1>(-5165), splat<T1>(23258)), Valmin<T1>());

  typedef int T2;
  STF_EQUAL(bs::saturated_(bs::multiplies)(splat<T2>(-1306766858), splat<T2>(1550772331)), Valmin<T2>());
  STF_EQUAL(bs::saturated_(bs::multiplies)(splat<T2>(1467238299), splat<T2>(-900961598)), Valmin<T2>());
}
