//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/logical_not.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" logical_not ",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_not;
  using bs::logical;


  using r_t = decltype(logical_not(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,logical<T>);

  // specific values tests
  STF_EQUAL(logical_not(T(1)), r_t(false));
  STF_EQUAL(logical_not(T(0)), r_t(true));
} // end of test for integer_


STF_CASE_TPL (" logical_not logical",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_not;
  using lT =  bs::logical<T>;

  using r_t = decltype(logical_not(lT()));

  // return type conformity test
  STF_TYPE_IS(r_t,lT);

  // specific values tests
  STF_EQUAL(logical_not(bs::True<lT>()), r_t(false));
  STF_EQUAL(logical_not(bs::False<lT>()), r_t(true));
} // end of test for logical_


