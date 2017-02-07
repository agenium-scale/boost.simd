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
boost::simd::pack<T, sizeof...(N)> make( nsm::list<N...> const& )
{
  return {N::value...};
}

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  boost::simd::pack<T, N> p = make<T>(nsm::range<std::size_t,0,N>{});

  std::array<T,N> ref;
  std::iota(ref.begin(), ref.end(), T{0});

  STF_ALL_EQUAL(p, ref);
}

template <typename T, std::size_t N, typename Env>
void test1(Env& runtime)
{
  boost::simd::pack<T, N> p{8};

  std::array<T,N> ref;
  std::iota(ref.begin(), ref.end(), T{8});

  STF_ALL_EQUAL(p, ref);
}

template <typename T, std::size_t N, typename Env>
void test2(Env& runtime)
{
  {
    boost::simd::pack<T, N> p(0, 1);

    std::array<T,N> ref;
    std::iota(ref.begin(), ref.end(), T{0});

    STF_ALL_EQUAL(p, ref);
  }

  // check that pack( p[i], p[j] ) is not ill-formed due to proxy nature of p[*]
  {
    boost::simd::pack<T, N> q(0, 1);
    boost::simd::pack<T, N> p(q[0], q[1]);

    std::array<T,N> ref;
    std::iota(ref.begin(), ref.end(), T{0});

    STF_ALL_EQUAL(p, ref);
  }
}

STF_CASE_TPL( "Check that pack constructs from initializer list", STF_NUMERIC_TYPES )
{
  test1<T,  1>(runtime);
  test2<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}
