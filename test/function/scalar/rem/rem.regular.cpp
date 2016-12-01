//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/rem.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/is_negative.hpp>

STF_CASE_TPL (" rem real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rem;
  using r_t = decltype(rem(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(rem(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(rem(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(rem(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(rem(bs::Inf<T>(), bs::One<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(rem(bs::One<T>(), bs::Zero<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(rem(bs::Zero<T>(), bs::Zero<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(rem(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(rem(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(rem(bs::One<T>(),bs::Zero<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(rem(bs::Zero<T>(), bs::Zero<T>()), bs::Nan<T>());
} // end of test for floating_

STF_CASE_TPL (" rem unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rem;
  using r_t = decltype(rem(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(rem(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(rem(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" rem signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rem;
  using r_t = decltype(rem(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(rem(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(rem(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(rem(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_



STF_CASE_TPL (" rem std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rem;
  using r_t = decltype(bs::std_(rem)(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bs::std_(rem)(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(bs::std_(rem)(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(bs::std_(rem)(T(3), T(2)), bs::One<T>());
} // end of test for signed_int_

STF_CASE_TPL (" rem option fix",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rem;
  using r_t = decltype(rem(bs::fix, T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(rem(bs::fix, bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(rem(bs::fix, bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(rem(bs::fix, T(3), T(2)), bs::One<T>());
} // end of test for signed_int_

