//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sincpi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/sinpi.hpp>

STF_CASE_TPL(" sinc",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sincpi;

  STF_EXPR_IS(sincpi(T()),T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sincpi(bs::Inf<T>()), bs::Zero<T>(), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Minf<T>()), bs::Zero<T>(), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Nan<T>()), bs::Nan<T>(), 1.0);
#endif
  STF_ULP_EQUAL(sincpi(-T(1)/T(2)), T(2)/(bs::Pi<T>()), 1.0);
  STF_ULP_EQUAL(sincpi(-T(1)/T(4)), bs::sinpi(T(1)/T(4))*T(4)/(bs::Pi<T>()), 1.0);
  STF_ULP_EQUAL(sincpi(T(1)/T(2)),  T(2)/(bs::Pi<T>()), 1.0);
  STF_ULP_EQUAL(sincpi(T(1)/T(4)), bs::sinpi(T(1)/T(4))*T(4)/(bs::Pi<T>()), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Eps<T>()), bs::One<T>(), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Mindenormal<T>()), bs::One<T>(), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Zero<T>()), bs::One<T>(), 1.0);
}
