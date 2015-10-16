//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/inbtrue.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" inbtrue real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::inbtrue;

  // specific values tests
  STF_EQUAL(inbtrue(bs::Inf<T>()) , 1u);
  STF_EQUAL(inbtrue(bs::Minf<T>()), 1u);
  STF_EQUAL(inbtrue(bs::Mone<T>()), 1u);
  STF_EQUAL(inbtrue(bs::Nan<T>()) , 1u);
  STF_EQUAL(inbtrue(bs::One<T>()) , 1u);
  STF_EQUAL(inbtrue(bs::Zero<T>()), 0u);
} // end of test for floating_

STF_CASE_TPL (" inbtrue integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::inbtrue;

  // specific values tests
  STF_EQUAL(inbtrue(bs::Mone<T>()), 1u);
  STF_EQUAL(inbtrue(bs::One<T>()) , 1u);
  STF_EQUAL(inbtrue(bs::Zero<T>()), 0u);
}

