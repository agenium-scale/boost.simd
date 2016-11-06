//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test_l2l(Env& $)
{
  using p_t = bs::pack<T, N>;

  std::array<T,N> a1;
  std::array<T,N> a2;
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = i%3 ? true : false;
    a2[i] = false;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  bs::store(aa1, &a2[0]);
  STF_ALL_IEEE_EQUAL(a1, a2);
}

STF_CASE_TPL( "Check store logical into logical", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_l2l<bs::logical<T>, N>($);
  test_l2l<bs::logical<T>, N/2>($);
  test_l2l<bs::logical<T>, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test_l2a(Env& $)
{
  using p_t = bs::pack<T, N>;
  using s_t = typename T::value_type;

  std::array<T,N> a1;
  std::array<s_t,N> a2, ref;
  s_t k = bs::is_bitwise_logical<p_t>::value ? bs::Allbits<s_t>() : 1;

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = i%3 ? true : false;
    a2[i] = T(0);
    ref[i] = a1[i] ? k : s_t(0);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  bs::store(aa1, &a2[0]);
  STF_ALL_IEEE_EQUAL(a2, ref);
}

STF_CASE_TPL( "Check store logical into arithmetic type", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_l2a<bs::logical<T>, N>($);
  test_l2a<bs::logical<T>, N/2>($);
  test_l2a<bs::logical<T>, N*2>($);
}
