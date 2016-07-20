//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/pow2.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N],  b[N];
  bd::as_integer_t<T> a2 =  2;
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     b[i] = bs::pow2(a1[i], a2);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);//logical
  STF_IEEE_EQUAL(bs::pow2(aa1, a2), bb);
}

STF_CASE_TPL("Check pow2 on pack" , (float))//STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
//  test<T, N/2>($);
//  test<T, Nx2>($);
}
