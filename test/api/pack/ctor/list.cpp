//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <numeric>
#include <array>
#include <simd_test.hpp>

template <typename T, typename... N>
boost::simd::pack<T, sizeof...(N)> make( brigand::list<N...> const& )
{
  return {N::value...};
}

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  boost::simd::pack<T, N> p = make<T>(brigand::range<std::size_t,0,N>{});

  std::array<T,N> ref;
  std::iota(ref.begin(), ref.end(), T{0});

  STF_EXPECT( std::equal(p.begin(),p.end(),ref.begin()) );
}

STF_CASE_TPL( "Check that pack constructs from initializer list", STF_NUMERIC_TYPES )
{
  test<T,  2>($);
  test<T,  4>($);
  test<T,  8>($);
  test<T, 16>($);
  test<T, 32>($);
}
