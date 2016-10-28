//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sqr.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/saturated.hpp>

STF_CASE_TPL (" sqr real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr;
  using r_t = decltype(sqr(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(sqr(bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(sqr(bs::Minf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(sqr(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(sqr(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(sqr(bs::One<T>()), bs::One<T>());
  STF_EQUAL(sqr(bs::Zero<T>()), bs::Zero<T>());
} // end of test for floating_

STF_CASE_TPL (" sqr unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr;
  using r_t = decltype(sqr(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sqr(bs::One<T>()), bs::One<T>());
  STF_EQUAL(sqr(bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" sqr signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr;
  using r_t = decltype(sqr(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sqr(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(sqr(bs::One<T>()), bs::One<T>());
  STF_EQUAL(sqr(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_


STF_CASE_TPL( "Check saturated sqr behavior ", STF_SIGNED_INTEGRAL_TYPES )
{
  namespace bs = boost::simd;
  using bs::sqr;
  using r_t = decltype(bs::saturated_(sqr)(T()));
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(bs::saturated_(sqr)(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(bs::saturated_(sqr)(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(bs::saturated_(sqr)(bs::Mone<T>()), bs::One<r_t>());
}
