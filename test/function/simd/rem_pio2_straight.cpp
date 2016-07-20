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
#include <boost/simd/function/rem_pio2_straight.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;
  using iT = bd::as_integer_t<T>;
  using i_t = bs::pack<iT, N>;

  T a1[N], m[N];
  iT e[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     std::tie(e[i], m[i]) = bs::rem_pio2_straight(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t mm1;
  p_t mm(&m[0], &m[0]+N);
  i_t ee(&e[0], &e[0]+N), ee1;
  std::tie(ee1, mm1) = bs::rem_pio2_straight(aa1);
  STF_IEEE_EQUAL(ee1, ee);
  STF_IEEE_EQUAL(mm1, mm);
}

STF_CASE_TPL("Check rem_pio2_straight on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
