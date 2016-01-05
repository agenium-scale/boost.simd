//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/b_notand.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>


STF_CASE_TPL (" b_notand real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::b_notand;
  using r_t = decltype(b_notand(T(), T()));
  using bs::b_notand;

  // return type conformity test
  STF_EXPR_IS(b_notand(T(), T()), T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(b_notand(bs::Inf<T>(), bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(b_notand(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>());
  STF_EQUAL(b_notand(bs::Nan<T>(), bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(b_notand(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(b_notand(bs::Zero<T>(),bs::One<T>()), bs::One<r_t>());
} // end of test for floating_

STF_CASE_TPL("b_notand mix", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::b_notand;
  using siT = bd::as_integer_t<T>;
  using uiT = bd::as_integer_t<T, unsigned>;

  // return type conformity test
  STF_EXPR_IS(b_notand(T(),uiT()), T);
  STF_EXPR_IS(b_notand(T(),siT()), T);
  STF_EXPR_IS(b_notand(uiT(), T()), uiT);
  STF_EXPR_IS(b_notand(siT(), T()), siT);

  // specific values tests
  STF_IEEE_EQUAL(b_notand(bs::Zero<T>(),bs::Valmax<uiT>()), bs::Nan<T>());
  STF_IEEE_EQUAL(b_notand(bs::Zero<T>(), bs::Mone<siT>()), bs::Nan<T>());
  STF_IEEE_EQUAL(b_notand(bs::Zero<siT>(),bs::Nan<T>()), bs::Mone<siT>());
  STF_EQUAL(b_notand(bs::Zero<uiT>(), bs::Nan<T>()), bs::Valmax<uiT>());
}
