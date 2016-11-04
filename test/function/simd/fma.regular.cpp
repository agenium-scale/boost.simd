//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], a3[N], b[N];
  for(int i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     a3[i] = (i%2) ? T(i+2*N) : T(-(i+2*N));
     b[i] = bs::fma(a1[i], a2[i], a3[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t aa3(&a3[0], &a3[0]+N);
  p_t bb (&b [0], &b [0]+N);
  STF_EQUAL(bs::fma(aa1, aa2, aa3), bb);
}

STF_CASE_TPL("Check fma on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL (" fma real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::fma;
  using p_t = bs::pack<T>;

  // return type conformity test
  STF_EXPR_IS(fma(p_t(),p_t(),p_t()), p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(fma(bs::Inf<p_t>(), bs::Inf<p_t>(), bs::Inf<p_t>()), bs::Inf<p_t>());
  STF_IEEE_EQUAL(fma(bs::Minf<p_t>(), bs::Minf<p_t>(), bs::Minf<p_t>()), bs::Nan<p_t>());
  STF_IEEE_EQUAL(fma(bs::Nan<p_t>(), bs::Nan<p_t>(), bs::Nan<p_t>()), bs::Nan<p_t>());
#endif
  STF_EQUAL(fma(bs::Mone<p_t>(), bs::Mone<p_t>(), bs::Mone<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(fma(bs::One<p_t>(), bs::One<p_t>(), bs::One<p_t>()), bs::Two<p_t>());
  STF_EQUAL(fma(bs::Zero<p_t>(), bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for floating_

STF_CASE_TPL (" fma unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;

  using bs::fma;

  // return type conformity test
  STF_EXPR_IS(fma(p_t(),p_t(),p_t()), p_t);

  // specific values tests
  STF_EQUAL(fma(bs::One<p_t>(), bs::One<p_t>(), bs::One<p_t>()), bs::Two<p_t>());
  STF_EQUAL(fma(bs::Zero<p_t>(), bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" fma signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;

  using bs::fma;

  // return type conformity test
  STF_EXPR_IS(fma(p_t(),p_t(),p_t()), p_t);

  // specific values tests
  STF_EQUAL(fma(bs::Mone<p_t>(), bs::Mone<p_t>(), bs::Mone<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(fma(bs::One<p_t>(), bs::One<p_t>(), bs::One<p_t>()), bs::Two<p_t>());
  STF_EQUAL(fma(bs::Zero<p_t>(), bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for signed_int_
