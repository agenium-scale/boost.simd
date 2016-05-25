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
#include <boost/simd/function/rem.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] =  T(i) ;
     a2[i] = T(i+N) ;
     b[i] = bs::rem(bs::ceil, a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::rem(bs::ceil, aa1, aa2), bb);
}

STF_CASE_TPL("Check rem on pack" , STF_SIGNED_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
//   test<T, N/2>($);
//   test<T, N*2>($);
}
template <typename T, std::size_t N, typename Env>
void testceilfast(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] =T(i);
     a2[i] =T(i+N);
     b[i] = bs::fast_(bs::rem)(bs::fix, a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::fast_(bs::rem)(aa1, aa2), bb);
}

STF_CASE_TPL("Check fast_(rem) on pack option ceil" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  testceilfast<T, N>($);
//   testceilfast<T, N/2>($);
//   testceilfast<T, N*2>($);
}
