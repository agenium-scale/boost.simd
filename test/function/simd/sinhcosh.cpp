//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/sinhcosh.hpp>
#include <boost/simd/pack.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], c[N], s[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i)/2 : -T(i)/2;
    std::tie(s[i], c[i])= bs::sinhcosh(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t ss (&s[0], &s[0]+N);
  p_t cc (&c[0], &c[0]+N);
  p_t ss1, cc1;
  std::tie(ss1, cc1)= bs::sinhcosh(aa1) ;
  STF_IEEE_EQUAL(ss1, ss);
  STF_IEEE_EQUAL(cc1, cc);
}

STF_CASE_TPL("Check sincosh on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

