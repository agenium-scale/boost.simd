//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/enumerate.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test0(Env& runtime)
{
  using p_t = bs::pack<T, N>;
  std::array<T,N> ref;

  T k = 0;
  for(auto& e : ref) e = k++;

  STF_ALL_EQUAL(bs::enumerate<p_t>(),ref);
}

STF_CASE_TPL( "Check enumerate<T>() behavior", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test0<T, N>(runtime);
  test0<T, N/2>(runtime);
  test0<T, N*2>(runtime);
}

template <typename T, std::size_t N, typename Env>
void test1(Env& runtime)
{
  using p_t = bs::pack<T, N>;
  std::array<T,N> ref;

  T k = 42;
  for(auto& e : ref) e = k++;

  STF_ALL_EQUAL(bs::enumerate<p_t>(42),ref);
}

STF_CASE_TPL( "Check enumerate<T>(SEED) behavior", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test1<T, N>(runtime);
  test1<T, N/2>(runtime);
  test1<T, N*2>(runtime);
}

template <typename T, std::size_t N, typename Env>
void test2(Env& runtime)
{
  using p_t = bs::pack<T, N>;
  std::array<T,N> ref;

  for(std::size_t i = 0; i< N; ++i)
    ref[i] = 5 + T(i)*3;

  STF_ALL_EQUAL(bs::enumerate<p_t>(5,3),ref);
}

STF_CASE_TPL( "Check enumerate<T>(SEED,STEP) behavior", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test2<T, N>(runtime);
  test2<T, N/2>(runtime);
  test2<T, N*2>(runtime);
}
