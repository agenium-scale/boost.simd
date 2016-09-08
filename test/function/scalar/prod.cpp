//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/prod.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" prod ",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;

  using bs::prod;

  // return type conformity test
   STF_EXPR_IS(prod(T()), T);

  // specific values tests
  STF_EQUAL(prod(bs::One<T>()), bs::One<T>());
  STF_EQUAL(prod(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_


