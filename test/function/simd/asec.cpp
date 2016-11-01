//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/asec.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/twopio_3.hpp>
#include <boost/simd/constant/pio_3.hpp>
#include <boost/simd/constant/two.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N], a2[N], c[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = i%2 ?N/T(i) : -(N/T(i));
    a2[i] = T(i)/10000;
    b[i] = bs::asec(a1[i]);
    c[i] = bs::asec(a2[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb (&b[0], &b[0]+N);
  p_t cc (&c[0], &c[0]+N);
  STF_ULP_EQUAL(bs::asec(aa1), bb, 1);
  STF_ULP_EQUAL(bs::asec(aa2), cc, 1);
}

STF_CASE_TPL("Check asec on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" asec",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::asec;
  using p_t = bs::pack<T>;
  using r_t = decltype(asec(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(asec(bs::Inf<p_t>()), bs::Pio_2<r_t>(), 0);
  STF_ULP_EQUAL(asec(bs::Minf<p_t>()), bs::Pio_2<r_t>(), 0);
  STF_ULP_EQUAL(asec(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(asec(bs::Zero<p_t>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(asec(-bs::Two<p_t>()), bs::Twopio_3<r_t>(), 0.5);
  STF_ULP_EQUAL(asec(bs::Mone<p_t>()), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(asec(bs::One<p_t>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(asec(bs::Two<p_t>()), bs::Pio_3<r_t>(), 0.5);
}
