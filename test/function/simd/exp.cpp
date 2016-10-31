//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void limit_test(Env& $)
{
  using p_t = bs::pack<T, N>;

  STF_ULP_EQUAL (bs::exp(p_t(1))            , p_t(2.718281828459045), 0.5);
  STF_IEEE_EQUAL(bs::exp(p_t(0))            , p_t(1)        );
  STF_IEEE_EQUAL(bs::exp(p_t(bs::Inf<T>())) , bs::Inf<p_t>());
  STF_IEEE_EQUAL(bs::exp(p_t(bs::Minf<T>())), p_t(0)        );
}

STF_CASE_TPL("Check exp limit cases" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  limit_test<T, N>($);
  limit_test<T, N/2>($);
  limit_test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::exp(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::exp(aa1), bb, 0.5);
}

STF_CASE_TPL("Check exp on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
