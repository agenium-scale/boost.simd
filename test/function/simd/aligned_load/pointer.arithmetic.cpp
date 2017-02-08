//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/simd/aligned_load.hpp>
#include <boost/simd/pack.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <simd_test.hpp>

namespace ba = boost::alignment;
namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime, std::size_t offset = 0)
{
  using p_t = bs::pack<T,N>;

  T* data = static_cast<T*>(ba::aligned_alloc(p_t::alignment, (sizeof(T)) * N * 2));
  std::array<T,N> ref;
  for(std::size_t i = 0;i < 2*N        ; ++i) data[i] = T(i);
  for(std::size_t i = 0;i < ref.size() ; ++i) ref[i]  = T(i+offset);

  p_t p;

  if(offset)  p = bs::aligned_load<bs::pack<T,N>>(&data[0], offset);
  else        p = bs::aligned_load<bs::pack<T,N>>(&data[0]);

  STF_ALL_EQUAL( p, ref );
}

STF_CASE_TPL( "Check aligned_load behavior with simple pointer", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

STF_CASE_TPL( "Check aligned_load behavior with offset+ pointer", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime,N);
  test<T, N/2>(runtime,N/2);
  test<T, N*2>(runtime,N*2);
}
