//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/unary_minus.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>


STF_CASE_TPL( "Check bs::saturated_(bs::unary_minus_s) behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using r_t = decltype(bs::saturated_(bs::unary_minus)(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Inf<T>()),  bs::Minf<r_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(bs::saturated_(bs::unary_minus)(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::One<T>()), bs::Mone<T>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmax<T>()), bs::Valmin<T>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Zero<T>()), bs::Zero<T>());
}


STF_CASE_TPL( "Check bs::saturated_(bs::unary_minus) behavior with floating", STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using r_t = decltype(bs::saturated_(bs::unary_minus)(T()));
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::One<T>()), bs::Mone<T>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmax<T>()), bs::Valmin<T>()+bs::One<T>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmin<T>()+bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Zero<T>()), bs::Zero<T>());
}





