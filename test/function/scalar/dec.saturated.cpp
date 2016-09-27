//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/dec.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>

STF_CASE_TPL (" bs::saturated_(dec) signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::dec;

  using r_t = decltype(bs::saturated_(dec)(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bs::saturated_(dec)(bs::Mone<T>()), bs::Mtwo<T>());
  STF_EQUAL(bs::saturated_(dec)(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(bs::saturated_(dec)(bs::Valmin<T>()), bs::Valmin<T>());
  STF_EQUAL(bs::saturated_(dec)(bs::Zero<T>()), bs::Mone<T>());
}

STF_CASE_TPL (" bs::saturated_(dec) unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::dec;

  using r_t = decltype(bs::saturated_(dec)(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bs::saturated_(dec)(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(bs::saturated_(dec)(bs::Two<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(dec)(bs::Zero<T>()), bs::Zero<T>());
}

STF_CASE_TPL(" bs::saturated_(dec) floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::dec;

  using r_t = decltype(bs::saturated_(dec)(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::saturated_(dec)(bs::Inf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(bs::saturated_(dec)(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(bs::saturated_(dec)(bs::Minf<T>()), bs::Minf<T>());
#endif
  STF_EQUAL(bs::saturated_(dec)(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(bs::saturated_(dec)(bs::Two<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(dec)(bs::Zero<T>()), bs::Mone<T>());
}
