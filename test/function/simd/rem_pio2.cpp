//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/rem_pio2.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;

  T a1[N], m[N], x[N];
  T e[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     auto z = bs::rem_pio2(a1[i]);
     e[i] =  z.first;
     m[i] =  z.second;

   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t mm(&m[0], &m[0]+N);
  p_t ee(&e[0], &e[0]+N);
  p_t xx(&x[0], &x[0]+N);
  auto zz =  bs::rem_pio2(aa1);
  p_t ee1 =  zz.first;
  p_t mm1 =  zz.second;
  STF_IEEE_EQUAL(ee1, ee);
  STF_IEEE_EQUAL(mm1, mm);
}

STF_CASE_TPL("Check rem_pio2 on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
