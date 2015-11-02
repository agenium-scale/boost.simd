//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/genmask.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/allbits.hpp>

STF_CASE_TPL (" genmask real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::genmask;
  using r_t = decltype(genmask(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(genmask(bs::Inf<T>()), bs::Allbits<r_t>());
  STF_IEEE_EQUAL(genmask(bs::Minf<T>()), bs::Allbits<r_t>());
  STF_IEEE_EQUAL(genmask(bs::Nan<T>()), bs::Allbits<r_t>());
#endif
  STF_EQUAL(genmask(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" genmask integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::genmask;
  using r_t = decltype(genmask(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
  STF_EQUAL(genmask(bs::One<T>()), bs::Allbits<r_t>());
  STF_EQUAL(genmask(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_
