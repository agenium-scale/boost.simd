//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/erf.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/rsqrt.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = T(i)/N;
     b[i] = bs::erf(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::erf(aa1), bb, 32);

}

STF_CASE_TPL("Check erf2 on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" erf", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::erf;
 using p_t = bs::pack<T>;

  // return type conformity test
  STF_TYPE_IS(decltype(erf(std::declval<p_t>())), p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(erf(bs::Minf<p_t>()), p_t(-1), 0);
  STF_ULP_EQUAL(erf(bs::Inf<p_t>()), p_t(1), 0);
  STF_ULP_EQUAL(erf(bs::Nan<p_t>()), bs::Nan<p_t>(), 0);
#endif

  STF_ULP_EQUAL(erf(p_t(0.1)), p_t(0.112462916018284892203275071744), 10);

  STF_ULP_EQUAL(erf(bs::Mzero<p_t>()), p_t(0), 0);
  STF_ULP_EQUAL(erf(p_t(0.5)), p_t(0.520499877813046537682746653892), 5.5);
  STF_ULP_EQUAL(erf(p_t(1)), p_t(0.842700792949714869341220635083), 0.5);
  STF_ULP_EQUAL(erf(p_t(2)), p_t(0.995322265018952734162069256367), 0);
  STF_ULP_EQUAL(erf(p_t(0)), p_t(0), 0);
  STF_ULP_EQUAL(erf(bs::Halfeps<p_t>()), bs::Eps<p_t>()*bs::rsqrt(bs::Pi<p_t>()), 6);
  STF_ULP_EQUAL(erf(p_t(5)), p_t(0.99999999999846254020557196515), 0);
  STF_ULP_EQUAL(erf(p_t(27)), p_t(1), 0);

  STF_ULP_EQUAL(erf(p_t(-0.1)), -p_t(0.112462916018284892203275071744), 10);
  STF_ULP_EQUAL(erf(-p_t(0.5)), -p_t(0.520499877813046537682746653892), 5.5);
  STF_ULP_EQUAL(erf(-p_t(1)), -p_t(0.842700792949714869341220635083), 0.5);
  STF_ULP_EQUAL(erf(-p_t(2)), -p_t(0.995322265018952734162069256367), 0);
  STF_ULP_EQUAL(erf(-bs::Halfeps<p_t>()), -bs::Eps<p_t>()*bs::rsqrt(bs::Pi<p_t>()), 6);
  STF_ULP_EQUAL(erf(-p_t(5)), -p_t(0.99999999999846254020557196515), 0);
  STF_ULP_EQUAL(erf(p_t(-27)), -p_t(1), 0);
}
