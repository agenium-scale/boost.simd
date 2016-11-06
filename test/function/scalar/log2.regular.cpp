//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/log2.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" log2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log2;

  using r_t = decltype(log2(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(log2(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(log2(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log2(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log2(bs::Mone<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log2(bs::Zero<T>()), bs::Minf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(log2(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log2(T(2)), T(1), 0);
  STF_ULP_EQUAL(log2(T(8)), T(3), 0);
  STF_ULP_EQUAL(log2(T(64)), T(6), 0);
}

STF_CASE_TPL (" log2int",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log2;

  using r_t = decltype(log2(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_ULP_EQUAL(log2(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log2(T(2)), T(1), 0);
  STF_ULP_EQUAL(log2(T(8)), T(3), 0);
  STF_ULP_EQUAL(log2(T(64)), T(6), 0);
}

