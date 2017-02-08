//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/store.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, typename U, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t  = bs::pack<T, N>;
  using pi_t = bs::pack<U, N>;

  std::array<T,N> a1;
  std::array<U,N> idx;
  std::array<T,3*N> dst, ref;

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i]  = T(i+1);
    idx[i] = 3*i;
  }

  for(std::size_t i = 0; i < 3*N; ++i)
  {
    dst[i] = 0;
    if(i%3 == 0)  ref[i] = a1[i/3];
    else          ref[i] = 0;
  }

  pi_t pidx(&idx[0], &idx[0]+N);
  p_t aa1(&a1[0], &a1[0]+N);
  bs::store(aa1, &dst[0], pidx);

  STF_ALL_EQUAL(dst, ref);
}

STF_CASE_TPL( "Check scatter store behavior with 32 bits indexes", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, std::int32_t, N>(runtime);
  test<T, std::int32_t, N/2>(runtime);
  test<T, std::int32_t, N*2>(runtime);
}

STF_CASE_TPL( "Check scatter store behavior with 64 bits indexes", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, std::int64_t, N>(runtime);
  test<T, std::int64_t, N/2>(runtime);
  test<T, std::int64_t, N*2>(runtime);
}
