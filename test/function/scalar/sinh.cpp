//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sinh.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>

STF_CASE_TPL (" sinh",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sinh;
  using r_t = decltype(sinh(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sinh(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(sinh(bs::Minf<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(sinh(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(sinh(bs::Zero<T>()), bs::Zero<r_t>(), 0);
  STF_EXPECT(bs::is_negative(bs::sinh(bs::Mzero<T>() )));
  STF_EXPECT(bs::is_positive(bs::sinh(bs::Zero<T>() )));
  STF_ULP_EQUAL(sinh(bs::One<T>()),T(1.1752011936438014568823818506), 0.5);
  STF_ULP_EQUAL(sinh(bs::Mone<T>()), T(-1.1752011936438014568823818506), 0.5);
  STF_ULP_EQUAL(sinh(bs::Half<T>()), T(0.52109530549374736162242562641149), 0.5);
}
