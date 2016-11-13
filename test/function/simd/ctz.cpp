//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/ctz.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/signmask.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;
  using iT =  bd::as_integer_t<T>;
  using i_t=  bs::pack<iT, N>;

  T a1[N];
  iT b[N];

  a1[0] = T(1);
  b[0]  = bs::ctz(a1[0]);

  for(std::size_t i = 1; i < N; ++i)
  {
    a1[i] = T(bs::max(T(a1[i-1]*3), T(1)));
    b[i]  = bs::ctz(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  i_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::ctz(aa1), bb);
}

STF_CASE_TPL("Check ctz on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" ctz real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ctz;
  using r_t = decltype(ctz(T()));
  // return type conformity test
  STF_EXPR_IS(ctz(T()), bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ctz(bs::Inf<T>()), r_t(bs::Nbmantissabits<T>()));
  STF_EQUAL(ctz(bs::Minf<T>()), r_t(bs::Nbmantissabits<T>()));
#endif
  STF_EQUAL(ctz(bs::Zero<T>()), r_t(sizeof(T)*8));
  STF_EQUAL(ctz(bs::Signmask<T>()), r_t(sizeof(T)*8-1));
} // end of test for real_

STF_CASE_TPL (" ctz signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::ctz;
  using bs::Nbmantissabits;
  using bs::Signmask;
  using p_t = bs::pack<T>;


  using r_t = decltype(ctz(p_t()));

  for(std::size_t j=0; j< (sizeof(T)*CHAR_BIT-1); j++)
  {
  namespace bs = boost::simd;
    // Test 01111 ... 10000b
    T value = ~T(0) & ~((T(1)<<j)-1);
    STF_EQUAL(ctz( p_t(value) ), r_t(j));
    STF_EQUAL(ctz( p_t(-value) ), r_t(j));
  }

  STF_EQUAL(ctz(Signmask<p_t>()) , r_t(sizeof(T)*CHAR_BIT-1) );
}

STF_CASE_TPL(" ctz unsigned_integer", STF_UNSIGNED_INTEGRAL_TYPES )
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ctz;
  using p_t = bs::pack<T>;

  using r_t = decltype(ctz(p_t()));

  // return type conformity test
  STF_EXPR_IS(ctz(p_t()), bd::as_integer_t<p_t>);

  // specific values tests
  for(std::size_t j=0; j< sizeof(T)*CHAR_BIT; j++)
  {
    // Test 1111 ... 10000b
    T value = ~T(0) & ~((T(1)<<j)-1);
    STF_EQUAL(ctz( p_t(value) ), r_t(j));
  }
 }
