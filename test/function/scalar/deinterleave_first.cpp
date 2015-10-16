//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/deinterleave_first.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" deinterleave_first real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::deinterleave_first;

  // return type conformity test
  STF_EXPR_IS(deinterleave_first(T()), T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(deinterleave_first(bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(deinterleave_first(bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(deinterleave_first(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(deinterleave_first(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(deinterleave_first(bs::One<T>()), bs::One<T>());
  STF_EQUAL(deinterleave_first(bs::Zero<T>()), bs::Zero<T>());
} // end of test for floating_

STF_CASE_TPL (" deinterleave_first unsigned_int",  STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::deinterleave_first;
  // return type conformity test
  STF_EXPR_IS(deinterleave_first(T()), T);


  // specific values tests
  STF_EQUAL(deinterleave_first(bs::One<T>()), bs::One<T>());
  STF_EQUAL(deinterleave_first(bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" deinterleave_first signed_int",  STF_SIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::deinterleave_first;

  // return type conformity test
  STF_EXPR_IS(deinterleave_first(T()), T);

  // specific values tests
  STF_EQUAL(deinterleave_first(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(deinterleave_first(bs::One<T>()), bs::One<T>());
  STF_EQUAL(deinterleave_first(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_


