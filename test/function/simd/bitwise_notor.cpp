//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/bitwise_notor.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;


  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(2*i);
     a2[i] = (i%2) ? T(i+N) : T(1);
     b[i] = bs::bitwise_notor(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::bitwise_notor(aa1, aa2), bb);
}

STF_CASE_TPL("Check bitwise_notor on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
 test<T, N>(runtime);
  test<T, N/2>(runtime);
 test<T, N*2>(runtime);
}

template <typename T, std::size_t N, typename Env>
void testm(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using iT = bd::as_integer_t<T, unsigned>;
  using p_t = bs::pack<T, N>;
  using pi_t = bs::pack<iT,N>;

  T a1[N], b1[N], b3[N];
  iT a2[N], a3[N], b2[N], b4[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i);
    a2[i] = iT(1) << (sizeof(iT)*8-1);
    a3[i] = iT(1);
  }
  for(std::size_t i = 0; i < N; ++i)
  {
     b1[i] = bs::bitwise_notor(a1[i], a2[i]);
     b2[i] = bs::bitwise_notor(a2[i], a1[i]);
     b3[i] = bs::bitwise_notor(a1[i], a3[i]);
     b4[i] = bs::bitwise_notor(a3[i], a1[i]);
  }
  p_t  aa1(&a1[0], &a1[0]+N);
  pi_t aa2(&a2[0], &a2[0]+N);
  pi_t aa3(&a3[0], &a3[0]+N);

  p_t  bb1(&b1[0], &b1[0]+N);
  p_t  bb3(&b3[0], &b3[0]+N);
  STF_IEEE_EQUAL(bs::bitwise_notor(aa1, aa2), bb1);
  STF_IEEE_EQUAL(bs::bitwise_notor(aa1, aa3), bb3);


  pi_t bb2(&b2[0], &b2[0]+N);
  pi_t bb4(&b4[0], &b4[0]+N);
  STF_IEEE_EQUAL(bs::bitwise_notor(aa2, aa1), bb2);
  STF_IEEE_EQUAL(bs::bitwise_notor(aa3, aa1), bb4);
}



STF_CASE_TPL("Check bitwise_notor on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  testm<T, N>(runtime);
  testm<T, N/2>(runtime);
  testm<T, N*2>(runtime);
}
