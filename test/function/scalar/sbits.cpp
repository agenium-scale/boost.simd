//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sbits.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" sbits real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sbits;
  using r_t = decltype(sbits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(sbits(bs::Nan<T>()), bs::Mone<r_t>());
#endif
  STF_EQUAL(sbits(bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" sbits unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sbits;
  using r_t = decltype(sbits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, signed>));

  // specific values tests
  STF_EQUAL(sbits(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(sbits(bs::Valmax<T>()), bs::Mone<r_t>());
  STF_EQUAL(sbits(bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" sbits signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sbits;
  using r_t = decltype(sbits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);


  // specific values tests
  STF_EQUAL(sbits(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(sbits(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(sbits(bs::Zero<T>()), bs::Zero<r_t>());
}

