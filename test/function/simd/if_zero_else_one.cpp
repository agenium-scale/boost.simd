//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/if_zero_else_one.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(int i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(2) : T(0);
     b[i] = a1[i] ? bs::Zero<T>() : bs::One<T>();
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::if_zero_else_one(aa1), bb);
}

STF_CASE_TPL("Check if_zero_else_one on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

template <typename T, int N, typename Env>
void testl(Env& runtime)
{
  namespace bs = boost::simd;
  using lT =  bs::logical<T>;
  using p_t = bs::pack<T, N>;
  using pl_t = bs::pack<lT, N>;

  lT a1[N];
  T b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? bs::True<lT>() : bs::False<lT>();
    b[i] = a1[i] ? bs::Zero<T>() : bs::One<T>() ;
  }
  pl_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::if_zero_else_one(aa1), bb);
}

STF_CASE_TPL("Check if_zero_else_one on pack of logical" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  testl<T, N>(runtime);
  testl<T, N/2>(runtime);
  testl<T, N*2>(runtime);
}

