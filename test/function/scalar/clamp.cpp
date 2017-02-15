//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/clamp.hpp>
#include <boost/simd/constant/nan.hpp>
#include <scalar_test.hpp>


STF_CASE_TPL(" clamp",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::clamp;

  STF_EXPR_IS(clamp(T(),T(),T()), T);

  STF_EQUAL(clamp(T(1),T(2),T(4)) ,T(2));
  STF_EQUAL(clamp(T(2),T(2),T(4)), T(2));
  STF_EQUAL(clamp(T(3),T(2),T(4)), T(3));
  STF_EQUAL(clamp(T(4),T(2),T(4)), T(4));
  STF_EQUAL(clamp(T(5),T(2),T(4)), T(4));
}

STF_CASE_TPL(" clamp pedantic on nan",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::clamp;

  auto nan =  bs::Nan<T>();
  STF_IEEE_EQUAL(bs::pedantic_(clamp)(T(nan),T(2),T(4)) , nan);
}




