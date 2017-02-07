//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/broadcast.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, typename... N, typename Env>
void test(Env& runtime, nsm::list<N...> const&)
{
  static const std::size_t C = sizeof...(N);
  using p_t = bs::pack<T,C>;

  p_t p( (T(1+N::value))... );

  STF_EQUAL( bs::broadcast< -1>(p), bs::Zero<p_t>() );
  STF_EQUAL( bs::broadcast<  0>(p), p_t(T(1))       );
  STF_EQUAL( bs::broadcast<C/2>(p), p_t(T(C/2+1))   );
  STF_EQUAL( bs::broadcast<C-1>(p), p_t(T(C))       );
  STF_EQUAL( bs::broadcast<C*2>(p), bs::Zero<p_t>() );
}

STF_CASE_TPL( "Check broadcast<N>() behavior", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T>(runtime, nsm::range<std::size_t, 0, N  >{});
  test<T>(runtime, nsm::range<std::size_t, 0, N/2>{});
  test<T>(runtime, nsm::range<std::size_t, 0, N*2>{});
}

