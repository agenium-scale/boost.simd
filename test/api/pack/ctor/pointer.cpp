//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/simd/pack.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <numeric>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace ba = boost::alignment;
  using pack_t = boost::simd::pack<T, N>;

  T* ptr = static_cast<T*>(ba::aligned_alloc(pack_t::alignment, (sizeof(T)) * N));
  std::iota(ptr, ptr + N, T{1});

  pack_t p(ptr);
  STF_EXPECT( std::equal(p.begin(),p.end(),ptr) );

  ba::aligned_free(ptr);
}

STF_CASE_TPL("Check that pack constructs from aligned pointer" , STF_NUMERIC_TYPES)
{
  test<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}
