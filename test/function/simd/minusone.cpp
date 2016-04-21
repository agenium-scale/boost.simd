//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/minusone.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::minusone(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[N]);
  p_t bb (&b[0], &b[N]);

  STF_EQUAL(bs::minusone(aa1), bb);
}

STF_CASE_TPL("Check minusone saturated on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void tests(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] =bs::saturated_( bs::minusone)(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[N]);
  p_t bb (&b[0], &b[N]);

  STF_EQUAL(bs::saturated_(bs::minusone)(aa1), bb);
}

STF_CASE_TPL("Check minusone on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  tests<T, N>($);
  tests<T, N/2>($);
  tests<T, N*2>($);
}
