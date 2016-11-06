//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/rsqrt.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/sqrt_2.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test_fast(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(2*i) : T(2*i+1);
    b[i] = bs::fast_(bs::rsqrt)(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::fast_(bs::rsqrt)(aa1), bb, 2048);
}

STF_CASE_TPL("Check fast rsqrt on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_fast<T, N>($);
  test_fast<T, N/2>($);
  test_fast<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(2*i) : T(2*i+1);
    b[i]  = bs::rsqrt(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::rsqrt(aa1), bb, 1);
}

STF_CASE_TPL("Check rsqrt on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL (" rsqrtreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rsqrt;
  using p_t = bs::pack<T>;
  using r_t = decltype(rsqrt(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(rsqrt(bs::Inf<p_t>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(rsqrt(bs::Minf<p_t>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(rsqrt(bs::Nan<p_t>()), bs::Nan<r_t>());
#endif
  STF_IEEE_EQUAL(rsqrt(bs::Mone<p_t>()), bs::Nan<r_t>());
  STF_EQUAL(rsqrt(bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(rsqrt(bs::Zero<p_t>()), bs::Inf<r_t>());
  STF_EQUAL(rsqrt(bs::Four<p_t>()), bs::Half<r_t>());
  STF_ULP_EQUAL(rsqrt(p_t(0.5)), bs::Sqrt_2<p_t>(), 0.5);
  STF_ULP_EQUAL(rsqrt(p_t(0.01)), p_t(10), 0.5);
  STF_ULP_EQUAL(rsqrt(p_t(0.0001)), p_t(100), 0.5);
} // end of test for floating_

STF_CASE_TPL( "fast rsqrt", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rsqrt;
  using p_t = bs::pack<T>;
  using r_t = decltype(bs::fast_(rsqrt)(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_ULP_EQUAL(rsqrt(bs::Mone<p_t>()), bs::Nan<p_t>(), 75);
  STF_ULP_EQUAL(rsqrt(bs::Nan<p_t>()), bs::Nan<p_t>(), 0.5);
  STF_ULP_EQUAL(rsqrt(bs::One<p_t>()), bs::One<p_t>(), 30);
  STF_ULP_EQUAL(rsqrt(bs::Four<p_t>()), bs::Half<p_t>(), 30);
  STF_ULP_EQUAL(rsqrt(bs::Half<p_t>()), bs::Sqrt_2<p_t>(), 70);
  STF_ULP_EQUAL(rsqrt(p_t(0.01)), p_t(10), 30);
  STF_ULP_EQUAL(rsqrt(p_t(0.0001)), p_t(100), 30);
}
