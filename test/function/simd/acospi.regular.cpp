//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/acospi.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/std.hpp>
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

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = i%2 ?T(i)/N : -T(i)/N;
    b[i] = bs::acospi(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::acospi(aa1), bb, 4);
}

STF_CASE_TPL("Check acospi on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" acospi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T>;
  using bs::acospi;

  using r_t = decltype(acospi(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::acospi(bs::Inf<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::acospi(bs::Minf<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::acospi(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(bs::acospi(bs::Half<p_t>()), r_t(1.0/3.0), 0.5);
  STF_ULP_EQUAL(bs::acospi(bs::Mhalf<p_t>()), r_t(2.0/3.0), 0.5);
  STF_ULP_EQUAL(bs::acospi(bs::Mone<p_t>()), r_t(1), 0.5);
  STF_ULP_EQUAL(bs::acospi(bs::One<p_t>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::acospi(bs::Zero<p_t>()), r_t(1.0/2.0), 0.5);
}
