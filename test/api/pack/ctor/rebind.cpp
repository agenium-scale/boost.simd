//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <numeric>
#include <type_traits>
#include <simd_test.hpp>

// test construction of pack<T, N> from pack<U, N>
template <typename T, typename U, std::size_t N, typename Env>
void test_for_u(Env& runtime)
{
    using destination = boost::simd::pack<T, N>;
    using source = boost::simd::pack<U, N>;

    source x;
    std::iota(std::begin(x), std::end(x), T{1});

    destination y(x);
    STF_ALL_EQUAL(y, x);
    
    destination z{x};
    STF_ALL_EQUAL(z, x);
}

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  test_for_u<T, float, N, Env>(runtime);
  test_for_u<T, double, N, Env>(runtime);
  test_for_u<T, int, N, Env>(runtime);
  test_for_u<T, std::uint8_t, N, Env>(runtime);
  test_for_u<T, std::int16_t, N, Env>(runtime);
  test_for_u<T, std::uint32_t, N, Env>(runtime);
  test_for_u<T, std::int64_t, N, Env>(runtime);
}

STF_CASE_TPL("Check that pack constructs from pack of different value type" , STF_NUMERIC_TYPES)
{
  test<T,  1>(runtime);
  test<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}
