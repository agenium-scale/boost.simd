//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/clz.hpp>
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

STF_CASE_TPL (" clz real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;


  using bs::clz;
  using r_t = decltype(clz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(clz(bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(clz(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(clz(bs::Signmask<T>()),bs::Zero<r_t>());
} // end of test for real_

STF_CASE_TPL (" clz signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::clz;
  using r_t = decltype(clz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(clz(bs::One<T>()), r_t(sizeof(T)*8 -1));
  STF_EQUAL(clz(bs::Signmask<T>()), bs::Zero<r_t>());
} // end of test for signed_int_

 STF_CASE_TPL (" clz unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
 {
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::clz;
  using r_t = decltype(clz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(clz(bs::One<T>()),  r_t(sizeof(T)*8-bs::One<r_t>()));

  T j = 1;
  for(int i=1; i < bs::Valmax<char>(); i*= 2)
    {
      STF_EQUAL(clz(T(i)),T(sizeof(T)*8- T(j)));
      ++j;
    }
 } // end of test for unsigned_int_


