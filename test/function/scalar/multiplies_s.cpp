//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/multiplies_s.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" multiplies_ssigned_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::multiplies_s;

  using r_t = decltype(multiplies_s(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(multiplies_s(bs::Mone<T>(), bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(multiplies_s(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(multiplies_s(bs::Valmax<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(multiplies_s(bs::Valmax<T>(),T(2)), bs::Valmax<T>());
  STF_EQUAL(multiplies_s(bs::Valmax<T>(),bs::Mone<T>()), bs::Valmin<T>()+bs::One<T>());
  STF_EQUAL(multiplies_s(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(multiplies_s(bs::Valmin<T>(),bs::Mone<T>()), bs::Valmax<T>());
  STF_EQUAL(multiplies_s(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

STF_CASE_TPL (" multiplies_sunsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::multiplies_s;
  using r_t = decltype(multiplies_s(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(multiplies_s(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(multiplies_s(bs::Valmax<T>(),T(2)), bs::Valmax<T>());
  STF_EQUAL(multiplies_s(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE("mul sspecial")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::multiplies_s;
  using bs::splat;
  using bs::Valmin;

  typedef short int T1;
  STF_EQUAL(multiplies_s(splat<T1>(-5165), splat<T1>(23258)), Valmin<T1>());

  typedef int T2;
  STF_EQUAL(multiplies_s(splat<T2>(-1306766858), splat<T2>(1550772331)), Valmin<T2>());
  STF_EQUAL(multiplies_s(splat<T2>(1467238299), splat<T2>(-900961598)), Valmin<T2>());
}
