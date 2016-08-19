//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/nextpow2.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/mthree.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" nextpow2 real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nextpow2;
  using r_t = decltype(nextpow2(T()));
  using iT = bd::as_integer_t<T>;

  // return type conformity test
  STF_TYPE_IS(r_t, iT);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(nextpow2(bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(nextpow2(bs::Minf<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(nextpow2(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(nextpow2(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(nextpow2(bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" nextpow2 unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nextpow2;
  using r_t = decltype(nextpow2(T()));
  using iT = bd::as_integer_t<T>;

  // return type conformity test
  STF_TYPE_IS(r_t, iT);

  // specific values tests
  STF_EQUAL(nextpow2(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(nextpow2(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(nextpow2(bs::Two <T>()), bs::One<r_t>());
  STF_EQUAL(nextpow2(bs::Three <T>()), bs::One<r_t>());
  STF_EQUAL(nextpow2(bs::Valmax <T>()), r_t(sizeof(T)*8-1));
}

STF_CASE_TPL (" nextpow2 signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nextpow2;
  using r_t = decltype(nextpow2(T()));
  using iT = bd::as_integer_t<T>;

  // return type conformity test
  STF_TYPE_IS(r_t, iT);

  // specific values tests
  STF_EQUAL(nextpow2(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(nextpow2(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(nextpow2(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(nextpow2(bs::Two <T>()), bs::One<r_t>());
  STF_EQUAL(nextpow2(bs::Three <T>()), bs::One<r_t>());
  STF_EQUAL(nextpow2(bs::Mtwo <T>()), bs::One<r_t>());
  STF_EQUAL(nextpow2(bs::Mthree <T>()), bs::One<r_t>());
  STF_EQUAL(nextpow2(bs::Valmin <T>()), r_t(sizeof(T)*8)-2);
  STF_EQUAL(nextpow2(bs::Valmax <T>()), r_t(sizeof(T)*8)-2);
}
