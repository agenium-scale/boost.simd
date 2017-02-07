//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/insert.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <array>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  bs::pack<T, N>  p;
  std::array<bool,N> ref;

  for(std::size_t i = 0; i < N; ++i)
  {
    bs::insert(p, i, i%2 ? true : false);
    ref[i] = i%2 ? true : false;
  }

  for(std::size_t i = 0;i < N; ++i) STF_EQUAL( p[i], ref[i] );
}

STF_CASE_TPL("Check dynamic insert on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = boost::simd::pack<T>::static_size;

  test<bs::logical<T>, N>(runtime);
  test<bs::logical<T>, N/2>(runtime);
  test<bs::logical<T>, N*2>(runtime);
}
