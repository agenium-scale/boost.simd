//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <utility>
#include <tuple>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;
  using iT = bd::as_integer_t<T>;
  using i_t = bs::pack<iT, N>;

  T a1[N], m[N], mf[N];
  iT e[N], ef[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     std::tie(m[i], e[i]) = bs::frexp(a1[i]);
     std::tie(mf[i], ef[i])= bs::fast_(bs::frexp)(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t mm(&m[0], &m[0]+N);
  i_t ee(&e[0], &e[0]+N);
  i_t ee1, eef;
  p_t mm1, mmf;
  std::tie(mm1, ee1) = bs::frexp(aa1);
  STF_IEEE_EQUAL(mm1, mm);
  STF_IEEE_EQUAL(ee1, ee);
  std::tie(mmf, eef) = bs::fast_(bs::frexp)(aa1);
  p_t mmf1(&mf[0], &mf[0]+N);
  i_t eef1(&ef[0], &ef[0]+N);
  STF_IEEE_EQUAL(mmf, mmf1);
  STF_IEEE_EQUAL(eef, eef1);
}

STF_CASE_TPL("Check frexp on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
