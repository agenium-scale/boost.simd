//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitwise_or.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/three.hpp>



STF_CASE_TPL( "Check bitwise_or behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::bitwise_or;
  using r_t = decltype(bitwise_or(T(), T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bitwise_or(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(bitwise_or(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(bitwise_or(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(bitwise_or(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL("bitwise_or_ui", STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::bitwise_or;
  using r_t = decltype(bitwise_or(T(), T()));
  STF_TYPE_IS(r_t, T);

  STF_TYPE_IS(r_t, T);
  // specific values tests
  STF_EQUAL(bitwise_or(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL("bitwise_or_si", STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::bitwise_or;
  using r_t = decltype(bitwise_or(T(), T()));
  STF_TYPE_IS(r_t, T);


  // specific values tests
  STF_EQUAL(bitwise_or(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitwise_or(bs::One <T>(), bs::Two <T>()), bs::Three<r_t>());
}

STF_CASE_TPL("bitwise_or_mix", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::bitwise_or;
  using r_t = decltype(bitwise_or(T(), T()));
  STF_TYPE_IS(r_t, T);
  typedef typename  boost::dispatch::as_integer<T>::type siT;
  typedef typename  boost::dispatch::as_integer<T, unsigned>::type uiT;

  // return type conformity test
  STF_EXPR_IS(bitwise_or(T(),uiT()) , T);
  STF_EXPR_IS(bitwise_or(T(),siT()) , T);
  STF_EXPR_IS(bitwise_or(uiT(), T()), uiT);
  STF_EXPR_IS(bitwise_or(siT(), T()), siT);

  // specific values tests
  STF_EQUAL(bitwise_or(bs::Zero<T>(),bs::Zero<uiT>()), bs::Zero<T>());
  STF_EQUAL(bitwise_or(bs::Zero<T>(), bs::Zero<siT>()), bs::Zero<T>());
  STF_EQUAL(bitwise_or(bs::Valmin<siT>(),bs::Nan<T>()), bs::Mone<siT>());
  STF_EQUAL(bitwise_or(bs::Zero<uiT>(), bs::Nan<T>()), bs::Valmax<uiT>());
}



