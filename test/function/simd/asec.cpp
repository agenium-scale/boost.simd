//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/asec.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/std.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N], a2[N], c[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = i%2 ?N/T(i) : -(N/T(i));
    a2[i] = T(i)/10000;
    b[i] = bs::asec(a1[i]);
    c[i] = bs::asec(a2[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb (&b[0], &b[0]+N);
  p_t cc (&c[0], &c[0]+N);
  STF_ULP_EQUAL(bs::asec(aa1), bb, 1);
  STF_ULP_EQUAL(bs::asec(aa2), cc, 1);
}

STF_CASE_TPL("Check asec on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

