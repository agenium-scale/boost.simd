//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/oneminus.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" oneminus signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneminus;
  using r_t = decltype(oneminus(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(oneminus(bs::Mone<T>()), bs::Two<T>());
  STF_EQUAL(oneminus(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(oneminus(bs::Valmax<T>()), bs::Valmin<T>()+bs::Two<T>());
  STF_EQUAL(oneminus(bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL (" oneminus unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneminus;
  using r_t = decltype(oneminus(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(oneminus(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(oneminus(bs::Two<T>()), bs::Valmax<T>());
  STF_EQUAL(oneminus(bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL(" oneminus floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneminus;
  using r_t = decltype(oneminus(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(oneminus(bs::Inf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(oneminus(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(oneminus(bs::Minf<T>()), bs::Inf<T>());
#endif
  STF_EQUAL(oneminus(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(oneminus(bs::Two<T>()), bs::Mone<T>());
  STF_EQUAL(oneminus(bs::Zero<T>()), bs::One<T>());
}

