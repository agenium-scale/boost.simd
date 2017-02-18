//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/fnms.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

STF_CASE_TPL(" fnms",  STF_SIGNED_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::fnms;

  STF_EXPR_IS(fnms(T(),T(),T()), T);


  STF_EQUAL(fnms(T(2),T(2),T(4)) , T(0));
  STF_EQUAL(fnms(T(-2),T(2),T(4)), T(8));
  STF_EQUAL(fnms(T(2),T(-2),T(4)), T(8));
  STF_EQUAL(fnms(T(-2),T(-2),T(4)), T(0));
}
