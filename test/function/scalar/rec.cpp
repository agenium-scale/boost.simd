//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL("regular rec",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rec;

  // return type conformity test
  STF_EXPR_IS( rec(T()) , T );

  // specific values tests
  STF_EQUAL(rec(bs::Inf<T>()), bs::Zero<T>());
  STF_EQUAL(rec(bs::Minf<T>()), bs::Zero<T>());
  STF_EQUAL(rec(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(rec(bs::Mzero<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(rec(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(rec(bs::One<T>()), bs::One<T>());
  STF_EQUAL(rec(bs::Zero<T>()), bs::Inf<T>());
} // end of test for floating_


STF_CASE_TPL("raw rec",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rec;
  using bs::raw_;

  // return type conformity test
  STF_EXPR_IS( bs::raw_(rec)(T()) , T );
  //For scalar is it a call redirected to bs::raw_(rec)
  // specific values tests
  STF_ULP_EQUAL(bs::raw_(rec)(bs::One<T>()) , bs::One<T>()  , 2000);
  STF_ULP_EQUAL(bs::raw_(rec)(bs::Mone<T>()), bs::Mone<T>() , 2000);
  STF_ULP_EQUAL(bs::raw_(rec)(T(7))         , T(1)/T(7)     , 2000);
} // end of test for floating_
