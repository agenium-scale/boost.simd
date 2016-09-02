//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test_fast(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] =  T(N-i);
    b[i] = bs::fast_(bs::sqrt)(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::fast_(bs::sqrt)(aa1), bb, 2048);
}

STF_CASE_TPL("Check fast(sqrt) on pack", STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_fast<T, N>($);
  test_fast<T, N/2>($);
  test_fast<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  a1[0] = bs::Inf<T>();
  b[0] = bs::sqrt(a1[0]);

  for(std::size_t i = 1; i < N; ++i)
  {
    a1[i] =  T(N-i);
    b[i] = bs::sqrt(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::sqrt(aa1), bb, 0.5);
}

STF_CASE_TPL("Check sqrt on pack", STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
