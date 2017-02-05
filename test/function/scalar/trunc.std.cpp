//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/scalar/trunc.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Check return type from std_(trunc)", STF_NUMERIC_TYPES)
{
  using bs::trunc;
  using bs::std_;

  STF_TYPE_IS(decltype(std_(trunc)(T())), T);
}

STF_CASE_TPL( "Check std_(trunc) behavior on IEEE types",  STF_IEEE_TYPES)
{
  using bs::trunc;
  using bs::std_;

  STF_EQUAL(std_(trunc)(T(2.5)), T(2));
  STF_EQUAL(std_(trunc)(T(1.6)), T(1));
  STF_EQUAL(std_(trunc)(T(1.5)), T(1));
  STF_EQUAL(std_(trunc)(T(1.4)), T(1));
  STF_EQUAL(std_(trunc)(T(0)), T(0));
  STF_EQUAL(std_(trunc)(T(-1.4)), T(-1));
  STF_EQUAL(std_(trunc)(T(-1.5)), T(-1));
  STF_EQUAL(std_(trunc)(T(-1.6)), T(-1));
  STF_EQUAL(std_(trunc)(T(-2.5)), T(-2));
}

STF_CASE_TPL( "Check std_(trunc) behavior on limit cases", STF_NUMERIC_TYPES)
{
  using bs::trunc;
  using bs::std_;
  using bs::Valmin;
  using bs::Valmax;

  STF_EQUAL(std_(trunc)(Valmin<T>()), Valmin<T>());
  STF_EQUAL(std_(trunc)(Valmax<T>()), Valmax<T>());
}

STF_CASE_TPL( "Check std_(trunc) behavior on IEEE limit cases", STF_IEEE_TYPES)
{
  using bs::trunc;
  using bs::std_;
  using bs::Valmin;
  using bs::Valmax;
  using bs::Inf;
  using bs::Minf;
  using bs::Nan;
  using bs::Maxflint;

  STF_EQUAL(std_(trunc)(Inf<T>()) , Inf<T>());
  STF_EQUAL(std_(trunc)(Minf<T>()), Minf<T>());
  STF_IEEE_EQUAL(std_(trunc)(Nan<T>()) , Nan<T>());
  STF_EQUAL(std_(trunc)(Maxflint<T>()+1) , Maxflint<T>()+1);
  STF_EQUAL(std_(trunc)(Maxflint<T>()  ) , Maxflint<T>()  );
  STF_EQUAL(std_(trunc)(Maxflint<T>()-1) , Maxflint<T>()-1);
}

STF_CASE_TPL( "Check std_(trunc) behavior on integral types",  STF_INTEGRAL_TYPES)
{
  using bs::trunc;
  using bs::std_;

  STF_EQUAL(std_(trunc)(T(2)), T(2));
  STF_EQUAL(std_(trunc)(T(1)), T(1));
  STF_EQUAL(std_(trunc)(T(0)), T(0));
  STF_EQUAL(std_(trunc)(T(-1)), T(-1));
  STF_EQUAL(std_(trunc)(T(-2)), T(-2));
}
