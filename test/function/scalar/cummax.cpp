//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/cummax.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" cummax real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::cummax;

  // return type conformity test
  STF_EXPR_IS(cummax(T()), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(cummax(bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(cummax(bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(cummax(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(cummax(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(cummax(bs::One<T>()), bs::One<T>());
  STF_EQUAL(cummax(bs::Zero<T>()), bs::Zero<T>());
} // end of test for floating_

STF_CASE_TPL (" cummax unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::cummax;
  // return type conformity test
  STF_EXPR_IS(cummax(T()), T);


  // specific values tests
  STF_EQUAL(cummax(bs::One<T>()), bs::One<T>());
  STF_EQUAL(cummax(bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" cummax signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::cummax;

  // return type conformity test
  STF_EXPR_IS(cummax(T()), T);

  // specific values tests
  STF_EQUAL(cummax(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(cummax(bs::One<T>()), bs::One<T>());
  STF_EQUAL(cummax(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_



