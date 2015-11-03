//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/compare_eq.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" compare_eq",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::compare_eq;
  using r_t = decltype(compare_eq(T(), T()));


  // specific values tests
  STF_EQUAL(compare_eq(bs::One<T>(), bs::One<T>()),  r_t(true));
  STF_EQUAL(compare_eq(bs::One<T>(), bs::Zero<T>()), r_t(false));
  STF_EQUAL(compare_eq(bs::Zero<T>(), bs::One<T>()), r_t(false));

} // end of test for floating_


