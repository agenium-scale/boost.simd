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
#include <boost/simd/function/hmsb.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T,int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N];
  std::size_t r = 0;
  for(int i = 0; i < N; ++i)
  {
    a1[i] = -1; //(i%2) ? T(i) : T(-i);
    r |= (bs::bits(a1[i]) >> (sizeof(T)*8 - 1)) << i;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  STF_EQUAL(bs::hmsb(aa1), r);
}

STF_CASE_TPL("Check rec on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
//  test<T, N/2>($);
//  test<T, Nx2>($);
}
