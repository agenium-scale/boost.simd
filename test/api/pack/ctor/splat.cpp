//==================================================================================================
/*
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/simd/pack.hpp>
#include <numeric>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  T v{42};

  std::array<T,N> ref;
  ref.fill(v);

  boost::simd::pack<T,N> p( v );
  STF_EXPECT( std::equal(p.begin(),p.end(), ref.begin()) );
}

STF_CASE_TPL("Check pack constructs from a simple scalar" , STF_NUMERIC_TYPES)
{
  test<T,  2>($);
  test<T,  4>($);
  test<T,  8>($);
  test<T, 16>($);
  test<T, 32>($);
}
