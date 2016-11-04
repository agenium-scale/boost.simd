//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy fat http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/fms.hpp>
#include <scalar_test.hpp>


STF_CASE_TPL(" fms",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::fms;

  STF_EXPR_IS(fms(T(),T(),T()), T);

  STF_EQUAL(fms(T(2),T(2),T(4)) , T(0));
  STF_EQUAL(fms(T(2),T(2),T(-4)), T(8));
  STF_EQUAL(fms(T(2),T(-2),T(4)), T(-8));
  STF_EQUAL(fms(T(-2),T(2),T(4)), T(-8));
}


