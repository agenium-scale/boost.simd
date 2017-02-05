//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/scalar/trunc.hpp>
#include <boost/simd/function/raw.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Check return type from raw_(trunc)", STF_NUMERIC_TYPES)
{
  using bs::trunc;
  using bs::raw_;
  STF_TYPE_IS(decltype(raw_(trunc)(T())), T);
}

STF_CASE_TPL( "Check raw_(trunc) behavior on IEEE types",  STF_IEEE_TYPES)
{
  using bs::trunc;
  using bs::raw_;

  STF_EQUAL(raw_(trunc)(T(2.5)), T(2));
  STF_EQUAL(raw_(trunc)(T(1.6)), T(1));
  STF_EQUAL(raw_(trunc)(T(1.5)), T(1));
  STF_EQUAL(raw_(trunc)(T(1.4)), T(1));
  STF_EQUAL(raw_(trunc)(T(0)), T(0));
  STF_EQUAL(raw_(trunc)(T(-1.4)), T(-1));
  STF_EQUAL(raw_(trunc)(T(-1.5)), T(-1));
  STF_EQUAL(raw_(trunc)(T(-1.6)), T(-1));
  STF_EQUAL(raw_(trunc)(T(-2.5)), T(-2));
}

STF_CASE_TPL( "Check raw_(trunc) behavior on integral types",  STF_INTEGRAL_TYPES)
{
  using bs::trunc;
  using bs::raw_;

  STF_EQUAL(raw_(trunc)(T(2)), T(2));
  STF_EQUAL(raw_(trunc)(T(1)), T(1));
  STF_EQUAL(raw_(trunc)(T(0)), T(0));
  STF_EQUAL(raw_(trunc)(T(-1)), T(-1));
  STF_EQUAL(raw_(trunc)(T(-2)), T(-2));
}
