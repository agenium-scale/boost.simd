//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/store.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  std::array<T,N> a1, a2;
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i+1);
    a2[i] = T(0);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  bs::store(aa1, &a2[0]);
  STF_ALL_EQUAL(a1, a2);
}

STF_CASE_TPL( "Check store behavior with all types", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

template <typename T, std::size_t N, typename Env>
void test_o(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  std::array<T,N+3> a1,a2;

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i+1);
    a2[i] = T(0);
  }

  for(std::size_t i = N; i < N+3; ++i) { a1[i] = a2[i] = T(0); }

  p_t aa1(&a1[0], &a1[0]+N);

  bs::store(aa1, &a2[0], 3);
  p_t aa2(&a2[3], &a2[3]+N);

  STF_EQUAL(aa1, aa2);
}

STF_CASE_TPL( "Check offset store behavior with all types", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_o<T, N>(runtime);
  test_o<T, N/2>(runtime);
  test_o<T, N*2>(runtime);
}
