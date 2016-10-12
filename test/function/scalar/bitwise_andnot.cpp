//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitwise_andnot.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" bitwise_andnot real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::bitwise_andnot;
  using r_t = decltype(bitwise_andnot(T(), T()));
  typedef T wished_r_t;


  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bitwise_andnot(bs::Inf<T>(), bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitwise_andnot(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitwise_andnot(bs::Nan<T>(), bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(bitwise_andnot(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(bitwise_andnot(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" bitwise_andnot integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::bitwise_andnot;
  using r_t = decltype(bitwise_andnot(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(bitwise_andnot(bs::One<T>(), bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitwise_andnot(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(bitwise_andnot(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_


STF_CASE_TPL("bitwise_andnot mix", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::bitwise_andnot;
  using siT = bd::as_integer_t<T>;
  using uiT = bd::as_integer_t<T, unsigned>;

  // return type conformity test
  STF_EXPR_IS(bitwise_andnot(T(),uiT()), T);
  STF_EXPR_IS(bitwise_andnot(T(),siT()), T);
  STF_EXPR_IS(bitwise_andnot(uiT(), T()), uiT);
  STF_EXPR_IS(bitwise_andnot(siT(), T()), siT);

  // specific values tests
  STF_IEEE_EQUAL(bitwise_andnot(bs::Nan<T>(),bs::Zero<uiT>()), bs::Nan<T>());
  STF_IEEE_EQUAL(bitwise_andnot(bs::Nan<T>(), bs::Zero<siT>()), bs::Nan<T>());
  STF_EQUAL(bitwise_andnot(bs::Mone<siT>(),bs::Zero<T>()), bs::Mone<siT>());
  STF_EQUAL(bitwise_andnot(bs::Valmax<uiT>(), bs::Zero<T>()), bs::Valmax<uiT>());
}


