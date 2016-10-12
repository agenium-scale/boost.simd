//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_one_else_zero.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/two.hpp>

#include <boost/simd/logical.hpp>
STF_CASE_TPL (" if_one_else_zero real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_one_else_zero;
  using bs::logical;

  // return type conformity test
  STF_EXPR_IS( if_one_else_zero(T()),  T);

  // specific values tests
  STF_EQUAL(if_one_else_zero(T(0)), 0);
  STF_EQUAL(if_one_else_zero(T(1)), 1);
  STF_EQUAL(if_one_else_zero(bs::Inf<T>()) , 1);
  STF_EQUAL(if_one_else_zero(bs::Minf<T>()),1);
  STF_EQUAL(if_one_else_zero(bs::Nan<T>()) , 1);
  STF_EQUAL(if_one_else_zero(bs::Zero<T>()),0);
} // end of test for floating_

STF_CASE_TPL (" if_one_else_zero signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_one_else_zero;
  using bs::logical;

  // return type conformity test
  STF_EXPR_IS( if_one_else_zero(T()),  T);

  // specific values tests
  STF_EQUAL(if_one_else_zero(T(0)), 0);
  STF_EQUAL(if_one_else_zero(T(1)), 1);
} // end of test for signed_int_

STF_CASE_TPL (" if_one_else_zero real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_one_else_zero;
  using r_t = decltype( if_one_else_zero(T()));

  // return type conformity test
  STF_EXPR_IS( if_one_else_zero(T()),  T);


  // specific values tests
  STF_EQUAL(if_one_else_zero(-bs::Zero<T>()), r_t(false));
  STF_EQUAL(if_one_else_zero(bs::Half<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Inf<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Minf<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Mone<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Nan<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::One<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Quarter<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Two<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Zero<T>()), r_t(false));
} // end of test for floating_

STF_CASE_TPL (" if_one_else_zerosigned_int__1_0",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_one_else_zero;
  using r_t = decltype( if_one_else_zero(T()));

  // return type conformity test
   STF_EXPR_IS( if_one_else_zero(T()),  T);

  // specific values tests
  STF_EQUAL(if_one_else_zero(bs::Mone<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::One<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Two<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Zero<T>()), r_t(false));
} // end of test for signed_int_

STF_CASE_TPL (" if_one_else_zerounsigned_int__1_0",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_one_else_zero;
  using r_t = decltype( if_one_else_zero(T()));

  // return type conformity test
  STF_EXPR_IS( if_one_else_zero(T()),  T);

  // specific values tests
  STF_EQUAL(if_one_else_zero(bs::One<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Two<T>()), r_t(true));
  STF_EQUAL(if_one_else_zero(bs::Zero<T>()), r_t(false));
} // end of test for unsigned_int_





