//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/safe_min.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/smallestposval.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::safe_min(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::safe_min(aa1), bb);
}

STF_CASE_TPL("Check safe_min on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" safe_minreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::safe_min;
  using p_t = bs::pack<T>;

  using r_t = decltype(safe_min(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(safe_min(bs::Inf<p_t>()), bs::Inf<r_t>());
  STF_EQUAL(safe_min(bs::Minf<p_t>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(safe_min(bs::Nan<p_t>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(safe_min(bs::Mone<p_t>()), bs::Sqrtsmallestposval<r_t>());
  STF_EQUAL(safe_min(bs::One<p_t>()), bs::Sqrtsmallestposval<r_t>());
  STF_EQUAL(safe_min(bs::Zero<p_t>()), bs::Zero<r_t>());
}

