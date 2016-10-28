//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/log10.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/three.hpp>


STF_CASE_TPL (" log10 std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;

  using r_t = decltype(log10(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::std_(log10)(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(log10)(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(log10)(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(log10)(bs::Mone<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(log10)(bs::Zero<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(log10)(bs::Mzero<T>()), bs::Minf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(bs::std_(log10)(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(log10)(bs::Two<T>()), T(0.301029995663981195213738894724), 0);
}
