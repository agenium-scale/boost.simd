//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/compare_equal.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" compare_equal",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::compare_equal;
  using r_t = decltype(compare_equal(T(), T()));


  // specific values tests
  STF_EQUAL(compare_equal(bs::One<T>(), bs::One<T>()),  r_t(true));
  STF_EQUAL(compare_equal(bs::One<T>(), bs::Zero<T>()), r_t(false));
  STF_EQUAL(compare_equal(bs::Zero<T>(), bs::One<T>()), r_t(false));

} // end of test for floating_


