//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/gamma.hpp>
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
#include <boost/simd/function/std.hpp>
#include <simd_test.hpp>

STF_CASE_TPL (" gamma",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::gamma;
  using r_t = decltype(gamma(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(gamma(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(gamma(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(gamma(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(gamma(bs::Zero<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(gamma(bs::Mzero<T>()), bs::Minf<r_t>(), 0);
//   STF_ULP_EQUAL(gamma(bs::Halfeps<T>()), bs::std_(gamma)(bs::Halfeps<T>()), 1);
//   STF_ULP_EQUAL(gamma(bs::Eps<T>()), bs::std_(gamma)(bs::Eps<T>()), 0.5);
//   STF_ULP_EQUAL(gamma(bs::Half<T>()), bs::std_(gamma)(bs::Half<T>()), 1);
//   STF_ULP_EQUAL(gamma(T(1.5)), bs::std_(gamma)(T(1.5)), 0.5);
//   STF_ULP_EQUAL(gamma(T(2.5)), bs::std_(gamma)(T(2.5)), 0.5);
//   STF_ULP_EQUAL(gamma(T(13.5)) , bs::std_(gamma)(T(13.5)), 0);
//   STF_ULP_EQUAL(gamma(T(-0.1)),           bs::std_(gamma)(T(-0.1)),         1);
//   STF_ULP_EQUAL(gamma(-bs::Half<T>()),    bs::std_(gamma)(-bs::Half<T>()),  0.5);
//   STF_ULP_EQUAL(gamma(-bs::Halfeps<T>()), bs::std_(gamma)(-bs::Halfeps<T>()), 0.5);
//   STF_ULP_EQUAL(gamma(T(-27.5)),            bs::std_(gamma)(T(-27.5)),            3);
 }
