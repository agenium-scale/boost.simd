//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/nbtrue.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>


STF_CASE_TPL (" nbtrue real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nbtrue;

  // specific values tests
  STF_EQUAL(nbtrue(bs::Inf<T>()) ,T(1));
  STF_EQUAL(nbtrue(bs::Minf<T>()),T(1));
  STF_EQUAL(nbtrue(bs::Mone<T>()),T(1));
  STF_EQUAL(nbtrue(bs::Nan<T>()) ,T(1));
  STF_EQUAL(nbtrue(bs::One<T>()) ,T(1));
  STF_EQUAL(nbtrue(bs::Zero<T>()), T(0));
} // end of test for floating_

STF_CASE_TPL (" nbtrue integer",  STF_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nbtrue;

  // specific values tests
  STF_EQUAL(nbtrue(bs::Mone<T>()), T(1));
  STF_EQUAL(nbtrue(bs::One<T>()) , T(1));
  STF_EQUAL(nbtrue(bs::Zero<T>()), T(0));
}
