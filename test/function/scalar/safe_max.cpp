//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/safe_max.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/sqrtvalmax.hpp>


STF_CASE_TPL (" safe_max real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::safe_max;
  using r_t = decltype(safe_max(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(safe_max(bs::Zero<T>()), bs::Inf<r_t>());
  STF_EQUAL(safe_max(bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(safe_max(bs::Minf<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(safe_max(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(safe_max(bs::Mone<T>()), bs::Sqrtvalmax<r_t>());
  STF_EQUAL(safe_max(bs::One<T>()), bs::Sqrtvalmax<r_t>());
}


