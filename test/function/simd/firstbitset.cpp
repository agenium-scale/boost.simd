//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/firstbitset.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;
  using iT =  bd::as_integer_t<T, unsigned>;
  using pi_t = bs::pack<iT, N>;

  T a1[N];
  iT b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = T(i+1);
     b[i] = bs::firstbitset(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  pi_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::firstbitset(aa1), bb);
}

STF_CASE_TPL("Check firstbitset on pack" ,  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL (" firstbitset real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::firstbitset;
  using p_t = bs::pack<T>;
  using r_t = decltype(firstbitset(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t,(bd::as_integer_t<p_t, unsigned>));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(firstbitset(bs::Inf<p_t>()), r_t(1ull<<bs::Nbmantissabits<T>()));
  STF_EQUAL(firstbitset(bs::Minf<p_t>()), r_t(1ull<<bs::Nbmantissabits<T>()));
  STF_EQUAL(firstbitset(bs::Nan<p_t>()), bs::One<r_t>());
#endif
  STF_EQUAL(firstbitset(bs::Signmask<p_t>()), bs::One<r_t>()+bs::Valmax<r_t>()/2);
  STF_EQUAL(firstbitset(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for real_

STF_CASE_TPL (" firstbitset signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::firstbitset;
  using p_t = bs::pack<T>;
  using r_t = decltype(firstbitset(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t,(bd::as_integer_t<p_t, unsigned>));

  // specific values tests
  STF_EQUAL(firstbitset(bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(firstbitset(bs::Signmask<p_t>()), bs::One<r_t>()+bs::Valmax<r_t>()/2);
  STF_EQUAL(firstbitset(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for signed_int_

STF_CASE_TPL (" firstbitset unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::firstbitset;
  using p_t = bs::pack<T>;
  using r_t = decltype(firstbitset(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t,(bd::as_integer_t<p_t, unsigned>));

  // specific values tests
  STF_EQUAL(firstbitset(bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(firstbitset(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for unsigned_int_


