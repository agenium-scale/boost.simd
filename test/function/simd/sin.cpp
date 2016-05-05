//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/sin.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/std.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N], c[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);
    b[i] = bs::sin(a1[i]) ;
    c[i] = bs::std_(bs::sin)(a1[i]);
  }
  for(std::size_t i = 0; i < N; ++i)
  {
    std::cout << "sin(" << a1[i] << ") -> " << b[i] << std::endl;
  }

  p_t aa1(&a1[0], &a1[N]);
  p_t bb (&b[0], &b[N]);
  p_t cc (&c[0], &c[N]);
  STF_EQUAL(bs::sin(aa1), bb);
  std::cout << "aa1 = " << aa1 << std::endl;
  std::cout << " bs::sin(aa1) = " << bs::sin(aa1) << std::endl;
 STF_EQUAL(bs::std_(bs::sin)(aa1), cc);
}

STF_CASE_TPL("Check sin on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

