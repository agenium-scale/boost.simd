//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/atan2.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/threepio_4.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/all.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(1+i);
    a2[i] = (i%2) ? T(i+N) : T(2*i);
    b[i] = bs::atan2(a1[i], a2[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::atan2(aa1, aa2), bb, 1);
}

STF_CASE_TPL("Check atan2 on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL (" atan2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::atan2;
  using p_t = bs::pack<T>;


  using r_t = decltype(atan2(p_t(), p_t()));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(atan2(bs::Inf<p_t>(),bs::One<p_t>()), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<p_t>(),bs::Mone<p_t>()), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<p_t>(),bs::One<p_t>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<p_t>(),bs::Mone<p_t>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<p_t>(), bs::Minf<p_t>()), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<p_t>(), bs::Minf<p_t>()), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<p_t>(), bs::Inf<p_t>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<p_t>(), bs::Inf<p_t>()), -bs::Zero<r_t>(), 0.5);
  STF_EQUAL(bs::is_negative(atan2(bs::Mone<p_t>(), bs::Inf<p_t>())), bs::True<p_t>());
  STF_EQUAL(bs::is_positive(atan2(bs::One<p_t>(), bs::Inf<p_t>())), bs::True<p_t>());
  STF_ULP_EQUAL(atan2(bs::Minf<p_t>(),bs::Minf<p_t>()), -p_t(3)*bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<p_t>(),bs::Minf<p_t>()), p_t(3)*bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<p_t>(),bs::Inf<p_t>()), -bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<p_t>(),bs::Inf<p_t>()), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<p_t>(), bs::Inf<p_t>()), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<p_t>(),bs::One<p_t>()), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<p_t>(), bs::Minf<p_t>()), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<p_t>(),bs::One<p_t>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Nan<p_t>(), bs::Nan<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Nan<p_t>(), bs::Zero<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<p_t>(), bs::Nan<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<p_t>(),bs::Inf<p_t>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<p_t>(),bs::Minf<p_t>()), bs::Pi<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(atan2(bs::Half<p_t>(), bs::Half<p_t>()), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mhalf<p_t>(), bs::Mhalf<p_t>()), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<p_t>(), bs::Mone<p_t>()), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<p_t>(), bs::One<p_t>()), bs::Pio_4<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Mzero<p_t>(), bs::Zero<p_t>()), bs::Mzero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mzero<p_t>(), bs::Mzero<p_t>()), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mzero<p_t>(), bs::Mone<p_t>()), -bs::Pi<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Zero<p_t>(), bs::Mzero<p_t>()), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<p_t>(), bs::Mone<p_t>()), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<p_t>(), bs::Mzero<p_t>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<p_t>(), bs::Zero<p_t>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<p_t>(), bs::Mzero<p_t>()), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<p_t>(), bs::Zero<p_t>()), bs::Pio_2<r_t>(), 0.5);

}

