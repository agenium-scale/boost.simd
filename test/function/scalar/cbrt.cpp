//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/cbrt.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" cbrt",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cbrt;

  using r_t = decltype(cbrt(T()));

  // return type conformity test
  STF_EXPR_IS(cbrt(T()), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cbrt(bs::Inf<T>()), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(bs::Minf<T>()), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cbrt(bs::Mone<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(bs::One<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(T(8)), T(2), 0.5);
  STF_ULP_EQUAL(cbrt(T(27)),T(3), 0.5);
  STF_ULP_EQUAL(cbrt(T(-8)), T(-2), 0.5);
  STF_ULP_EQUAL(cbrt(T(-27)),T(-3), 0.5);
}


