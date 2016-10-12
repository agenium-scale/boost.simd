//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitwise_xor.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" bitwise xor_real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::bitwise_xor;
  using r_t = decltype(bitwise_xor(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bitwise_xor(bs::Inf<T>(), bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitwise_xor(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(bitwise_xor(bs::Nan<T>(), bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(bitwise_xor(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(bitwise_xor(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" bitwise xor_integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::bitwise_xor;
  using r_t = decltype(bitwise_xor(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bitwise_xor(bs::One<T>(), bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitwise_xor(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(bitwise_xor(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_


STF_CASE_TPL("bitwise xor_mix", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::bitwise_xor;
  using siT = bd::as_integer_t<T>;
  using uiT = bd::as_integer_t<T, unsigned>;

  // return type conformity test
  STF_EXPR_IS(bitwise_xor(T(),uiT()), T);
  STF_EXPR_IS(bitwise_xor(T(),siT()), T);
  STF_EXPR_IS(bitwise_xor(uiT(), T()), uiT);
  STF_EXPR_IS(bitwise_xor(siT(), T()), siT);

  // specific values tests
  STF_EQUAL(bitwise_xor(bs::Nan<T>(),bs::Valmax<uiT>()), bs::Zero<T>());
  STF_EQUAL(bitwise_xor(bs::Nan<T>(), bs::Mone<siT>()), bs::Zero<T>());
  STF_EQUAL(bitwise_xor(bs::Mone<siT>(),bs::Zero<T>()), bs::Mone<siT>());
  STF_EQUAL(bitwise_xor(bs::Valmax<uiT>(), bs::Zero<T>()), bs::Valmax<uiT>());
}



