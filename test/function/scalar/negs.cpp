//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/negs.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" negs real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::negs;
  using r_t = decltype(negs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(negs(bs::Inf<T>()), bs::Minf<T>());
  STF_EQUAL(negs(bs::Minf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(negs(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(negs(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(negs(bs::One<T>()), bs::Mone<T>());
  STF_EQUAL(negs(bs::Valmax<T>()), bs::Valmin<T>());
  STF_EQUAL(negs(bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(negs(bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(negs(T(100)), T(-100));
} // end of test for floating_

STF_CASE_TPL (" negs signed_int",  STF_SIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::negs;
  using r_t = decltype(negs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(negs(T(100)), T(-100));
  STF_EQUAL(negs(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(negs(bs::One<T>()), bs::Mone<T>());
  STF_EQUAL(negs(bs::Valmax<T>()), -bs::Valmax<T>());
  STF_EQUAL(negs(bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(negs(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_
