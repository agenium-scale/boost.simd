//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/trunc.hpp>
#include <boost/simd/function/fast.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/three.hpp>

STF_CASE_TPL (" trunc real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::trunc;
  using r_t = decltype(trunc(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(trunc(bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(trunc(bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(trunc(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(trunc(bs::One<T>()), bs::One<T>());
  STF_EQUAL(trunc(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(trunc(bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(trunc(bs::Pi<T>()), bs::Three<T>());
  STF_EQUAL(trunc(T(1.4)), T(1));
  STF_EQUAL(trunc(T(1.5)), T(1));
  STF_EQUAL(trunc(T(1.6)), T(1));
  STF_EQUAL(trunc(T(2.5)), T(2));
  STF_EQUAL(trunc(T(-1.4)), T(-1));
  STF_EQUAL(trunc(T(-1.5)), T(-1));
  STF_EQUAL(trunc(T(-1.6)), T(-1));
  STF_EQUAL(trunc(T(-2.5)), T(-2));
} // end of test for floating_

STF_CASE_TPL (" trunc unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::trunc;
  using r_t = decltype(trunc(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(trunc(bs::One<T>()), bs::One<T>());
  STF_EQUAL(trunc(bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" trunc signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::trunc;
  using r_t = decltype(trunc(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(trunc(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(trunc(bs::One<T>()), bs::One<T>());
  STF_EQUAL(trunc(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

STF_CASE_TPL ( "fast trunc real",  STF_IEEE_TYPES)
{

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::trunc;
  using r_t = decltype(trunc(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bs::fast_(trunc)(bs::One<T>()), bs::One<T>());
  STF_EQUAL(bs::fast_(trunc)(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(bs::fast_(trunc)(bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(bs::fast_(trunc)(bs::Pi<T>()), bs::Three<T>());
  STF_EQUAL(bs::fast_(trunc)(T(1.4)), T(1));
  STF_EQUAL(bs::fast_(trunc)(T(1.5)), T(1));
  STF_EQUAL(bs::fast_(trunc)(T(1.6)), T(1));
  STF_EQUAL(bs::fast_(trunc)(T(2.5)), T(2));
  STF_EQUAL(bs::fast_(trunc)(T(-1.4)), T(-1));
  STF_EQUAL(bs::fast_(trunc)(T(-1.5)), T(-1));
  STF_EQUAL(bs::fast_(trunc)(T(-1.6)), T(-1));
  STF_EQUAL(bs::fast_(trunc)(T(-2.5)), T(-2));
} // end of test for floating_

