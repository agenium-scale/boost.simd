//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/shift_right.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" shift_right integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::shift_right;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(shift_right(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(shift_right(bs::One<T>(),bs::One<iT>()), bs::Zero<r_t>());
  STF_EQUAL(shift_right(bs::One<T>(),bs::Zero<iT>()), bs::One<r_t>());
  STF_EQUAL(shift_right(bs::Zero<T>(),bs::One<iT>()), bs::Zero<r_t>());
} // end of test for integer_

STF_CASE_TPL (" shift_right real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::shift_right;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(shift_right(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(shift_right(bs::One<T>(),bs::Zero<iT>()), bs::One<r_t>());
  STF_EQUAL(shift_right(bs::Zero<T>(),bs::One<iT>()), bs::Zero<r_t>());
} // end of test for floating_
