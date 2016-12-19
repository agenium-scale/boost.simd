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
void test(Env& $, std::size_t offset = 0)
{
  using p_t = bs::pack<bs::logical<T>,N>;

  bs::logical<T>* data  = static_cast<bs::logical<T>*>
                          ( ba::aligned_alloc ( p_t::alignment, (sizeof(bs::logical<T>)) * N * 2) );

  std::array<bs::logical<T>,N> ref;
  for(std::size_t i = 0;i < 2*N        ; ++i) data[i] = i%3 ? true : false;
  for(std::size_t i = 0;i < ref.size() ; ++i) ref[i]  = (i+offset)%3 ? true : false;

  p_t p;

  if(offset)  p = bs::aligned_load<bs::pack<bs::logical<T>,N>>(&data[0], offset);
  else        p = bs::aligned_load<bs::pack<bs::logical<T>,N>>(&data[0]);

  STF_ALL_EQUAL( p, ref );
}

STF_CASE_TPL( "Check aligned_load behavior with simple pointer", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL( "Check aligned_load behavior with offset + pointer", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($,N);
  test<T, N/2>($,N/2);
  test<T, N*2>($,N*2);
}

template <typename T, std::size_t N, typename Env>
void test2(Env& $, std::size_t offset = 0)
{
  using ptr_t = T;
  using p_t = bs::pack<bs::logical<T>,N>;

  ptr_t* data = static_cast<ptr_t*>(ba::aligned_alloc(bs::pack<T>::alignment, (sizeof(ptr_t)) * N * 2));

  std::array<bs::logical<T>,N> ref;
  for(std::size_t i = 0;i < 2*N        ; ++i) data[i] = ptr_t( (i+1) % 3 );
  for(std::size_t i = 0;i < ref.size() ; ++i) ref[i]  = (data[i+offset] != 0) ? true : false;

  p_t p;

  if(offset)  p = bs::aligned_load<bs::pack<bs::logical<T>,N>>(&data[0], offset);
  else        p = bs::aligned_load<bs::pack<bs::logical<T>,N>>(&data[0]);

  STF_ALL_EQUAL( p, ref );
}

STF_CASE_TPL( "Check aligned_load behavior with a pointer of arithmetic source", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test2<T, N>($);
  test2<T, N/2>($);
  test2<T, N*2>($);
}

STF_CASE_TPL( "Check aligned_load behavior with offset + pointer of arithmetic source", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test2<T, N>($,N);
  test2<T, N/2>($,N/2);
  test2<T, N*2>($,N*2);
}
