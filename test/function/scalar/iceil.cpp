//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/iceil.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>


STF_CASE_TPL (" iceil real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::iceil;
  using r_t = decltype(iceil(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(iceil(bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(iceil(bs::Minf<T>()), bs::Minf<r_t>());
  STF_EQUAL(iceil(bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(iceil(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(iceil(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iceil(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" iceil unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::iceil;
  using r_t = decltype(iceil(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, unsigned>));

  // specific values tests
  STF_EQUAL(iceil(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iceil(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" iceil signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::iceil;
  using r_t = decltype(iceil(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(iceil(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(iceil(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iceil(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

