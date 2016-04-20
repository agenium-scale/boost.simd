//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/toint_s.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/ldexp.hpp>

STF_CASE_TPL (" toint_s real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::toint_s;
  using r_t = decltype(toint_s(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, signed>));

  // specific values tests
  STF_EQUAL(toint_s(T(2)*bs::Valmax<r_t>()),  bs::Valmax<r_t>());
  STF_EQUAL(toint_s(T(2)*bs::Valmin<r_t>()),  bs::Valmin<r_t>());
  STF_EQUAL(toint_s(T(1.5)*bs::Valmax<r_t>()),  bs::Valmax<r_t>());
  STF_EQUAL(toint_s(T(1.5)*bs::Valmin<r_t>()),  bs::Valmin<r_t>());


  STF_EQUAL(toint_s(bs::Inf<T>()),  bs::Inf<r_t>());
  STF_EQUAL(toint_s(bs::Minf<T>()), bs::Minf<r_t>());
  STF_EQUAL(toint_s(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(toint_s(bs::Nan<T>()),  bs::Zero<r_t>());
  STF_EQUAL(toint_s(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(toint_s(bs::Zero<T>()), bs::Zero<r_t>());

  T v = T(1);
  r_t iv = 1;
  int N = sizeof(T)*8-1;
  for(int i=0; i < N ; i++, v*= 2, iv <<= 1)
  {
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
    STF_EQUAL(toint_s(v), iv);
    STF_EQUAL(toint_s(-v), -iv);
  }
  STF_EQUAL(toint_s(bs::ldexp(bs::One<T>(), N)), bs::Valmax<r_t>());
  STF_EQUAL(toint_s(bs::ldexp(bs::One<T>(), N+1)), bs::Valmax<r_t>());
  STF_EQUAL(toint_s(-bs::ldexp(bs::One<T>(), N+1)), bs::Valmin<r_t>());
  STF_EQUAL(toint_s(-bs::ldexp(bs::One<T>(), N+1)), bs::Valmin<r_t>());

} // end of test for floating_

STF_CASE_TPL (" toint_s unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::toint_s;
  using r_t = decltype(toint_s(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, signed>));

  // specific values tests
  STF_EQUAL(toint_s(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(toint_s(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" toint_s signed",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::toint_s;
  using r_t = decltype(toint_s(T()));
  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, signed>));


  // specific values tests
  STF_EQUAL(toint_s(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(toint_s(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(toint_s(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_
