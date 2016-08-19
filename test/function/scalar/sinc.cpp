//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sinc.hpp>
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

STF_CASE_TPL(" sinc",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sinc;

  STF_EXPR_IS(sinc(T()),T);


  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sinc(bs::Inf<T>()), bs::Zero<T>(), 0.5);
  STF_ULP_EQUAL(sinc(bs::Minf<T>()), bs::Zero<T>(), 0.5);
  STF_ULP_EQUAL(sinc(bs::Nan<T>()), bs::Nan<T>(), 0.5);
#endif
  STF_ULP_EQUAL(sinc(-bs::Pio_2<T>()), T(2)/(bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(sinc(-bs::Pio_4<T>()), bs::sin(bs::Pio_4<T>())/(bs::Pio_4<T>()), 0.5);
  STF_ULP_EQUAL(sinc(bs::Pio_2<T>()),  T(2)/(bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(sinc(bs::Pio_4<T>()), bs::sin(bs::Pio_4<T>())/(bs::Pio_4<T>()), 0.5);
  STF_ULP_EQUAL(sinc(bs::Eps<T>()), bs::One<T>(), 0.5);
  STF_ULP_EQUAL(sinc(bs::Mindenormal<T>()), bs::One<T>(), 0.5);
  STF_ULP_EQUAL(sinc(bs::Zero<T>()), bs::One<T>(), 0.5);
}
