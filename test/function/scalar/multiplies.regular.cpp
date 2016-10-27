//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/multiplies.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL( "Check multiplies behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::multiplies;
  using r_t = decltype(multiplies(T(), T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(multiplies(bs::Inf<T>(),  bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(multiplies(bs::Minf<T>(), bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(multiplies(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(multiplies(bs::One<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(multiplies(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(multiplies(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
}



STF_CASE_TPL( "Check multiplies saturated behavior", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::multiplies;
  using r_t = decltype(bs::saturated_(multiplies)(T(), T()));
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(bs::saturated_(multiplies)(bs::One<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(bs::saturated_(multiplies)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}



