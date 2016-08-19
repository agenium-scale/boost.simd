//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/signgam.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/mhalf.hpp>



STF_CASE_TPL (" signgam",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::signgam;
  using r_t = decltype(signgam(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(signgam(bs::Inf<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(signgam(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(signgam(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(signgam(bs::Mone<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(signgam(bs::Zero<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(signgam(bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(signgam(bs::Mhalf<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(signgam(T(-1.5)), bs::One<r_t>(), 0);
}
