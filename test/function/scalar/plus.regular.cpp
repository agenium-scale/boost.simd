//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/plus.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/saturated.hpp>

STF_CASE_TPL( "Check plus behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::plus;
  using r_t = decltype(plus(T(), T()));
  STF_TYPE_IS(r_t, T);
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(plus(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(plus(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(plus(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(plus(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(plus(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL( "Check plus saturated behavior", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::plus;
  using r_t = decltype(bs::saturated_(plus)(T(), T()));
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(bs::saturated_(plus)(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(bs::saturated_(plus)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}



