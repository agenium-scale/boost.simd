//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/hypot.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>

STF_CASE_TPL (" hypot real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::hypot;
  using r_t = decltype(bs::pedantic_(hypot)(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::Minf<T>(), bs::Minf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::Nan<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::Inf<T>(), bs::Nan<T>()), bs::Inf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::Mone<T>(), bs::Mone<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::One<T>(), bs::One<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>(), 0);
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>(), 0);
  STF_ULP_EQUAL(bs::pedantic_(hypot)(bs::Zero<T>(), bs::Valmax<T>()), bs::Valmax<T>(), 0);
} // end of test for floating_

