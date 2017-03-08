//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/slice_low.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template<typename T, std::size_t N, typename Env>
void test( Env&, nsm::bool_<false> const& )
{}

template<typename T, std::size_t N, typename Env>
void test( Env& runtime, nsm::bool_<true> const& = {} )
{
  std::array<bs::logical<T>,N> ref;
  for(std::size_t i=0;i<N;++i) ref[i] = (i%3) ? true : false;

  bs::pack<bs::logical<T>,N>   value (&ref[0], &ref[0]+N   );
  bs::pack<bs::logical<T>,N/2> second(&ref[0], &ref[0]+N/2 );

  STF_EQUAL( bs::slice_low(value), second);
}

STF_CASE_TPL("slice_low pack<T,N> into a pack<T,N/2>", STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T,N>(runtime);
  test<T,N/2>(runtime, nsm::bool_<(N/2 > 1)>{});
  test<T,N*2>(runtime);
}
