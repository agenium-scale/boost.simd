//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/std.hpp>


namespace bs = boost::simd;
  namespace bd = boost::dispatch;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;
  using iT =  bd::as_integer_t<T, unsigned>;
  using pi_t = bs::pack<iT, N>;

  T a1[N];
  iT b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = i;
    b[i] = bs::bits(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  pi_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::bits(aa1), bb, 0);
}

STF_CASE_TPL("Check bits on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

