//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sqr_abs.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>


STF_CASE_TPL (" sqr_abs real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr_abs;
  using r_t = decltype(sqr_abs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(sqr_abs(bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(sqr_abs(bs::Minf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(sqr_abs(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(sqr_abs(bs::One<T>()), bs::One<T>());
  STF_EQUAL(sqr_abs(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(sqr_abs(bs::Valmax<T>()), bs::Inf<T>());
  STF_EQUAL(sqr_abs(bs::Valmin<T>()), bs::Inf<T>());
  STF_EQUAL(sqr_abs(bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(sqr_abs(T(1)), T(1));
} // end of test for floating_

STF_CASE_TPL (" sqr_absunsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr_abs;
  using r_t = decltype(sqr_abs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sqr_abs(bs::One<T>()), bs::One<T>());
  STF_EQUAL(sqr_abs(bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" sqr_abs signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr_abs;
  using r_t = decltype(sqr_abs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sqr_abs(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(sqr_abs(bs::One<T>()), bs::One<T>());
  STF_EQUAL(sqr_abs(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_
