//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/b_andnot.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" b_andnot real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::b_andnot;
  using r_t = decltype(b_andnot(T(), T()));
  typedef T wished_r_t;


  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(b_andnot(bs::Inf<T>(), bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(b_andnot(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>());
  STF_EQUAL(b_andnot(bs::Nan<T>(), bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(b_andnot(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(b_andnot(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" b_andnot integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::b_andnot;
  using r_t = decltype(b_andnot(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(b_andnot(bs::One<T>(), bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(b_andnot(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(b_andnot(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_


STF_CASE_TPL("b_andnot mix", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::b_andnot;
  using siT = bd::as_integer_t<T>;
  using uiT = bd::as_integer_t<T, unsigned>;

  // return type conformity test
  STF_EXPR_IS(b_andnot(T(),uiT()), T);
  STF_EXPR_IS(b_andnot(T(),siT()), T);
  STF_EXPR_IS(b_andnot(uiT(), T()), uiT);
  STF_EXPR_IS(b_andnot(siT(), T()), siT);

  // specific values tests
  STF_IEEE_EQUAL(b_andnot(bs::Nan<T>(),bs::Zero<uiT>()), bs::Nan<T>());
  STF_IEEE_EQUAL(b_andnot(bs::Nan<T>(), bs::Zero<siT>()), bs::Nan<T>());
  STF_EQUAL(b_andnot(bs::Mone<siT>(),bs::Zero<T>()), bs::Mone<siT>());
  STF_EQUAL(b_andnot(bs::Valmax<uiT>(), bs::Zero<T>()), bs::Valmax<uiT>());
}


