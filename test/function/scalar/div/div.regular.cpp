//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/div.hpp>
#include <scalar_test.hpp>

#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/ceil.hpp>

STF_CASE_TPL( "Check div behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(div(bs::Inf<T>(),  bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(div(bs::One<T>(),bs::Zero<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(div(bs::Zero<T>(), bs::Zero<T>()), bs::Nan<r_t>());
  STF_EQUAL(div(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
}


STF_CASE_TPL( "Check div behavior with options", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));
  STF_TYPE_IS(r_t, T);
  STF_EQUAL(div(bs::One<T>(), bs::Two<T>())                , bs::Half<r_t>());
  STF_EQUAL(div(bs::ceil      , bs::One<T>(), bs::Two<T>()), bs::One<r_t>());
  STF_EQUAL(div(bs::floor     , bs::One<T>(), bs::Two<T>()), bs::Zero<r_t>());
  STF_EQUAL(div(bs::round     , bs::One<T>(), bs::Two<T>()), bs::One<r_t>());
  STF_EQUAL(div(bs::nearbyint, bs::One<T>(), bs::Two<T>()), bs::Zero<r_t>());
  STF_EQUAL(div(bs::fix       , bs::One<T>(), bs::Two<T>()), bs::Zero<r_t>());

}

