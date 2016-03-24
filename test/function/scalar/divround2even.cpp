//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/div.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" div real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));

  STF_IEEE_EQUAL(div(bs::Inf<T>(), bs::Inf<T>(), bs::round2even), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::Minf<T>(), bs::Minf<T>(), bs::round2even), bs::Nan<r_t>());
  STF_EQUAL(div(bs::Mone<T>(), bs::Mone<T>(), bs::round2even), bs::One<r_t>());
  STF_IEEE_EQUAL(div(bs::Nan<T>(), bs::Nan<T>(), bs::round2even), bs::Nan<r_t>());
  STF_EQUAL(div(bs::One<T>(), bs::One<T>(), bs::round2even), bs::One<r_t>());
} // end of test for floating_

STF_CASE_TPL (" div unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::div;
  using r_t = decltype(div(T(), T()));

  STF_EQUAL(div(bs::One<T>(), bs::One<T>(), bs::round2even), bs::One<r_t>());
  STF_EQUAL(div(T(5), T(2), bs::round2even), T(2));
  STF_EQUAL(div(T(7), T(2), bs::round2even), T(4));
  STF_EQUAL(div(T(9), T(3), bs::round2even), T(3));
  STF_EQUAL(div(T(10), T(3), bs::round2even), T(3));
  STF_EQUAL(div(T(11), T(3), bs::round2even), T(4));
  STF_EQUAL(div(T(12), T(3), bs::round2even), T(4));
  STF_EQUAL(div(T(18), T(6), bs::round2even), T(3));
  STF_EQUAL(div(T(20), T(6), bs::round2even), T(3));
  STF_EQUAL(div(T(22), T(6), bs::round2even), T(4));
  STF_EQUAL(div(T(24), T(6), bs::round2even), T(4));
  STF_EQUAL(div(bs::Valmax<T>(),bs::Two<T>(), bs::round2even), bs::Valmax<T>()/bs::Two<T>()+bs::One<T>());

} // end of test for unsigned_int_

STF_CASE_TPL (" div signed_int", STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));

  STF_EQUAL(div(bs::Mone<T>(), bs::Mone<T>(), bs::round2even), bs::One<r_t>());
  STF_EQUAL(div(bs::One<T>(), bs::One<T>(), bs::round2even), bs::One<r_t>());
  STF_EQUAL(div(T(5), T(2), bs::round2even), T(2));
  STF_EQUAL(div(T(7), T(2), bs::round2even), T(4));
  STF_EQUAL(div(T(-5), T(2), bs::round2even), T(-2));
  STF_EQUAL(div(T(-7), T(2), bs::round2even), T(-4));
  STF_EQUAL(div(T(-4),T(0), bs::round2even), bs::Valmin<r_t>());
  STF_EQUAL(div(T(4),T(0), bs::round2even), bs::Valmax<r_t>());
  STF_EQUAL(div(T(4),T(3), bs::round2even), T(1));
  STF_EQUAL(div(T(-4),T(-3), bs::round2even), T(1));
  STF_EQUAL(div(T(4),T(-3), bs::round2even), T(-1));
  STF_EQUAL(div(T(-4),T(3), bs::round2even), T(-1));
  STF_EQUAL(div(T(5),T(3), bs::round2even), T(2));
  STF_EQUAL(div(T(-5),T(-3), bs::round2even), T(2));
  STF_EQUAL(div(T(5),T(-3), bs::round2even), T(-2));
  STF_EQUAL(div(T(-5),T(3), bs::round2even), T(-2));

  STF_EQUAL(div(T(5),T(4), bs::round2even), T(1));
  STF_EQUAL(div(T(-5),T(-4), bs::round2even), T(1));
  STF_EQUAL(div(T(5),T(-4), bs::round2even), T(-1));
  STF_EQUAL(div(T(-5),T(4), bs::round2even), T(-1));
  STF_EQUAL(div(T(6),T(4), bs::round2even), T(2));
  STF_EQUAL(div(T(-6),T(-4), bs::round2even), T(2));
  STF_EQUAL(div(T(6),T(-4), bs::round2even), T(-2));
  STF_EQUAL(div(T(-6),T(4), bs::round2even), T(-2));
  STF_EQUAL(div(T(8),T(4), bs::round2even), T(2));
  STF_EQUAL(div(T(-8),T(-4), bs::round2even), T(2));
  STF_EQUAL(div(T(8),T(-4), bs::round2even), T(-2));
  STF_EQUAL(div(T(-8),T(4), bs::round2even), T(-2));
  STF_EQUAL(div(T(9),T(4), bs::round2even), T(2));
  STF_EQUAL(div(T(-9),T(-4), bs::round2even), T(2));
  STF_EQUAL(div(T(9),T(-4), bs::round2even), T(-2));
  STF_EQUAL(div(T(-9),T(4), bs::round2even), T(-2));
  STF_EQUAL(div(T(10),T(4), bs::round2even), T(2));
  STF_EQUAL(div(T(-10),T(-4), bs::round2even), T(2));
  STF_EQUAL(div(T(10),T(-4), bs::round2even), T(-2));
  STF_EQUAL(div(T(-10),T(4), bs::round2even), T(-2));

} // end of test for signed_int_

