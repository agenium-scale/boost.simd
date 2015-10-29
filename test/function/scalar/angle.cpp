//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/angle.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" angle real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::angle;
  using r_t = decltype(angle(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(angle(bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(angle(bs::Minf<T>()), bs::Pi<r_t>());
  STF_IEEE_EQUAL(angle(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(angle(bs::Mone<T>()), bs::Pi<r_t>());
  STF_EQUAL(angle(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(angle(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_


