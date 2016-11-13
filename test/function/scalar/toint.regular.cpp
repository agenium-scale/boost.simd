//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/toint.hpp>
#include <boost/simd/function/fast.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" toint real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::toint;
  using r_t = decltype(toint(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, signed>));

  // specific values tests
  STF_EQUAL(toint(T(0.4)), r_t(0));
  STF_EQUAL(toint(T(0.5)), r_t(0));
  STF_EQUAL(toint(T(0.6)), r_t(0));
  STF_EQUAL(toint(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(toint(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(toint(bs::Zero<T>()), bs::Zero<r_t>());

} // end of test for floating_

STF_CASE_TPL (" toint unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::toint;
  using r_t = decltype(toint(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, signed>));

  // specific values tests
  STF_EQUAL(toint(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(toint(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" toint signed",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::toint;
  using r_t = decltype(toint(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, signed>));

  // specific values tests
  STF_EQUAL(toint(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(toint(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(toint(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_


