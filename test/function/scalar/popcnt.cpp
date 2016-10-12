//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/popcnt.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" popcnt real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::popcnt;
  using r_t = decltype(popcnt(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, unsigned>));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(popcnt(bs::Nan<T>()), sizeof(T)*8);
#endif
  STF_EQUAL(popcnt(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" popcnt integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::popcnt;
  using r_t = decltype(popcnt(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, unsigned>));

  // specific values tests
  STF_EQUAL(popcnt(T(2)), bs::One<r_t>());
  STF_EQUAL(popcnt(T(3)), bs::Two<r_t>());
  STF_EQUAL(popcnt(bs::Mone<T>()), sizeof(T)*8);
  STF_EQUAL(popcnt(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(popcnt(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_
