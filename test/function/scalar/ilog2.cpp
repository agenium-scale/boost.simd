//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ilog2.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" ilog2real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilog2;

  // return type conformity test
  STF_EXPR_IS(ilog2(T()),  bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(ilog2(bs::Two<T>()), 1);
  STF_EQUAL(ilog2(bs::Three<T>()), 1);
  STF_EQUAL(ilog2(bs::Four<T> ()), 2);
  STF_EQUAL(ilog2(bs::Pi<T> ()), 1);
  STF_EQUAL(ilog2(bs::One<T>()), 0);
} // end of test for real_

STF_CASE_TPL (" ilog2signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilog2;

  // return type conformity test
  STF_EXPR_IS(ilog2(T()),  bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(ilog2(bs::One<T>()), 0);
  STF_EQUAL(ilog2(bs::Two<T>()), 1);
} // end of test for signed_int_

 STF_CASE_TPL (" ilog2unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
 {
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilog2;

  // return type conformity test
  STF_EXPR_IS(ilog2(T()),  bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(ilog2(bs::One<T>()), 0u);
  STF_EQUAL(ilog2(bs::Two<T>()),1u);

  T j = 1;
  for(T i=2; i < bs::Valmax<T>()/2; i*= 2)
  {
    STF_EQUAL(ilog2(T(i)),j);
    STF_EQUAL(ilog2(T(i+1)),j);
    ++j;
  }
 } // end of test for unsigned_int_
