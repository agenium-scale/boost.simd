//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Check return type from ceil", STF_NUMERIC_TYPES)
{
  using bs::ceil;
  STF_TYPE_IS(decltype(ceil(T())), T);
}

STF_CASE_TPL( "Check ceil behavior on IEEE types",  STF_IEEE_TYPES)
{
  using bs::ceil;

  STF_EQUAL(ceil(T(2.5)), T(3));
  STF_EQUAL(ceil(T(1.6)), T(2));
  STF_EQUAL(ceil(T(1.5)), T(2));
  STF_EQUAL(ceil(T(1.4)), T(2));
  STF_EQUAL(ceil(T(0)), T(0));
  STF_EQUAL(ceil(T(-1.4)), T(-1));
  STF_EQUAL(ceil(T(-1.5)), T(-1));
  STF_EQUAL(ceil(T(-1.6)), T(-1));
  STF_EQUAL(ceil(T(-2.5)), T(-2));
}

STF_CASE_TPL( "Check ceil behavior on limit cases", STF_NUMERIC_TYPES)
{
  using bs::ceil;
  using bs::Valmin;
  using bs::Valmax;

  STF_EQUAL(ceil(Valmin<T>()), Valmin<T>());
  STF_EQUAL(ceil(Valmax<T>()), Valmax<T>());
}

STF_CASE_TPL( "Check ceil behavior on IEEE limit cases", STF_IEEE_TYPES)
{
  using bs::ceil;
  using bs::Valmin;
  using bs::Valmax;
  using bs::Inf;
  using bs::Minf;
  using bs::Nan;
  using bs::Maxflint;

  STF_EQUAL(ceil(Inf<T>()) , Inf<T>());
  STF_EQUAL(ceil(Minf<T>()), Minf<T>());
  STF_IEEE_EQUAL(ceil(Nan<T>()) , Nan<T>());
  STF_EQUAL(ceil(Maxflint<T>()+1) , Maxflint<T>()+1);
  STF_EQUAL(ceil(Maxflint<T>()  ) , Maxflint<T>()  );
  STF_EQUAL(ceil(Maxflint<T>()-1) , Maxflint<T>()-1);
}

STF_CASE_TPL( "Check ceil behavior on integral types",  STF_INTEGRAL_TYPES)
{
  using bs::ceil;

  STF_EQUAL(ceil(T(2)), T(2));
  STF_EQUAL(ceil(T(1)), T(1));
  STF_EQUAL(ceil(T(0)), T(0));
  STF_EQUAL(ceil(T(-1)), T(-1));
  STF_EQUAL(ceil(T(-2)), T(-2));
}
