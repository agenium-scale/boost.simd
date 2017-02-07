//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N];
  std::size_t r = 0;
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     r += a1[i] != T(0);
   }
  p_t aa1(&a1[0], &a1[0]+N);

  STF_EQUAL(bs::nbtrue(aa1), r);
}

STF_CASE_TPL("Check nbtrue on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
