//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/insert.hpp>
#include <boost/simd/detail/unroll.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <array>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template<typename A, typename P, typename... N>
void f( nsm::list<N...> const&, A& a, P& p)
{
  BOOST_SIMD_LOCAL_UNROLL( a[N::value] = N::value%2 ? true : false );
  BOOST_SIMD_LOCAL_UNROLL( (bs::insert(p, N::value, N::value%2 ? true : false )) );
}

template <typename T, std::size_t N, typename Env>
void test_st(Env& runtime)
{
  bs::pack<T, N>  p;
  std::array<bool,N> ref;

  f( nsm::range<std::size_t, 0, N>(),ref,p);

  for(std::size_t i = 0;i < N; ++i) STF_EQUAL( p[i], ref[i] );
}

STF_CASE_TPL("Check static insert on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = boost::simd::pack<T>::static_size;

  test_st<bs::logical<T>, N>(runtime);
  test_st<bs::logical<T>, N/2>(runtime);
  test_st<bs::logical<T>, N*2>(runtime);
}
