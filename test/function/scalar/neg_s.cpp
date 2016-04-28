//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/neg.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>


STF_CASE_TPL( "Check bs::saturated_(bs::neg_s) behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using r_t = decltype(bs::saturated_(bs::neg)(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Inf<T>()),  bs::Minf<r_t>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(bs::saturated_(bs::neg)(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::One<T>()), bs::Mone<T>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Valmax<T>()), bs::Valmin<T>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Zero<T>()), bs::Zero<T>());
}


STF_CASE_TPL( "Check bs::saturated_(bs::neg) behavior with floating", STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using r_t = decltype(bs::saturated_(bs::neg)(T()));
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(bs::saturated_(bs::neg)(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::One<T>()), bs::Mone<T>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Valmax<T>()), bs::Valmin<T>()+bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Valmin<T>()+bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::neg)(bs::Zero<T>()), bs::Zero<T>());
}





