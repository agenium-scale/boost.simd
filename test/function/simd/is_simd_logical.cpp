//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/is_simd_logical.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(0) : bs::Allbits<T>();
    a2[i] = T(i+1);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  STF_EQUAL(bs::is_simd_logical(aa1), true);
  STF_EQUAL(bs::is_simd_logical(aa2), false);
}

STF_CASE_TPL("Check is_simd_logical on pack", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
