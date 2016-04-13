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
#include <boost/simd/function/negatenz.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N], b[N];
  for(int i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i+1) : T(-i);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     b[i] = bs::negatenz(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[N]);
  p_t aa2(&a2[0], &a2[N]);
  p_t bb(&b[0], &b[N]);
  std::cout << "aa1 "<< aa1 << std::endl;
  std::cout << "aa2 "<< aa2 << std::endl;
  std::cout << "bb  "<< bb  << std::endl;
  std::cout << "bs::negatenz(aa1, aa2) " << bs::negatenz(aa1, aa2) << std::endl;
  STF_EQUAL(bs::negatenz(aa1, aa2), bb);
}

STF_CASE_TPL("Check negatenz on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
//  test<T, N/2>($);
//  test<T, Nx2>($);
}
