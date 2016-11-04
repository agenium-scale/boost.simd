//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/firstbitunset.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/signmask.hpp>

STF_CASE_TPL (" firstbitunsetreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::firstbitunset;
  using r_t = decltype(firstbitunset(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, unsigned>));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(firstbitunset(bs::Inf<T>()), bs::One<r_t>());
  STF_EQUAL(firstbitunset(bs::Minf<T>()), bs::One<r_t>());
  STF_EQUAL(firstbitunset(bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(firstbitunset(bs::Signmask<T>()), bs::One<r_t>());
  STF_EQUAL(firstbitunset(bs::Zero<T>()), bs::One<r_t>());
} // end of test for floating_


