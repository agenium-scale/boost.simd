//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/pow.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/eight.hpp>
#include <boost/simd/constant/third.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>

STF_CASE_TPL("pow std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using r_t =  decltype(pow(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::std_(pow)(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(pow)(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(pow)(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(pow)(bs::Inf<T>(), bs::Minf<T>()), bs::Zero<r_t>(), 0);
#endif
  STF_ULP_EQUAL(bs::std_(pow)(T(-1),T(6)), T(1), 0);
  STF_ULP_EQUAL(bs::std_(pow)(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(pow)(bs::One<T>(), bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(pow)(bs::Zero<T>(), bs::Zero<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(pow)(T(-1),T(5)), T(-1), 0);
  STF_ULP_EQUAL(bs::std_(pow)(bs::Zero<T>(), bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(pow)(T(8),bs::Third<T>()), r_t(2), 0.5);
}
