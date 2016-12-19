//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/four.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = ((i%2) ? T(i*2) : T(-2*i))/T(3);
    b[i] = bs::ceil(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::ceil(aa1), bb);
}

STF_CASE_TPL("Check ceil on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" ceil real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::ceil;
  using p_t =  bs::pack<T>;
  // return type conformity test
  STF_EXPR_IS(ceil(p_t()), p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ceil(bs::Inf<p_t>()), bs::Inf<p_t>());
  STF_EQUAL(ceil(bs::Minf<p_t>()), bs::Minf<p_t>());
  STF_IEEE_EQUAL(ceil(bs::Nan<p_t>()), bs::Nan<p_t>());
#endif
  STF_EQUAL(ceil(bs::Mone<p_t>()), bs::Mone<p_t>());
  STF_EQUAL(ceil(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(ceil(bs::Zero<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(ceil(bs::Pi<p_t>()), bs::Four<p_t>());
  STF_EQUAL(ceil(p_t(-1.1)), p_t(-1));
  STF_EQUAL(ceil(p_t(1.1)), p_t(2));
} // end of test for floating_
