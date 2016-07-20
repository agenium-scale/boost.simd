//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/comma.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" comma real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::comma;
  using r_t = decltype(comma(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(comma(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(comma(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(comma(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(comma(bs::One<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(comma(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" comma integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::comma;
  using r_t = decltype(comma(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(comma(bs::One<T>(),bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(comma(bs::One<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(comma(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_


