//==================================================================================================
/*
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/simd/pack.hpp>
#include <limits>
#include <numeric>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  std::vector<T> v(N);
  std::iota(v.begin(), v.end(), T{1});
  boost::simd::pack<T, N> p(v.begin(), v.end());

  STF_EXPECT( std::equal(p.begin(),p.end(), v.begin()) );
}

STF_CASE_TPL( "Check that pack constructs from iterators pair" , STF_NUMERIC_TYPES)
{
  test<T,  2>($);
  test<T,  4>($);
  test<T,  8>($);
  test<T, 16>($);
  test<T, 32>($);
}
