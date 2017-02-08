//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/extract.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <array>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  STF_TYPE_IS(T, decltype(bs::extract(bs::pack<T, N>(),0ULL)) );

  std::array<T,N> ref;
  for(std::size_t i = 0; i < N; ++i) ref[i] = T(i*2);

  bs::pack<T,N> p(&ref[0], &ref[0]+N);
  for(std::size_t i = 0; i < N; ++i) STF_EQUAL(bs::extract(p, i), ref[i]);
}

STF_CASE_TPL("Check dynamic extract on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = boost::simd::pack<T>::static_size;

  test<T, N/2>(runtime);
  test<T, N>(runtime);
  test<T, N*2>(runtime);
}
