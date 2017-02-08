//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <numeric>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using pack_t = boost::simd::pack<T, N>;

  std::array<T,N> x;
  std::iota(&x[0], &x[0] + N, T{1});

  STF_ALL_EQUAL(pack_t{x}, x);
}

STF_CASE_TPL("Check that pack constructs from standard array" , STF_NUMERIC_TYPES)
{
  test<T,  1>(runtime);
  test<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}
