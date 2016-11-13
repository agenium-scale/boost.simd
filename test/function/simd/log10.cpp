//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/log10.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/three.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : bs::rec(T(i));
    b[i] = bs::log10(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::log10(aa1), bb, 0.5);
}

STF_CASE_TPL("Check log10 on pack", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}



STF_CASE_TPL (" log10", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;
  using p_t = bs::pack<T>;

  using r_t = decltype(log10(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);
  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(log10(bs::Inf<p_t>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Minf<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Mone<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Zero<p_t>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(log10)(bs::Mzero<p_t>()), bs::Minf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(log10(bs::One<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Two<p_t>()), p_t(0.301029995663981195213738894724), 0);
  STF_ULP_EQUAL(log10(bs::Three<p_t>()),p_t(0.477121254719662437295027903255), 0.5);
}

STF_CASE_TPL (" log10 uint8",  (uint8_t))
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;
  using p_t = bs::pack<T>;

  using r_t = decltype(log10(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<p_t>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(log10(p_t(100)), p_t(2), 0);
}


STF_CASE_TPL (" log10 uint16",  (uint16_t))//STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;
  using p_t = bs::pack<T>;

  using r_t = decltype(log10(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<p_t>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(log10(p_t(100)), p_t(2), 0);
  STF_ULP_EQUAL(log10(p_t(1000)), p_t(3), 0);
  STF_ULP_EQUAL(log10(p_t(10000)), p_t(4), 0);
}

STF_CASE_TPL (" log10 uint32",  (uint32_t))//STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;
  using p_t = bs::pack<T>;

  using r_t = decltype(log10(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<p_t>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(log10(p_t(100)), p_t(2), 0);
  STF_ULP_EQUAL(log10(p_t(1000)), p_t(3), 0);
  STF_ULP_EQUAL(log10(p_t(10000)), p_t(4), 0);
  STF_ULP_EQUAL(log10(p_t(100000)), p_t(5), 0);
  STF_ULP_EQUAL(log10(p_t(1000000)), p_t(6), 0);
  STF_ULP_EQUAL(log10(p_t(10000000)), p_t(7), 0);
  STF_ULP_EQUAL(log10(p_t(100000000)), p_t(8), 0);
  STF_ULP_EQUAL(log10(p_t(1000000000)), p_t(9), 0);
}

STF_CASE_TPL (" log10 uint64",  (uint64_t))//STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;
  using p_t = bs::pack<T>;

  using r_t = decltype(log10(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<p_t>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(log10(p_t(100ull)), p_t(2), 0);
  STF_ULP_EQUAL(log10(p_t(1000ull)), p_t(3), 0);
  STF_ULP_EQUAL(log10(p_t(10000ull)), p_t(4), 0);
  STF_ULP_EQUAL(log10(p_t(100000ull)), p_t(5), 0);
  STF_ULP_EQUAL(log10(p_t(1000000ull)), p_t(6), 0);
  STF_ULP_EQUAL(log10(p_t(10000000ull)), p_t(7), 0);
  STF_ULP_EQUAL(log10(p_t(100000000ull)), p_t(8), 0);
  STF_ULP_EQUAL(log10(p_t(1000000000ull)), p_t(9), 0);
  STF_ULP_EQUAL(log10(p_t(10000000000ull)), p_t(10), 0);
  STF_ULP_EQUAL(log10(p_t(100000000000ull)), p_t(11), 0);
  STF_ULP_EQUAL(log10(p_t(1000000000000ull)), p_t(12), 0);
  STF_ULP_EQUAL(log10(p_t(10000000000000ull)), p_t(13), 0);
  STF_ULP_EQUAL(log10(p_t(100000000000000ull)), p_t(14), 0);
  STF_ULP_EQUAL(log10(p_t(1000000000000000ull)), p_t(15), 0);
  STF_ULP_EQUAL(log10(p_t(10000000000000000ull)), p_t(16), 0);
  STF_ULP_EQUAL(log10(p_t(100000000000000000ull)), p_t(17), 0);
  STF_ULP_EQUAL(log10(p_t(1000000000000000000ull)), p_t(18), 0);
  STF_ULP_EQUAL(log10(p_t(10000000000000000000ull)), p_t(19), 0);
}

STF_CASE_TPL (" log10 signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;
  using p_t = bs::pack<T>;

  using r_t = decltype(log10(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<p_t>()), bs::One<r_t>(), 0);
}

