//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/pack.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <vector>
#include <simd_test.hpp>

namespace ba = boost::alignment;
namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  std::vector<T,ba::aligned_allocator<T,p_t::alignment>> a1(N);
  std::vector<T,ba::aligned_allocator<T,p_t::alignment>> a2(N);

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(27);
    a2[i] = T(i+1);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  bs::aligned_store(aa1, &a2[0]);

  STF_EQUAL(a1, a2);
}

STF_CASE_TPL( "Check aligned_store behavior with all types", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
