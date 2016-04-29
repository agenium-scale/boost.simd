//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/function/bitwise_select.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/meta/cardinal_of.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], a3[N], b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(1) : T(0);
    a2[i] = (i%2) ? T(i+N) : T(-(i+N));
    a3[i] = (i%2) ? T(i+2*N) : T(-(i+2*N));
    b[i] = bs::bitwise_select(a1[i], a2[i], a3[i]);
  }
  p_t aa1(&a1[0], &a1[N]);
  p_t aa2(&a2[0], &a2[N]);
  p_t aa3(&a3[0], &a3[N]);
  p_t bb(&b[0], &b[N]);
  STF_IEEE_EQUAL(bs::bitwise_select(aa1, aa2, aa3), bb);
}

STF_CASE_TPL("Check bitwise_select on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, int N, typename Env>
void testl(Env& $)
{
  namespace bs = boost::simd;
  using lT = bs::logical<T>;
  using p_t = bs::pack<T, N>;
  using pl_t = bs::pack<lT, N>;

  T  a2[N], a3[N], b[N];
  lT a1[N], c[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? bs::True<lT>() : bs::False<lT>();
    a2[i] = (i%2) ? T(i+N) : T(-(i+N));
    a3[i] = (i%2) ? T(i+2*N) : T(-(i+2*N));
    b[i] = bs::bitwise_select(a1[i], a2[i], a3[i]);
    c[i] = bs::bitwise_select(a1[i], bs::is_gtz(a2[i]), bs::is_gtz(a3[i]));
  }
  pl_t aa1(&a1[0], &a1[N]);
  p_t aa2(&a2[0], &a2[N]);
  p_t aa3(&a3[0], &a3[N]);
  p_t bb(&b[0], &b[N]);
  pl_t cc(&c[0], &c[N]);
  STF_EQUAL(bs::bitwise_select(aa1, bs::is_gtz(aa2), bs::is_gtz(aa3)), cc);
}

STF_CASE_TPL("Check bitwise_select on pack of logical" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  testl<T, N>($);
  testl<T, N/2>($);
  testl<T, N*2>($);
}

