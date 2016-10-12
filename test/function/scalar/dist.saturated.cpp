//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/dist.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/mten.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/valmax.hpp>


STF_CASE_TPL (" bs::saturated_(bs::dist)_s real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  STF_EXPR_IS( bs::saturated_(bs::dist)(T(), T()), T );

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(bs::saturated_(bs::dist)(bs::Inf<T>() , bs::Inf<T>()) , bs::Nan<T>());
  STF_IEEE_EQUAL(bs::saturated_(bs::dist)(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(bs::saturated_(bs::dist)(bs::Nan<T>() , bs::Nan<T>()) , bs::Nan<T>());
#endif

  STF_EQUAL(bs::saturated_(bs::dist)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::Mone<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::One<T>(), bs::Three<T>()), bs::Two<T>());
}

STF_CASE_TPL (" bs::saturated_(bs::dist) integer_ui",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  STF_EXPR_IS( bs::saturated_(bs::dist)(T(), T()), T );

  STF_EQUAL(bs::saturated_(bs::dist)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::One<T>(), bs::Three<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::Zero<T>(), bs::Valmax<T>()), bs::Valmax<T>());
}

STF_CASE_TPL (" bs::saturated_(bs::dist) integer_si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  STF_EXPR_IS( bs::saturated_(bs::dist)(T(), T()), T );

  STF_EQUAL(bs::saturated_(bs::dist)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::Mone<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::One<T>(), bs::Three<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::Zero<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::Zero<T>(), bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(bs::dist)(bs::Valmin<T>(), bs::Zero<T>()), bs::Valmax<T>());

  STF_EQUAL(bs::saturated_(bs::dist)(bs::Ten<T>(), bs::Mten<T>()), (T(20)));
  STF_EQUAL(bs::saturated_(bs::dist)(bs::Mten<T>(), bs::Ten<T>()), (T(20)));
}

