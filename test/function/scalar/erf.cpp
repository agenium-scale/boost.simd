//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/scalar/erf.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>

#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/rsqrt.hpp>

STF_CASE_TPL (" erf", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::erf;

  // return type conformity test
  STF_TYPE_IS(decltype(erf(bd::detail::declval<T>())), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(erf(bs::Minf<T>()), T(-1));
  STF_IEEE_EQUAL(erf(bs::Inf<T>()), T(1));
  STF_IEEE_EQUAL(erf(bs::Nan<T>()), bs::Nan<T>());
#endif

  STF_ULP_EQUAL(erf(T(0.1)), T(0.112462916018284892203275071744), 0.5);

  STF_ULP_EQUAL(erf(bs::Mzero<T>()), T(0), 0.5);
  STF_ULP_EQUAL(erf(T(0.5)), T(0.520499877813046537682746653892), 0.5);
  STF_ULP_EQUAL(erf(T(1)), T(0.842700792949714869341220635083), 0.5);
  STF_ULP_EQUAL(erf(T(2)), T(0.995322265018952734162069256367), 0.5);
  STF_ULP_EQUAL(erf(T(0)), T(0), 0.5);
  STF_ULP_EQUAL(erf(bs::Halfeps<T>()), bs::Eps<T>()*bs::rsqrt(bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(erf(T(5)), T(0.99999999999846254020557196515), 0.5);
  STF_ULP_EQUAL(erf(T(27)), T(1), 0.5);

  STF_ULP_EQUAL(erf(T(-0.1)), -T(0.112462916018284892203275071744), 0.5);
  STF_ULP_EQUAL(erf(-T(0.5)), -T(0.520499877813046537682746653892), 0.5);
  STF_ULP_EQUAL(erf(-T(1)), -T(0.842700792949714869341220635083), 0.5);
  STF_ULP_EQUAL(erf(-T(2)), -T(0.995322265018952734162069256367), 0.5);
  STF_ULP_EQUAL(erf(-bs::Halfeps<T>()), -bs::Eps<T>()*bs::rsqrt(bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(erf(-T(5)), -T(0.99999999999846254020557196515), 0.5);
  STF_ULP_EQUAL(erf(T(-27)), -T(1), 0.5);
}
