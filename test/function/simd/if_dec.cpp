//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, int N, typename Env> void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;
  using pl_t = bs::pack<bs::logical<T>, N>;

  bs::logical<T> a1[N];
  T a2[N], b[N];

  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2 != 1);
    a2[i] = T(1+i/2);
    b[i] = bs::if_dec(a1[i], a2[i]);
  }

  pl_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);

  STF_EQUAL(bs::if_dec(aa1, aa2), bb);
}

STF_CASE_TPL("Check if_dec on pack with logical condition" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

template <typename T, int N, typename Env> void testa(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N],a2[N], b[N];

  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2 != 1) ? T(1) : T(0);
    a2[i] = T(1+i/2);
    b[i] = bs::if_dec(a1[i], a2[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);

  STF_EQUAL(bs::if_dec(aa1, aa2), bb);
}

STF_CASE_TPL("Check if_dec on pack with arithmetic condition" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  testa<T, N>(runtime);
  testa<T, N/2>(runtime);
  testa<T, N*2>(runtime);
}
