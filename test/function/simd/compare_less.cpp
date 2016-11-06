//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/compare_less.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i/2);
    a2[i] = T(i);
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);

  STF_EXPECT(!bs::compare_less(aa1, aa1));
  STF_EXPECT(!bs::compare_less(aa2, aa1));
  STF_EXPECT( bs::compare_less(aa1, aa2));
}

STF_CASE_TPL("Check compare_less on pack" , STF_NUMERIC_TYPES)
{
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
