//==================================================================================================
/*!
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/logical_not.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/logical.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL (" logical_not ",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::logical_not;
  using bs::logical;

  using r_t = decltype(logical_not(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,logical<T>);

  // specific values tests
  STF_EQUAL(logical_not(T(1)), r_t(false));
  STF_EQUAL(logical_not(T(0)), r_t(true));
}

STF_CASE_TPL (" logical_not logical",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::logical_not;
  using lT =  bs::logical<T>;

  using r_t = decltype(logical_not(lT()));

  // return type conformity test
  STF_TYPE_IS(r_t,lT);

  // specific values tests
  STF_EQUAL(logical_not(bs::True<lT>()), r_t(false));
  STF_EQUAL(logical_not(bs::False<lT>()), r_t(true));
}
