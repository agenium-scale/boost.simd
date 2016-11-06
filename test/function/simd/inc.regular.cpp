//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/inc.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void pre_test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(1+i);
    b[i] = a1[i] + T(1);
  }

  p_t aa1(&a1[0], &a1[0]+N), aa2;
  p_t bb(&b[0], &b[0]+N);

  aa2 = ++aa1;
  STF_EQUAL(aa2, bb);
  STF_EQUAL(aa1, bb);
}

STF_CASE_TPL("Check pre-increment on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  pre_test<T, N>($);
  pre_test<T, N/2>($);
  pre_test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void post_test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(1+i);
    b[i] = a1[i] + T(1);
  }

  p_t aa1(&a1[0], &a1[0]+N), prev(aa1), aa2;
  p_t bb(&b[0], &b[0]+N);

  aa2 = aa1++;
  STF_EQUAL(aa2, prev);
  STF_EQUAL(aa1, bb);
}

STF_CASE_TPL("Check post-increment on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  post_test<T, N>($);
  post_test<T, N/2>($);
  post_test<T, N*2>($);
}
