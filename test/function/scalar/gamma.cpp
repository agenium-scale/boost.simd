//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/gamma.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/five.hpp>
#include <boost/simd/function/rsqrt.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL (" gamma",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::gamma;
  using r_t = decltype(gamma(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(gamma(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(gamma(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(gamma(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(gamma(bs::Zero<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(gamma(bs::Mzero<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(gamma(T(1)), T(1), 0);
  STF_ULP_EQUAL(gamma(T(2)), T(1), 0);
  STF_ULP_EQUAL(gamma(T(3)), T(2), 0);
  STF_ULP_EQUAL(gamma(T(5)), T(24), 0);
 }
