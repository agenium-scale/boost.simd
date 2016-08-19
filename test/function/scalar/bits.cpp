//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bits.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" bits real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::bits;
  using r_t = decltype(bits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, unsigned>));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(bits(bs::Nan<T>()), bs::Mone<r_t>());
#endif
  STF_EQUAL(bits(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" bits signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::bits;
  using r_t = decltype(bits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, unsigned>));

  // specific values tests
  STF_EQUAL(bits(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(bits(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(bits(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_

STF_CASE_TPL (" bits unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::bits;
  using r_t = decltype(bits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, unsigned>));

  // specific values tests
  STF_EQUAL(bits(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(bits(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_


