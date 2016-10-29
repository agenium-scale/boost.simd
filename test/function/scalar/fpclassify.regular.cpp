//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/fpclassify.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <cmath>

STF_CASE_TPL (" fpclassify",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fpclassify;

  using r_t = decltype(fpclassify(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(fpclassify(bs::Inf<T>()), FP_INFINITE);
  STF_EQUAL(fpclassify(bs::Minf<T>()), FP_INFINITE);
  STF_EQUAL(fpclassify(bs::Nan<T>()), FP_NAN);
#endif
  STF_EQUAL(fpclassify(bs::Half<T>()), FP_NORMAL);
  STF_EQUAL(fpclassify(bs::Mhalf<T>()), FP_NORMAL);
  STF_EQUAL(fpclassify(bs::Mone<T>()), FP_NORMAL);
  STF_EQUAL(fpclassify(bs::Mindenormal<T>()), FP_SUBNORMAL);
  STF_EQUAL(fpclassify(bs::Zero<T>()), FP_ZERO);
  STF_EQUAL(fpclassify(bs::Mzero<T>()), FP_ZERO);
}

