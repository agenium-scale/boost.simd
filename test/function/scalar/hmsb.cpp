//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/hmsb.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/function/shr.hpp>

STF_CASE_TPL (" hmsb real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::hmsb;

  // specific values tests
  STF_EQUAL(hmsb(bs::Allbits<T>()), 1u);
  STF_EQUAL(hmsb(bs::Inf<T>()), 0u);
  STF_EQUAL(hmsb(bs::Minf<T>()), 1u);
  STF_EQUAL(hmsb(bs::Mone<T>()), 1u);
  STF_EQUAL(hmsb(bs::Nan<T>()), 1u);
  STF_EQUAL(hmsb(bs::One<T>()), 0u);
  STF_EQUAL(hmsb(bs::Signmask<T>()), 1u);
  STF_EQUAL(hmsb(bs::Zero<T>()), 0u);
} // end of test for real_







  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
//

