//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <algorithm>
#include <numeric>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test_not(Env& runtime)
{
  std::array<T, N> a;
  std::iota(a.begin(), a.end(), T(1));
  bs::pack<T, N> p0(a.begin(), a.end()), ref(a.begin(), a.end());

  bool supports_logical_not = true;
  for (auto it0 = p0.begin(); it0 != p0.end(); ++it0)
    supports_logical_not = supports_logical_not && !(!(*it0));

  STF_EXPECT( supports_logical_not );
}

STF_CASE_TPL( "Check proxy bitwise negation" , STF_NUMERIC_TYPES)
{
  test_not<T,  1>(runtime);
  test_not<T,  2>(runtime);
  test_not<T,  4>(runtime);
  test_not<T,  8>(runtime);
  test_not<T, 16>(runtime);
  test_not<T, 32>(runtime);
}
