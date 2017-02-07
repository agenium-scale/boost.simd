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
  {
    T v{42};

    std::array<T,N> ref;
    ref.fill(v);

    boost::simd::pack<T,N> p( v );
    STF_ALL_EQUAL(p, ref);
  }

  // check that pack(0) is not ambiguous with the pack(T*) case
  {
    std::array<T,N> ref;
    ref.fill(0);

    boost::simd::pack<T,N> p(0);
    STF_ALL_EQUAL(p, ref);
  }

  // check that pack( p[i]) is not ill-formed due to proxy nature of p[i]
  {
    T v{63};

    std::array<T,N> ref;
    ref.fill(v);

    boost::simd::pack<T,N> q(v);

    boost::simd::pack<T,N> p( q[N/2] );
    STF_ALL_EQUAL(p, ref);
  }
}

STF_CASE_TPL("Check pack constructs from a simple scalar" , STF_NUMERIC_TYPES)
{
  test<T,  1>(runtime);
  test<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}
