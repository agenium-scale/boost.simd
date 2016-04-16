//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#define BOOST_SIMD_ENABLE_DIAG
#include <boost/simd/pack.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N];
  T b[N], c[N];
  size_t sh1 =  sizeof(T)*8-1;
  int sh2 =  1;
  for(int i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     b[i] = bs::shift_left(a1[i], sh1);
     c[i] = bs::shift_left(a1[i], sh2);
   }
  p_t aa1(&a1[0], &a1[N]);
  p_t bb(&b[0], &b[N]);
  p_t cc(&c[0], &c[N]);
  STF_IEEE_EQUAL(bs::shift_left(aa1, sh1), bb);
  STF_IEEE_EQUAL(bs::shift_left(aa1, sh2), cc);
  STF_IEEE_EQUAL(aa1 << sh1, bb);
  STF_IEEE_EQUAL(aa1 << sh2, cc);
}

STF_CASE_TPL("Check shift_left on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
