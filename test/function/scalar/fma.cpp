//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/fma.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" fma real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::fma;

  // return type conformity test
  STF_EXPR_IS(fma(T(),T(),T()), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(fma(bs::Inf<T>(), bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>(), 0.5);
  STF_ULP_EQUAL(fma(bs::Minf<T>(), bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>(), 0.5);
  STF_ULP_EQUAL(fma(bs::Nan<T>(), bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>(), 0.5);
#endif
  STF_ULP_EQUAL(fma(bs::Mone<T>(), bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>(), 0.5);
  STF_ULP_EQUAL(fma(bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::Two<T>(), 0.5);
  STF_ULP_EQUAL(fma(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>(), 0.5);
} // end of test for floating_

STF_CASE_TPL (" fma unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::fma;

  // return type conformity test
  STF_EXPR_IS(fma(T(),T(),T()), T);

  // specific values tests
  STF_EQUAL(fma(bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(fma(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" fma signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::fma;

  // return type conformity test
  STF_EXPR_IS(fma(T(),T(),T()), T);

  // specific values tests
  STF_EQUAL(fma(bs::Mone<T>(), bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(fma(bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(fma(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_
