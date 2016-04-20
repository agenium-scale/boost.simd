//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/remfix.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" remfix real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::remfix;
  using r_t = decltype(remfix(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(remfix(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(remfix(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(remfix(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(remfix(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(remfix(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(remfix(bs::Zero<T>(), bs::Nan<T>()), bs::Zero<T>());
} // end of test for floating_

STF_CASE_TPL (" remfix unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::remfix;
  using r_t = decltype(remfix(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(remfix(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(remfix(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" remfix signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::remfix;
  using r_t = decltype(remfix(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(remfix(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(remfix(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(remfix(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_
