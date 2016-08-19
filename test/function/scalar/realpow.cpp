//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/realpow.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" realpow",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::realpow;

  using r_t = decltype(realpow(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(realpow(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(realpow(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(realpow(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(realpow(bs::One<T>(), bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(realpow(bs::Zero<T>(), bs::Zero<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(realpow(T(-1),T(5)), T(-1), 0);
  STF_ULP_EQUAL(realpow(T(-1),T(6)), T(1), 0);
}
