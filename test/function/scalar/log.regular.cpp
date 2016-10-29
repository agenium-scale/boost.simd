//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" log",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log;

  using r_t = decltype(log(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(log(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(log(bs::Mone<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Mzero<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Zero<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Two<T>()), bs::Log_2<r_t>(), 0);
}


