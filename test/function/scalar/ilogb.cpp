//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ilogb.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/four.hpp>

STF_CASE_TPL (" ilogb real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilogb;
  using r_t = decltype(ilogb(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T>));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ilogb(bs::Minf<T>()), bs::Valmax<r_t>());
  STF_EQUAL(ilogb(bs::Inf<T>()), bs::Valmax<r_t>());
  STF_EQUAL(ilogb(bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(ilogb(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Two<T>()), bs::One<r_t>());
  STF_EQUAL(ilogb(bs::Four<T>()), bs::Two<r_t>());
  STF_EQUAL(ilogb(bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" ilogb unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilogb;
  using r_t = decltype(ilogb(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T>));

  // specific values tests
  STF_EQUAL(ilogb(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Two<T>()), bs::One<r_t>());
  STF_EQUAL(ilogb(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Four<T>()), bs::Two<r_t>());
}

STF_CASE_TPL (" ilogb signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilogb;
  using r_t = decltype(ilogb(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T>));

  // specific values tests
  STF_EQUAL(ilogb(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Two<T>()), bs::One<r_t>());
  STF_EQUAL(ilogb(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Four<T>()), bs::Two<r_t>());
}


