//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/any.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N];
  bs::logical<T> b = false,  c = false;
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(0);
    a2[i] = (i%2) ? T(i+1) : T(-i);
    b = b || a1[i]!= 0;
    c = c || a2[i]!= 0;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);

  STF_EQUAL(bs::any(aa1), b);
  STF_EQUAL(bs::any(aa2), c);
}

STF_CASE_TPL("Check any on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
