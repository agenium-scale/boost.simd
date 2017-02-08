//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/simd/load.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime, std::size_t offset = 0)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T,N>;

  std::array<T,N+1> data;
  std::array<T,N> ref;
  for(std::size_t i = 0;i < data.size(); ++i) data[i] = i%2 ? true : false;
  for(std::size_t i = 0;i < ref.size() ; ++i) ref[i]  = (i+offset)%2 ? true : false;

  p_t p;

  if(offset)  p = bs::load<bs::pack<T,N>>(&data[0], offset);
  else        p = bs::load<bs::pack<T,N>>(&data[0]);

  STF_ALL_EQUAL( p, ref );
}

STF_CASE_TPL( "Check load behavior with simple pointer", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<bs::logical<T>, N>(runtime);
  test<bs::logical<T>, N/2>(runtime);
  test<bs::logical<T>, N*2>(runtime);
}

STF_CASE_TPL( "Check load behavior with offset+ pointer", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<bs::logical<T>, N>(runtime,1);
  test<bs::logical<T>, N/2>(runtime,1);
  test<bs::logical<T>, N*2>(runtime,1);
}
