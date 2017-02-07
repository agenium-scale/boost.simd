//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/slide.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, int N, typename Env> void test(Env& runtime)
{
  std::array<bs::logical<T>,4*N> data;
  for(std::size_t i = 0;i < data.size(); ++i) data[i] = false;
  for(int i =   N;i < 2*N; ++i) data[i] = (i%2 != 0);
  for(int i = 2*N;i < 3*N; ++i) data[i] = ((i+1)%2 != 0);

  using p_t = bs::pack<bs::logical<T>,N>;
  p_t ref;
  p_t l = bs::load<p_t>(&data[  N]);
  p_t r = bs::load<p_t>(&data[2*N]);

  STF_EQUAL( bs::slide<-N>(l,r), bs::slide<0>(r,l) );
  STF_EQUAL( bs::slide<-1>(l,r), bs::slide<N-1>(r,l) );

  ref = bs::load<p_t>(&data[N]);
  STF_EQUAL( bs::slide<0>(l,r), ref );

  ref = bs::load<p_t>(&data[N], +1);
  STF_EQUAL( bs::slide<+1>(l,r), ref );

  ref = bs::load<p_t>(&data[N], N-1);
  STF_EQUAL( bs::slide<N-1>(l,r), ref );

  STF_EQUAL( bs::slide<N>(l,r), r );
}

STF_CASE_TPL( "Check binary slide behavior", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const int N = bs::pack<bs::logical<T>>::static_size;

  test<T, N  >(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
