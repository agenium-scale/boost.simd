//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/nbtrue.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
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
  STF_EQUAL(nbtrue(bs::Inf<T>()) ,1u);
  STF_EQUAL(nbtrue(bs::Minf<T>()),1u);
  STF_EQUAL(nbtrue(bs::Mone<T>()),1u);
  STF_EQUAL(nbtrue(bs::Nan<T>()) ,1u);
  STF_EQUAL(nbtrue(bs::One<T>()) ,1u);
  STF_EQUAL(nbtrue(bs::Zero<T>()), 0u);
} // end of test for floating_

STF_CASE_TPL (" nbtrue integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nbtrue;

  // specific values tests
  STF_EQUAL(nbtrue(bs::Mone<T>()), 1u);
  STF_EQUAL(nbtrue(bs::One<T>()) , 1u);
  STF_EQUAL(nbtrue(bs::Zero<T>()), 0u);
}
