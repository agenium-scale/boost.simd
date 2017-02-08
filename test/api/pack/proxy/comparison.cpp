//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <algorithm>
#include <numeric>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test_is_equal(Env& runtime)
{
  std::array<T, N> ref;
  std::iota(ref.begin(), ref.end(), T(1));
  bs::pack<T, N> p(ref.begin(), ref.end());

  STF_EXPECT(( std::all_of(p.begin() , p.end(), [](T e) { return e == e; } ) ));
}

template <typename T, std::size_t N, typename Env>
void test_not_equal(Env& runtime)
{
  std::array<T, N> ref;
  std::iota(ref.begin(), ref.end(), T(1));
  bs::pack<T, N> p(ref.begin(), ref.end());

  STF_EXPECT(( std::none_of(p.begin() , p.end(), [](T e) { return e != e; } ) ));
}

STF_CASE_TPL( "Check proxy equality comparison" , STF_NUMERIC_TYPES)
{
  test_is_equal<T,  1>(runtime);
  test_is_equal<T,  2>(runtime);
  test_is_equal<T,  4>(runtime);
  test_is_equal<T,  8>(runtime);
  test_is_equal<T, 16>(runtime);
  test_is_equal<T, 32>(runtime);
}

STF_CASE_TPL( "Check proxy inequality comparison" , STF_NUMERIC_TYPES)
{
  test_not_equal<T,  1>(runtime);
  test_not_equal<T,  2>(runtime);
  test_not_equal<T,  4>(runtime);
  test_not_equal<T,  8>(runtime);
  test_not_equal<T, 16>(runtime);
  test_not_equal<T, 32>(runtime);
}
