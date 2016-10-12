//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/inc.hpp>
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
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" bs::saturated_(bs::inc) signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using r_t = decltype(bs::saturated_(bs::inc)(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bs::saturated_(bs::inc)(bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(bs::saturated_(bs::inc)(bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(bs::inc)(bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::inc)(bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL (" bs::saturated_(bs::inc) unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using r_t = decltype(bs::saturated_(bs::inc)(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bs::saturated_(bs::inc)(bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(bs::inc)(bs::Two<T>()), bs::Three<T>());
  STF_EQUAL(bs::saturated_(bs::inc)(bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL(" bs::saturated_(bs::inc) floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using r_t = decltype(bs::saturated_(bs::inc)(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::saturated_(bs::inc)(bs::Inf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(bs::saturated_(bs::inc)(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(bs::saturated_(bs::inc)(bs::Minf<T>()), bs::Minf<T>());
#endif
  STF_EQUAL(bs::saturated_(bs::inc)(bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(bs::inc)(bs::Two<T>()), bs::Three<T>());
  STF_EQUAL(bs::saturated_(bs::inc)(bs::Zero<T>()), bs::One<T>());
}
