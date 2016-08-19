//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acosh.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" acosh",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acosh;
  using r_t = decltype(acosh(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(acosh(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(acosh(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(acosh(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(acosh(bs::Zero<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(acosh(bs::One<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(acosh(bs::Two<T>()), T(1.31695789692481670862504634731), 0.5);
}

