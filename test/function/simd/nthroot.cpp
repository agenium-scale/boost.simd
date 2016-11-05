//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/nthroot.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/half.hpp>

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
  p_t aa1(&a1[0], &a1[0]+N);
  pi_t aa2(&a2[0], &a2[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::nthroot(aa1, aa2), bb, 1);
  STF_ULP_EQUAL(bs::fast_(bs::nthroot)(aa1, aa2), bb, 1);
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

STF_CASE_TPL (" nthroot",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nthroot;
  using p_t = bs::pack<T>;
  using pi_t = bd::as_integer_t<p_t>;
  using r_t = decltype(nthroot(p_t(), pi_t()));

  // return type conformity test
 STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(nthroot(bs::Inf<p_t>(),pi_t(3)), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Inf<p_t>(),pi_t(4)), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Minf<p_t>(),pi_t(3)), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Minf<p_t>(),pi_t(4)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Nan<p_t>(),pi_t(3)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Nan<p_t>(),pi_t(4)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Mone<p_t>(),pi_t(4)), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(nthroot(bs::Mone<p_t>(),pi_t(0)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::One <p_t>(),pi_t(0)), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Half<p_t>(),pi_t(0)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Two <p_t>(),pi_t(0)), bs::Inf <r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Zero<p_t>(),pi_t(0)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Two <p_t>(),pi_t(0)), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Half<p_t>(),pi_t(0)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Mone<p_t>(),pi_t(3)), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::One<p_t>(),pi_t(3)), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::One<p_t>(),pi_t(4)), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Zero<p_t>(),pi_t(3)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Zero<p_t>(),pi_t(4)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(p_t(-8),pi_t(3)), r_t(-2), 0.5);
  STF_ULP_EQUAL(nthroot(p_t(256),pi_t(4)), r_t(4), 0.5);
  STF_ULP_EQUAL(nthroot(p_t(8),pi_t(3)), r_t(2), 0.5);
  STF_ULP_EQUAL(nthroot(p_t(0.5), pi_t(4)), r_t(0.84089641525371454303112547623321), 0.5);
}



