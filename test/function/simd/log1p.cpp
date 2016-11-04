//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/log1p.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/log_2.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : bs::rec(T(i));
    b[i] = bs::log1p(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::log1p(aa1), bb);
}

STF_CASE_TPL("Check log1p on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" log1p",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log1p;
  using p_t = bs::pack<T>;

  using r_t =  decltype(log1p(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(log1p(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log1p(bs::Minf<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log1p(bs::Mone<p_t>()), bs::Minf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(log1p(bs::Eps<p_t>()), bs::Eps<r_t>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::Eps<p_t>()), bs::Eps<r_t>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::One<p_t>()), bs::Log_2<r_t>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::Zero<p_t>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::Smallestposval<p_t>()), bs::Smallestposval<p_t>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::Eps<p_t>()), bs::Eps<p_t>(), 0.5);
}
