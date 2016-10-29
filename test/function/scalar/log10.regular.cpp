//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/log10.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/three.hpp>

STF_CASE_TPL (" log10", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;

  using r_t = decltype(log10(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);
  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(log10(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Mone<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Zero<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(log10)(bs::Mzero<T>()), bs::Minf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(log10(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Two<T>()), T(0.301029995663981195213738894724), 0);
  STF_ULP_EQUAL(log10(bs::Three<T>()),T(0.477121254719662437295027903255), 0.5);
}

STF_CASE_TPL (" log10 uint8",  (uint8_t))
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;

  using r_t = decltype(log10(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(log10(T(100)), T(2), 0);
}


STF_CASE_TPL (" log10 uint16",  (uint16_t))//STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;

  using r_t = decltype(log10(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(log10(T(100)), T(2), 0);
  STF_ULP_EQUAL(log10(T(1000)), T(3), 0);
  STF_ULP_EQUAL(log10(T(10000)), T(4), 0);
}

STF_CASE_TPL (" log10 uint32",  (uint32_t))//STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;

  using r_t = decltype(log10(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(log10(T(100)), T(2), 0);
  STF_ULP_EQUAL(log10(T(1000)), T(3), 0);
  STF_ULP_EQUAL(log10(T(10000)), T(4), 0);
  STF_ULP_EQUAL(log10(T(100000)), T(5), 0);
  STF_ULP_EQUAL(log10(T(1000000)), T(6), 0);
  STF_ULP_EQUAL(log10(T(10000000)), T(7), 0);
  STF_ULP_EQUAL(log10(T(100000000)), T(8), 0);
  STF_ULP_EQUAL(log10(T(1000000000)), T(9), 0);
}

STF_CASE_TPL (" log10 uint64",  (uint64_t))//STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;

  using r_t = decltype(log10(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(log10(T(100ull)), T(2), 0);
  STF_ULP_EQUAL(log10(T(1000ull)), T(3), 0);
  STF_ULP_EQUAL(log10(T(10000ull)), T(4), 0);
  STF_ULP_EQUAL(log10(T(100000ull)), T(5), 0);
  STF_ULP_EQUAL(log10(T(1000000ull)), T(6), 0);
  STF_ULP_EQUAL(log10(T(10000000ull)), T(7), 0);
  STF_ULP_EQUAL(log10(T(100000000ull)), T(8), 0);
  STF_ULP_EQUAL(log10(T(1000000000ull)), T(9), 0);
  STF_ULP_EQUAL(log10(T(10000000000ull)), T(10), 0);
  STF_ULP_EQUAL(log10(T(100000000000ull)), T(11), 0);
  STF_ULP_EQUAL(log10(T(1000000000000ull)), T(12), 0);
  STF_ULP_EQUAL(log10(T(10000000000000ull)), T(13), 0);
  STF_ULP_EQUAL(log10(T(100000000000000ull)), T(14), 0);
  STF_ULP_EQUAL(log10(T(1000000000000000ull)), T(15), 0);
  STF_ULP_EQUAL(log10(T(10000000000000000ull)), T(16), 0);
  STF_ULP_EQUAL(log10(T(100000000000000000ull)), T(17), 0);
  STF_ULP_EQUAL(log10(T(1000000000000000000ull)), T(18), 0);
  STF_ULP_EQUAL(log10(T(10000000000000000000ull)), T(19), 0);
}

STF_CASE_TPL (" log10 signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log10;

  using r_t = decltype(log10(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_ULP_EQUAL(log10(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log10(bs::Ten<T>()), bs::One<r_t>(), 0);
}

