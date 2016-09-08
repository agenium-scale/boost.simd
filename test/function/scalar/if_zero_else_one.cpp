//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_zero_else_one.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
STF_CASE_TPL (" if_zero_else_one real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::if_zero_else_one;
  using bs::logical;

  // return type conformity test
  STF_EXPR_IS( if_zero_else_one(T()), T);

  // specific values tests
  STF_EQUAL(if_zero_else_one(T(0)), 1);
  STF_EQUAL(if_zero_else_one(T(1)), 0);
  STF_EQUAL(if_zero_else_one(bs::Inf<T>()) , 0);
  STF_EQUAL(if_zero_else_one(bs::Minf<T>()), 0);
  STF_EQUAL(if_zero_else_one(bs::Nan<T>()) , 0);
  STF_EQUAL(if_zero_else_one(bs::Zero<T>()), 1);


} // end of test for floating_

STF_CASE_TPL (" if_zero_else_onesigned int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_zero_else_one;
  using bs::logical;

  // return type conformity test
  STF_EXPR_IS( if_zero_else_one(T()), T);

  // specific values tests
  STF_EQUAL(if_zero_else_one(T(0)), 1);
  STF_EQUAL(if_zero_else_one(T(1)), 0);
} // end of test for signed_int_


