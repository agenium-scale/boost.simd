//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/stirling.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/function/round.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i*10+33);
    b[i] = bs::stirling(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::stirling(aa1), bb, 0.5);
}

STF_CASE_TPL("Check stirling on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL(" stirling",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T>;

  using bs::stirling;

  STF_EXPR_IS(stirling(p_t()),p_t);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(stirling(bs::Inf<p_t>()),  bs::Inf<p_t>(), 0.5);
  STF_ULP_EQUAL(stirling(bs::Minf<p_t>()), bs::Nan<p_t>(), 0.5);
  STF_ULP_EQUAL(stirling(bs::Mone<p_t>()), bs::Nan<p_t>(), 0.5);
  STF_ULP_EQUAL(stirling(bs::Nan<p_t>()),  bs::Nan<p_t>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::round(stirling(bs::One<p_t>())),  bs::One<p_t>(), 0.5);
  STF_ULP_EQUAL(bs::round(stirling(bs::Two<p_t>())),  bs::One<p_t>(), 0.5);
}
