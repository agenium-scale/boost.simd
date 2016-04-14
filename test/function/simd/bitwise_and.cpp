//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;


  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     b[i] = bs::bitwise_and(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[N]);
  p_t aa2(&a2[0], &a2[N]);
  p_t bb(&b[0], &b[N]);
  STF_EQUAL(bs::bitwise_and(aa1, aa2), bb);

}

STF_CASE_TPL("Check bitwise_and on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void testm(Env& $)
{
  namespace bs = boost::simd;
  const std::size_t N1 = N*sizeof(T);
  using p_t = bs::pack<T, N>;
  using pi_t = bs::pack<int8_t, N1>;

  T a1[N], b1[N];
  int8_t a2[N1], b2[N1];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
  }
  for(std::size_t i = 0; i < N1; ++i)
  {
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
  }
  auto za2 = reinterpret_cast<T*>(a2);
  for(std::size_t i = 0; i < N; ++i)
  {
     b1[i] = bs::bitwise_and(a1[i], za2[i]);
  }
  auto za1 = reinterpret_cast<int8_t*>(a1);
  for(std::size_t i = 0; i < N1; ++i)
  {
     b2[i] = bs::bitwise_and(za1[i], a2[i]);
  }

  p_t  aa1(&a1[0], &a1[0]+N);
  pi_t aa2(&a2[0], &a2[0]+N1);

  p_t  bb1(&b1[0], &b1[0]+N);
  STF_EQUAL(bs::bitwise_and(aa1, aa2), bb1);

  pi_t bb2(&b2[0], &b2[0]+N1);
  STF_EQUAL(bs::bitwise_and(aa2, aa1), bb2);
}

STF_CASE_TPL("Check bitwise_and on mixed type packs" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  testm<T, N>($);
  testm<T, N/2>($);
  testm<T, N*2>($);
}

