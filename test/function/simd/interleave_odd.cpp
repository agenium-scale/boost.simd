//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/interleave_odd.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, int N, typename Env>
void test(Env&, std::false_type const&)
{}

template <typename T, int N, typename Env>
void test(Env& $, std::true_type const& = {})
{
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], b[N];

  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    a2[i] = (i%2) ? T(i+N) : T(-(i+N));
  }

  for(std::size_t i = 0; i < N; ++i)
  {
    b[i] = (i%2) ? a2[2*(i/2)+1] : a1[2*(i/2)+1];
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);

  STF_EQUAL(bs::interleave_odd(aa1, aa2), bb);
}

STF_CASE_TPL("Check interleave_odd on pack", STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N  >($, brigand::bool_<(N>1)>());
  test<T, N/2>($, brigand::bool_<(N>2)>());
  test<T, N*2>($);
}
