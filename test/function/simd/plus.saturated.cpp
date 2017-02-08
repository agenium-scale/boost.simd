//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void tests(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    a2[i] = (i%2) ? T(i+N) : T(-(i+N));
    b[i] = bs::saturated_(bs::plus)(a1[i], a2[i]);
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::saturated_(bs::plus)(aa1, aa2), bb);
}

STF_CASE_TPL("Check saturated plus on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  tests<T, N>(runtime);
  tests<T, N/2>(runtime);
  tests<T, N*2>(runtime);
}
