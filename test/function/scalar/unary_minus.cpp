//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/unary_minus.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/saturated.hpp>

STF_CASE_TPL (" unary_minus real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::unary_minus;

  using r_t = decltype(unary_minus(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(unary_minus(bs::Inf<T>()), bs::Minf<r_t>());
  STF_EQUAL(unary_minus(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(unary_minus(bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(unary_minus(bs::One<T>()), bs::Mone<r_t>());
  STF_EQUAL(unary_minus(bs::Zero<T>()), bs::Mzero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" unary_minus signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::unary_minus;
  using r_t = decltype(unary_minus(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(unary_minus(bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(unary_minus(bs::One<T>()), bs::Mone<r_t>());
  STF_EQUAL(unary_minus(bs::Two<T>()), -bs::Two<r_t>());
  STF_EQUAL(unary_minus(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_STF_CASE("unary_minus TO DO")

