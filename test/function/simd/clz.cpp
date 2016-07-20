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
#include <boost/simd/function/clz.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;
  using iT =  bd::as_integer_t<T>;
  using i_t=  bs::pack<iT, N>;

  T a1[N];
  iT b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = i == 0 ? T(1) : T(bs::max(T(a1[i-1]*3), T(1)));
    b[i] = bs::clz(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  i_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::clz(aa1), bb);
}

STF_CASE_TPL("Check clz on pack", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
   test<T, N/2>($);
   test<T, N*2>($);
}
