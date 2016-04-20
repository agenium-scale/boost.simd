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
#include <boost/simd/function/nthroot.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/options.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using iT =  bd::as_integer_t<T>;
  using p_t = bs::pack<T, N>;
  using pi_t= bs::pack<iT, N>;

  T a1[N], b[N];
  iT a2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : bs::rec(T(i));
    a2[i] = i+2;
    b[i] = bs::nthroot(a1[i], a2[i]) ;
  }
  p_t aa1(&a1[0], &a1[N]);
  pi_t aa2(&a2[0], &a2[N]);
  p_t bb (&b[0], &b[N]);

  STF_IEEE_EQUAL(bs::nthroot(aa1, aa2), bb);
}

STF_CASE_TPL("Check nthroot on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
