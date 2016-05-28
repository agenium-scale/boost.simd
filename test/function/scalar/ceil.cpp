//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ceil.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/four.hpp>

STF_CASE_TPL (" ceil real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::ceil;
  using r_t = decltype(ceil(T()));
  // return type conformity test
  STF_EXPR_IS(ceil(T()), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ceil(bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(ceil(bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(ceil(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(ceil(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(ceil(bs::One<T>()), bs::One<T>());
  STF_EQUAL(ceil(bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(ceil(bs::Pi<T>()), bs::Four<T>());
  STF_EQUAL(ceil(T(-1.1)), r_t(-1));
  STF_EQUAL(ceil(T(1.1)), r_t(2));
} // end of test for floating_

STF_CASE_TPL (" ceil signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::ceil;

  // return type conformity test
  STF_EXPR_IS(ceil(T()), T);


  // specific values tests
  STF_EQUAL(ceil(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(ceil(bs::One<T>()), bs::One<T>());
  STF_EQUAL(ceil(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

STF_CASE_TPL (" ceil unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::ceil;
  // return type conformity test
  STF_EXPR_IS(ceil(T()), T);


  // specific values tests
  STF_EQUAL(ceil(bs::One<T>()), bs::One<T>());
  STF_EQUAL(ceil(bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_


