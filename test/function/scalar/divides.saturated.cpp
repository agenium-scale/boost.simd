//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/divides.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" bs::saturated_(divides) signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divides;

  // return type conformity test
  STF_EXPR_IS(bs::saturated_(divides)(T(), T()), T);

  // specific values tests
  STF_EQUAL(bs::saturated_(divides)(bs::Mone<T>(), bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<T>(),bs::Mone<T>()), bs::Valmin<T>()+bs::One<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmin<T>(),bs::Mone<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Mone<T>(), bs::Zero<T>()), bs::Valmin<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Mtwo<T>(), bs::Zero<T>()), bs::Valmin<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmin<T>(), bs::Zero<T>()), bs::Valmin<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::One<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Two<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>());
} // end of test for signed_int_


STF_CASE_TPL (" bs::saturated_(divides) unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divides;

  // return type conformity test
  STF_EXPR_IS(bs::saturated_(divides)(T(), T()), T);

  // specific values tests
  STF_EQUAL(bs::saturated_(divides)(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::One<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Two<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>());
} // end of test for unsigned_int_
