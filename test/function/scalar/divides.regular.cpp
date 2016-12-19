//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/divides.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/zero.hpp>
#include <scalar_test.hpp>

#ifdef BOOST_MSVC
  #pragma warning(push)
  #pragma warning(disable: 4723) // potential divide by 0
#endif

STF_CASE_TPL( "Check divides behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::divides;
  using r_t = decltype(divides(T(), T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(divides(bs::Inf<T>(),  bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divides(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divides(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(divides(T(1), T(0)), bs::Inf<r_t>());
  STF_IEEE_EQUAL(divides(T(0), T(0)), bs::Nan<r_t>());
  STF_EQUAL(divides(T(1), T(1)), bs::One<r_t>());
}


STF_CASE_TPL( "Check divides saturated behavior", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::divides;
  using r_t = decltype(bs::saturated_(divides)(T(), T()));
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(bs::saturated_(divides)(bs::One<T>(),bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::One<T>(), bs::Zero<T>()), bs::Inf<r_t>());
}


#ifdef BOOST_MSVC
  #pragma warning(pop)
#endif
