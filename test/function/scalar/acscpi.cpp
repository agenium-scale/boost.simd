//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acscpi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" acscpi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acscpi;

  using r_t = decltype(acscpi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(acscpi(bs::Inf<T>()), T(0), 0.5);
  STF_ULP_EQUAL(acscpi(bs::Minf<T>()), T(0), 0.5);
  STF_ULP_EQUAL(acscpi(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(acscpi(bs::Zero<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(acscpi(-bs::Two<T>()), T(-1/6.0), 0.5);
  STF_ULP_EQUAL(acscpi(bs::Mone<T>()), T(-0.5), 0.5);
  STF_ULP_EQUAL(acscpi(bs::One<T>()),  T(0.5), 0.5);
  STF_ULP_EQUAL(acscpi(bs::Two<T>()),  T(1/6.0), 0.5);
}
