//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/sinc.hpp>
#include <boost/simd/pack.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N], c[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);
    b[i] = bs::sinc(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  p_t cc (&c[0], &c[0]+N);
  STF_ULP_EQUAL(bs::sinc(aa1), bb, 0.5);
}

STF_CASE_TPL("Check sinc on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

