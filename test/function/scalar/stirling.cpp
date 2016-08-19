//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/stirling.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/function/round.hpp>

STF_CASE_TPL(" stirling",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::stirling;

  STF_EXPR_IS(stirling(T()),T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(stirling(bs::Inf<T>()),  bs::Inf<T>(), 0.5);
  STF_ULP_EQUAL(stirling(bs::Minf<T>()), bs::Nan<T>(), 0.5);
  STF_ULP_EQUAL(stirling(bs::Mone<T>()), bs::Nan<T>(), 0.5);
  STF_ULP_EQUAL(stirling(bs::Nan<T>()),  bs::Nan<T>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::round(stirling(bs::One<T>())),  bs::One<T>(), 0.5);
  STF_ULP_EQUAL(bs::round(stirling(bs::Two<T>())),  bs::One<T>(), 0.5);
}
