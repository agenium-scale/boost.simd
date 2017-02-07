//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/rrol.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  static const std::size_t N1 = sizeof(T)*8-1;
  T a1[N], b[N], c[N], d[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     b[i] = bs::rrol(a1[i], 1);
     c[i] = bs::rrol(a1[i], N1/2);
     d[i] = bs::rrol(a1[i], N1-1);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t cc(&c[0], &c[0]+N);
  p_t dd(&d[0], &d[0]+N);
  STF_IEEE_EQUAL(bs::rrol(aa1, 1), bb);
  STF_IEEE_EQUAL(bs::rrol(aa1, N1/2), cc);
  STF_IEEE_EQUAL(bs::rrol(aa1, N1-1), dd);
}

STF_CASE_TPL("Check rrol on pack" , STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
