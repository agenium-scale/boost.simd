//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acospi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" acospi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acospi;

  using r_t = decltype(acospi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::pedantic_(bs::acospi)(bs::Inf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::pedantic_(bs::acospi)(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(bs::pedantic_(bs::acospi)(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(bs::pedantic_(bs::acospi)(bs::Half<T>()), r_t(1.0/3.0), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::acospi)(bs::Mhalf<T>()), r_t(2.0/3.0), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::acospi)(bs::Mone<T>()), r_t(1), 0);
  STF_ULP_EQUAL(bs::pedantic_(bs::acospi)(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(bs::pedantic_(bs::acospi)(bs::Zero<T>()), r_t(1.0/2.0), 0);
}
