//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ifnot_minus.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>
STF_CASE_TPL (" ifnot_minus real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnot_minus;
  using bs::logical;
  using r_t = decltype(ifnot_minus(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(ifnot_minus(T(0),T(1),T(2)), T(-1));
  STF_EQUAL(ifnot_minus(T(1),T(1),T(2)), T(1));
  STF_EQUAL(ifnot_minus(T(1),bs::Inf<T>(),bs::Inf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(ifnot_minus(T(0),bs::Minf<T>(),bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(ifnot_minus(T(0),bs::Nan<T>(),bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(ifnot_minus(T(0),bs::Zero<T>(),bs::One<T>()), bs::Mone<r_t>());
} // end of test for floating_

STF_CASE_TPL (" ifnot_minus integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnot_minus;
  using bs::logical;
  using r_t = decltype(ifnot_minus(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(ifnot_minus(logical<T>(T(-1)),T(1),T(2)), T(1));
  STF_EQUAL(ifnot_minus(logical<T>(T(0)),T(2),T(1)), T(1));
  STF_EQUAL(ifnot_minus(logical<T>(bs::Zero<T>()),bs::Zero<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(ifnot_minus(T(-1),T(1),T(2)), T(1));
  STF_EQUAL(ifnot_minus(T(0),T(2),T(1)), T(1));
  STF_EQUAL(ifnot_minus(bs::Zero<T>(),bs::Zero<T>(),bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_

