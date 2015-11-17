//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/tgamma.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/five.hpp>
#include <boost/simd/function/rsqrt.hpp>

STF_CASE_TPL (" gamma",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tgamma;
  using r_t = decltype(tgamma(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(tgamma(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(tgamma(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(tgamma(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(tgamma(bs::Zero<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(tgamma(bs::Mzero<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(tgamma(bs::Halfeps<T>()), tgamma(bs::Halfeps<T>(), bs::std_), 0.5);
  STF_ULP_EQUAL(tgamma(bs::Eps<T>()), tgamma(bs::Eps<T>(), bs::std_), 0.5);
  STF_ULP_EQUAL(tgamma(bs::Half<T>()), tgamma(bs::Half<T>(), bs::std_), 0);
  STF_ULP_EQUAL(tgamma(T(1.5)), tgamma(T(1.5), bs::std_), 0);
  STF_ULP_EQUAL(tgamma(T(2.5)), tgamma(T(2.5), bs::std_), 0.5);
  STF_ULP_EQUAL(tgamma(T(13.5)) , tgamma(T(13.5), bs::std_), 15);
  STF_ULP_EQUAL(tgamma(T(-0.1)),           tgamma(T(-0.1), bs::std_),         0.5);
  STF_ULP_EQUAL(tgamma(-bs::Half<T>()),    tgamma(-bs::Half<T>(), bs::std_),  0.5);
  STF_ULP_EQUAL(tgamma(-bs::Halfeps<T>()), tgamma(-bs::Halfeps<T>(), bs::std_), 0);
  STF_ULP_EQUAL(tgamma(T(-27.5)),            tgamma(T(-27.5), bs::std_),            3);
}

