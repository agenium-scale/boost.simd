//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/acot.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/eps.hpp>



namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = i%2 ?T(i)/N : -T(i)/N;
    b[i] = bs::acot(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::acot(aa1), bb, 0.5);
}

STF_CASE_TPL("Check acot on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" acot",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T>;
  using bs::acot;

  using r_t = decltype(acot(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(acot(bs::Inf<p_t>()), r_t(0), 1.5);
  STF_ULP_EQUAL(acot(bs::Minf<p_t>()),  r_t(0), 1.5);
  STF_ULP_EQUAL(acot(bs::Nan<p_t>()), bs::Nan<r_t>(), 1.5);
#endif
  STF_ULP_EQUAL(acot(bs::Half<p_t>()), r_t(1.107148717794090e+00), 1.5);
  STF_ULP_EQUAL(acot(bs::Mhalf<p_t>()), r_t(-1.107148717794090e+00), 1.5);
  STF_ULP_EQUAL(acot(bs::Mone<p_t>()), r_t(-7.853981633974483e-01), 1.5);
  STF_ULP_EQUAL(acot(bs::One<p_t>()), r_t(7.853981633974483e-01), 1.5);
  STF_ULP_EQUAL(acot(bs::Zero<p_t>()), r_t(1.570796326794897e+00), 1.5);
  STF_ULP_EQUAL(acot(bs::rec(bs::Eps<p_t>())), bs::Eps<r_t>(), 1.5);
}


