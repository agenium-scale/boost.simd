//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/floor.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/three.hpp>


STF_CASE_TPL (" floor real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::floor;
  using r_t = decltype(floor(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(floor(bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(floor(bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(floor(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(floor(bs::One<T>()), bs::One<T>());
  STF_EQUAL(floor(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(floor(bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(floor(bs::Pi<T>()), bs::Three<T>());
  STF_EQUAL(floor(T(-1.1)), r_t(-2));
  STF_EQUAL(floor(T(1.1)), r_t(1));
} // end of test for floating_

STF_CASE_TPL (" floor unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::floor;

  // return type conformity test
  STF_EXPR_IS(floor(T()), T);

  // specific values tests
  STF_EQUAL(floor(bs::One<T>()), bs::One<T>());
  STF_EQUAL(floor(bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" floor signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::floor;

  // return type conformity test
   STF_EXPR_IS(floor(T()), T);

  // specific values tests
  STF_EQUAL(floor(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(floor(bs::One<T>()), bs::One<T>());
  STF_EQUAL(floor(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_


