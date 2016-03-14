//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/store.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;


  T a1[N], a2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i+1);
    a2[i] = T(0);
  }

  p_t aa1(&a1[0], &a1[N]);
  bs::store(aa1, &a2[0]);

  for(std::size_t i=0; i <N ; ++i)
  {
    std::cout << "i -> " <<  i << std::endl;
    STF_IEEE_EQUAL(a1[i], a2[i]);
  }
  for(std::size_t i=0; i <N ; ++i)
  {
    std::cout << "i -> " <<  i << " "<< a1[i] << " == "<< a2[i] << std::endl;
  }
}

STF_CASE_TPL( "Check store behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = p_t::static_size;
   test<T, N>($);
   test<T, N/2>($);
   test<T, N*2>($);
}
