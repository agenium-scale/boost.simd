//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/four.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::saturated_(bs::abs)(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::saturated_(bs::abs)(aa1), bb);
}

STF_CASE_TPL("Check saturated abs on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL( "Check saturated abs behavior with signed integral", STF_SIGNED_INTEGRAL_TYPES )
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  using bs::abs;
  using r_t = decltype(abs(p_t()));
  STF_TYPE_IS(r_t, p_t);

#ifndef BOOSp_t_SIMD_NO_INVALIDS
  STF_EQUAL(bs::saturated_(abs)(bs::Inf<p_t>()),  bs::Inf<r_t>());
  STF_EQUAL(bs::saturated_(abs)(bs::Minf<p_t>()),  bs::Inf<r_t>());
  STF_EQUAL(bs::saturated_(abs)(bs::Nan<p_t>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(bs::saturated_(abs)(bs::Zero<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(bs::saturated_(abs)(bs::One<p_t>()),  bs::One<r_t>());
  STF_EQUAL(bs::saturated_(abs)(bs::Mone<p_t>()), bs::One<r_t>());
}
