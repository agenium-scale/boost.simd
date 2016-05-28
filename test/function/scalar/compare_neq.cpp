//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/compare_neq.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" compare_neq",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::compare_neq;
  using r_t = decltype(compare_neq(T(), T()));

  // specific values tests
  STF_EQUAL(compare_neq(bs::One<T>(), bs::One<T>()),  r_t(false));
  STF_EQUAL(compare_neq(bs::One<T>(), bs::Zero<T>()), r_t(true));
  STF_EQUAL(compare_neq(bs::Zero<T>(), bs::One<T>()), r_t(true));

} // end of test for floating_


