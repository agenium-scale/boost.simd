//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_not.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;
  using pl_t = bs::pack<bs::logical<T>, N>;

  T a1[N], a2[N];
  bs::logical<T> b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     b[i] = bs::logical_andnot(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  pl_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::logical_andnot(aa1, aa2), bb);
//  STF_IEEE_EQUAL(aa1&&!aa2, bb);
}

STF_CASE_TPL("Check logical_andnot on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

template <typename T, std::size_t N, typename Env>
void testl(Env& runtime)
{
  namespace bs = boost::simd;
  using lT = bs::logical<T>;
  using pl_t = bs::pack<lT, N>;
  lT a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? bs::True<lT>() : bs::False<lT>();
    a2[i] = bs::True<lT>();
    b[i] = bs::logical_andnot(a1[i], a2[i]);
  }
  pl_t aa1(&a1[0], &a1[0]+N);
  pl_t aa2(&a2[0], &a2[0]+N);
  pl_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::logical_andnot(aa1, aa2), bb);
//  STF_EQUAL(aa1&&!aa2, bb);
}

STF_CASE_TPL("Check logical_andnot on pack of logical", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<bs::logical<T>>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  testl<T, N>(runtime);
  testl<T, N/2>(runtime);
  testl<T, N*2>(runtime);
}


