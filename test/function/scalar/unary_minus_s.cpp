//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/unary_minus_s.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>


STF_CASE_TPL( "Check unary_minus_s behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::unary_minus_s;
  using r_t = decltype(unary_minus_s(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(unary_minus_s(bs::Inf<T>()),  bs::Minf<r_t>());
  STF_EQUAL(unary_minus_s(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(unary_minus_s(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(unary_minus_s(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(unary_minus_s(bs::One<T>()), bs::Mone<T>());
  STF_EQUAL(unary_minus_s(bs::Valmax<T>()), bs::Valmin<T>());
  STF_EQUAL(unary_minus_s(bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(unary_minus_s(bs::Zero<T>()), bs::Zero<T>());
}


STF_CASE_TPL( "Check unary_minus_s behavior with floating", STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::unary_minus_s;
  using r_t = decltype(unary_minus_s(T()));
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(unary_minus_s(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(unary_minus_s(bs::One<T>()), bs::Mone<T>());
  STF_EQUAL(unary_minus_s(bs::Valmax<T>()), bs::Valmin<T>()+bs::One<T>());
  STF_EQUAL(unary_minus_s(bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(unary_minus_s(bs::Valmin<T>()+bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(unary_minus_s(bs::Zero<T>()), bs::Zero<T>());
}





