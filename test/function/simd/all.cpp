//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/all.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], a3[N];

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i+1);
    a2[i] = T(0);
    a3[i] = i==N/2 ? T(0) : T(i+1);
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t aa3(&a3[0], &a3[0]+N);

  STF_EQUAL(bs::all(aa1), true);
  STF_EQUAL(bs::all(aa2 == 0), true);
  STF_EQUAL(bs::all(aa2), false);
  STF_EQUAL(bs::all(aa3), false);

  STF_EQUAL(bs::splatted_(bs::all)(aa1), (bs::pack<bs::logical<T>,N>(true)) );
  STF_EQUAL(bs::splatted_(bs::all)(aa2), (bs::pack<bs::logical<T>,N>(false)) );
  STF_EQUAL(bs::splatted_(bs::all)(aa3), (bs::pack<bs::logical<T>,N>(false)) );
}

STF_CASE_TPL("Check all on pack", STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
