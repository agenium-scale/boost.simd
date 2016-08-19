//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/rem_2pi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/twopi.hpp>
#include <boost/simd/constant/ten.hpp>

STF_CASE_TPL (" rem_2pi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rem_2pi;

  {
    T res = rem_2pi(bs::Zero<T>());
    STF_ULP_EQUAL( res, bs::Zero<T>(), 1.5);
    res = rem_2pi(bs::Pi<T>()-bs::Ten<T>()*bs::Eps<T>());
    STF_ULP_EQUAL( res, bs::Pi<T>()-bs::Ten<T>()*bs::Eps<T>(), 1.5);
    res = rem_2pi(bs::Pi<T>()+bs::Ten<T>()*bs::Eps<T>());
    STF_ULP_EQUAL( res, bs::Ten<T>()*bs::Eps<T>()-bs::Pi<T>(), 1.5);
    res = rem_2pi(bs::Twopi<T>());
    STF_ULP_EQUAL( res, bs::Zero<T>(), 1.5);
    res = rem_2pi(bs::Pio_2<T>());
    STF_ULP_EQUAL( res, bs::Pio_2<T>(), 1.5);
  }
} // end of test for floating_










