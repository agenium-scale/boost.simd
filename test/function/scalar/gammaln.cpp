//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/gammaln.hpp>
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
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/five.hpp>
#include <boost/simd/constant/mtwo.hpp>

STF_CASE_TPL (" gammaln",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::gammaln;
  using r_t = decltype(gammaln(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(gammaln(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Zero<T>()), bs::Inf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(gammaln(bs::Mone<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Mtwo<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Two<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Mzero<T>()),         bs::Inf<r_t>(), 0);

  STF_ULP_EQUAL(gammaln(bs::Halfeps<T>()),       bs::std_(gammaln)(bs::Halfeps<T>()), 1);
  STF_ULP_EQUAL(gammaln(bs::Eps<T>()),           bs::std_(gammaln)(bs::Eps<T>()), 0.5);
  STF_ULP_EQUAL(gammaln(bs::Half<T>()),          bs::std_(gammaln)(bs::Half<T>()), 0.5);
  STF_ULP_EQUAL(gammaln(T(1.5)),                 bs::std_(gammaln)(T(1.5)), 1.5);
  STF_ULP_EQUAL(gammaln(T(2.5)),                 bs::std_(gammaln)(T(2.5)), 0.5);
  STF_ULP_EQUAL(gammaln(T(13)) ,                 bs::std_(gammaln)(T(13)), 0.5);
  STF_ULP_EQUAL(gammaln(T(13.5)) ,               bs::std_(gammaln)(T(13.5)), 0.5);
  STF_ULP_EQUAL(gammaln(T(-0.1)),                bs::std_(gammaln)(T(-0.1)),         1);
  STF_ULP_EQUAL(gammaln(-bs::Half<T>()),         bs::std_(gammaln)(-bs::Half<T>()),  0.5);
  STF_ULP_EQUAL(gammaln(-bs::Halfeps<T>()),      bs::std_(gammaln)(-bs::Halfeps<T>()), 0.5);
  STF_ULP_EQUAL(gammaln(T(-27.5)),               bs::std_(gammaln)(T(-27.5)),            3);
}
