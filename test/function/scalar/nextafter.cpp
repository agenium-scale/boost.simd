//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/nextafter.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/bitincrement.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" nextafter real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nextafter;
  using r_t = decltype(nextafter(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(nextafter(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(nextafter(bs::Minf<T>(), bs::One<T>()), bs::Valmin<r_t>());
  STF_IEEE_EQUAL(nextafter(bs::Nan<T>(), bs::One<T>()), bs::Nan<r_t>());
  STF_EQUAL(nextafter(bs::One<T>(), bs::Inf<T>()), bs::One<r_t>()+bs::Eps<r_t>());
  STF_EQUAL(nextafter(bs::Valmax<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(nextafter(bs::Mone<T>(), bs::One<T>()), bs::Mone<r_t>()+bs::Eps<r_t>()/2);
  STF_EQUAL(nextafter(bs::Zero<T>(), bs::One<T>()), bs::Bitincrement<T>());
}

