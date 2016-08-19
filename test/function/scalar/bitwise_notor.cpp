//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitwise_notor.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/bitincrement.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" bitwise_notor real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::bitwise_notor;
  using r_t = decltype(bitwise_notor(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(bitwise_notor(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(bitwise_notor(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(bitwise_notor(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_IEEE_EQUAL(bitwise_notor(bs::Zero<T>(), bs::Zero<T>()), bs::Nan<r_t>());
} // end of test for floating_

STF_CASE_TPL (" bitwise_notor signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::bitwise_notor;
  using r_t = decltype(bitwise_notor(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bitwise_notor(bs::Mone<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitwise_notor(bs::One<T>(), bs::One<T>()), bs::Mone<r_t>());
  STF_EQUAL(bitwise_notor(bs::Zero<T>(), bs::Zero<T>()), bs::Mone<r_t>());
  STF_EQUAL(bitwise_notor(bs::Zero<T>(),bs::One<T>()), r_t(bs::Mone<r_t>()));
} // end of test for signed_int_

STF_CASE_TPL (" bitwise_notor unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::bitwise_notor;
  using r_t = decltype(bitwise_notor(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bitwise_notor(bs::One<T>(), bs::One<T>()), bs::Mone<r_t>());
  STF_EQUAL(bitwise_notor(bs::Zero<T>(), bs::Zero<T>()), bs::Mone<r_t>());
  STF_EQUAL(bitwise_notor(bs::Zero<T>(),bs::One<T>()), r_t(bs::Mone<r_t>()));
} // end of test for unsigned_int_


STF_CASE_TPL("bitwise_notor mix", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::bitwise_notor;

  using siT = bd::as_integer_t<T>;
  using uiT = bd::as_integer_t<T, unsigned>;

  // return type conformity test
  STF_EXPR_IS(bitwise_notor(T(),uiT()), T);
  STF_EXPR_IS(bitwise_notor(T(),siT()), T);
  STF_EXPR_IS(bitwise_notor(uiT(), T()), uiT);
  STF_EXPR_IS(bitwise_notor(siT(), T()), siT);

   // specific values tests
  STF_EQUAL(bitwise_notor(bs::Nan<T>(),bs::One<uiT>()), bs::Bitincrement<T>());
  STF_EQUAL(bitwise_notor(bs::Nan<T>(), bs::One<siT>()), bs::Bitincrement<T>());
  STF_EQUAL(bitwise_notor(bs::Valmin<siT>(),bs::Zero<T>()), bs::Valmax<siT>());
  STF_EQUAL(bitwise_notor(bs::Zero<uiT>(), bs::Zero<T>()), bs::Valmax<uiT>());
}
