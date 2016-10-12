//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/firstbitset.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>

STF_CASE_TPL (" firstbitset real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::firstbitset;
  using r_t = decltype(firstbitset(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,(bd::as_integer_t<T, unsigned>));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(firstbitset(bs::Inf<T>()), r_t(1ull<<bs::Nbmantissabits<T>()));
  STF_EQUAL(firstbitset(bs::Minf<T>()), r_t(1ull<<bs::Nbmantissabits<T>()));
  STF_EQUAL(firstbitset(bs::Nan<T>()), bs::One<r_t>());
#endif
  STF_EQUAL(firstbitset(bs::Signmask<T>()), bs::One<r_t>()+bs::Valmax<r_t>()/2);
  STF_EQUAL(firstbitset(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for real_

STF_CASE_TPL (" firstbitset signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::firstbitset;
  using r_t = decltype(firstbitset(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,(bd::as_integer_t<T, unsigned>));

  // specific values tests
  STF_EQUAL(firstbitset(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(firstbitset(bs::Signmask<T>()), bs::One<r_t>()+bs::Valmax<r_t>()/2);
  STF_EQUAL(firstbitset(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_

STF_CASE_TPL (" firstbitset unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::firstbitset;
  using r_t = decltype(firstbitset(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,(bd::as_integer_t<T, unsigned>));

  // specific values tests
  STF_EQUAL(firstbitset(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(firstbitset(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_


