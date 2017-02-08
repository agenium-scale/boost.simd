//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/simd/pack.hpp>
#include <boost/simd/function/load.hpp>
#include <list>
#include <numeric>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  std::list<T> v(N);
  std::iota(v.begin(), v.end(), T{1});

  boost::simd::pack<T, N> p(v.begin(), v.end());
  STF_ALL_EQUAL(p, v);
}

STF_CASE_TPL( "Check that pack constructs from iterators pair" , STF_NUMERIC_TYPES)
{
  test<T,  1>(runtime);
  test<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}
