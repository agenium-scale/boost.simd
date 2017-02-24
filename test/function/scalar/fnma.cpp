//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/fnma.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

STF_CASE_TPL(" fnma",  STF_SIGNED_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::fnma;


  STF_EXPR_IS(fnma(T(),T(),T()), T);

  STF_EQUAL(fnma(T(4),T(2),T(2)) , T(-10));
  STF_EQUAL(fnma(T(4),T(-2),T(2)), T(6));
  STF_EQUAL(fnma(T(4),T(2),T(-2)), T(-6));
  STF_EQUAL(fnma(T(4),T(-2),T(-2)), T(10));
}


