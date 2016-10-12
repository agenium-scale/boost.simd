//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ffs.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/signmask.hpp>

STF_CASE_TPL (" ffs real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::ffs;
  using r_t = decltype(ffs(T()));
  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T>));


  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ffs(bs::Inf<T>()), r_t(bs::Nbmantissabits<T>()+1));
  STF_EQUAL(ffs(bs::Minf<T>()), r_t(bs::Nbmantissabits<T>()+1));
  STF_EQUAL(ffs(bs::Nan<T>()), r_t(bs::One<r_t>()));
#endif
  STF_EQUAL(ffs(bs::Signmask<T>()), r_t(sizeof(T)*8));
  STF_EQUAL(ffs(bs::Zero<T>()), r_t(bs::Zero<r_t>()));
} // end of test for real_

STF_CASE_TPL (" ffs signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::ffs;
  using r_t = decltype(ffs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T>));

  // specific values tests
  STF_EQUAL(ffs(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(ffs(bs::Signmask<T>()), r_t(sizeof(T)*8));
  STF_EQUAL(ffs(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_

STF_CASE_TPL (" ffs unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::ffs;
  using r_t = decltype(ffs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T>));

  // specific values tests
  STF_EQUAL(ffs(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(ffs(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_


