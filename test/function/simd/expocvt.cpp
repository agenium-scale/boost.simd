//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/expocvt.hpp>
#include <boost/simd/function/is_even.hpp>
#include <boost/simd/function/complement.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/minf.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;

  T a1[N];
  T b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = T(i+1);
     b[i]  = bs::expocvt(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::expocvt(aa1), bb);
}

STF_CASE_TPL("Check expocvt on pack",STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

STF_CASE_TPL (" expocvt real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using iT = bd::as_integer_t<T>;
  using bs::expocvt;
  using p_t = bs::pack<T>;
  using r_t = decltype(expocvt(p_t()));


  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests

  for( iT i= bs::Minexponent<T>(); i < bs::Maxexponent<T>(); ++i)
  {
    p_t z1 = expocvt(p_t(i));
    STF_EQUAL(z1, p_t(std::ldexp(T(1), i)));
  }

} // end of test for floating_
