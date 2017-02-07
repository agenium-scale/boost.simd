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
void test(Env& runtime)
{
  std::array<T, N> ref;
  std::iota(ref.begin(), ref.end(), T(1));
  bs::pack<T, N> p0(ref.begin(), ref.end()), res;

  std::transform(p0.begin(),p0.end(),res.begin(), [](T e) { return e; } );
  STF_ALL_EQUAL(res, ref);
}

STF_CASE_TPL( "Check proxy access" , STF_NUMERIC_TYPES)
{
  test<T,  1>(runtime);
  test<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}
