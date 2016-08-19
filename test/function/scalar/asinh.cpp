//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/asinh.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/eps.hpp>
#include <cmath>

STF_CASE_TPL (" asinh",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::asinh;
  using r_t = decltype(asinh(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(asinh(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(asinh(bs::Minf<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(asinh(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(asinh(bs::Zero<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(asinh(bs::Valmax<T>()), std::asinh(bs::Valmax<T>()), 0.5);
  STF_ULP_EQUAL(asinh(bs::rec(bs::Sqrteps<T>())*2),  std::asinh(bs::rec(bs::Sqrteps<T>())*2), 0.5);
  STF_ULP_EQUAL(asinh(bs::Eps<T>()), bs::Eps<T>(), 0.5);
 for(T i=T(0.1); i <= T(1.1); i+= T(0.5))
 {
   T ri =  bs::rec(i);
   STF_ULP_EQUAL(asinh(i), std::asinh(i), 0.5);
   STF_ULP_EQUAL(asinh(ri), std::asinh(ri), 0.5);
 }
}

