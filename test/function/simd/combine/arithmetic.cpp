//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/combine.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL("combine scalar into a pack<T,2>", STF_NUMERIC_TYPES)
{
  bs::pack<T,2> res = bs::combine(T(13), T(37));
  STF_EQUAL(res[0], T(13));
  STF_EQUAL(res[1], T(37));
}

template<typename T, std::size_t N, typename Env>
void test( Env& runtime )
{
  std::array<T,2*N> ref;
  for(std::size_t i=0;i<2*N;++i) ref[i] = T(1+i);

  bs::pack<T,N> first (&ref[0]  , &ref[0]+N   );
  bs::pack<T,N> second(&ref[0]+N, &ref[0]+2*N );

  STF_EXPR_IS( bs::combine(first,second), (bs::pack<T,2*N>));
  STF_ALL_EQUAL( bs::combine(first,second), ref);
}

STF_CASE_TPL("combine pack<T,N> into pack<T,2*N>", STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T,N>(runtime);
  test<T,N/2>(runtime);
  test<T,N*2>(runtime);
}
