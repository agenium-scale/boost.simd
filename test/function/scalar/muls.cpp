//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/muls.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" mulssigned_int",  STF_SIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::muls;

  using r_t = decltype(muls(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(muls(bs::Mone<T>(), bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(muls(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(muls(bs::Valmax<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(muls(bs::Valmax<T>(),T(2)), bs::Valmax<T>());
  STF_EQUAL(muls(bs::Valmax<T>(),bs::Mone<T>()), bs::Valmin<T>()+bs::One<T>());
  STF_EQUAL(muls(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(muls(bs::Valmin<T>(),bs::Mone<T>()), bs::Valmax<T>());
  STF_EQUAL(muls(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

STF_CASE_TPL (" mulsunsigned_int",  STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::muls;
  using r_t = decltype(muls(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(muls(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(muls(bs::Valmax<T>(),T(2)), bs::Valmax<T>());
  STF_EQUAL(muls(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE("mul sspecial")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::muls;
  using bs::splat;
  using bs::Valmin;

  typedef short int T1;
  STF_EQUAL(muls(splat<T1>(-5165), splat<T1>(23258)), Valmin<T1>());

  typedef int T2;
  STF_EQUAL(muls(splat<T2>(-1306766858), splat<T2>(1550772331)), Valmin<T2>());
  STF_EQUAL(muls(splat<T2>(1467238299), splat<T2>(-900961598)), Valmin<T2>());
}
