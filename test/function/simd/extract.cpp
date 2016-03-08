//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  STF_TYPE_IS(const T&, decltype(bs::extract(p_t(), std::size_t())));
  T a1[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i*2);
  }
  p_t aa1(&a1[0], &a1[N]);
  for(std::size_t i = 0; i < N; ++i)
  {
    STF_EQUAL(bs::extract(aa1, i), a1[i]);
  }
}

STF_CASE_TPL("Check extract on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
//  test<T, N/2>($);
//  test<T, Nx2>($);
}
