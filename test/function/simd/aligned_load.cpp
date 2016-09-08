//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/aligned_load.hpp>
#include <simd_test.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <vector>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace ba = boost::alignment;
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T* a1 = static_cast<T*>(ba::aligned_alloc(p_t::alignment, (sizeof(T)) * N*3));
  STF_TYPE_IS(p_t, decltype(bs::aligned_load<p_t>(&a1[0])));
  STF_TYPE_IS(p_t, decltype(bs::aligned_load<p_t>(&a1[0], std::size_t())));

  for(std::size_t i = 0; i < 3*N; ++i){
    a1[i] = T(i);
  }
  for(int i = 0; i <= 2;  ++i)
  {
    p_t aa1(a1+i*N, a1+(i+1)*N);
    STF_IEEE_EQUAL(bs::aligned_load<p_t>(a1+i*N), aa1);
  }
  ba::aligned_free(a1);
}

STF_CASE_TPL( "Check aligned_load behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = p_t::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
