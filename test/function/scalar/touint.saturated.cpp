//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/touint.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/function/ldexp.hpp>

STF_CASE_TPL (" touint_s signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using r_t = decltype( bs::saturated_(bs::touint)(T()));

  STF_TYPE_IS( r_t, (bd::as_integer_t<T, unsigned>));

  STF_EQUAL(bs::saturated_(bs::touint)(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(bs::saturated_(bs::touint)(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(bs::saturated_(bs::touint)(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_
