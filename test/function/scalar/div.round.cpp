//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/div.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" divreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(div(bs::round, bs::Inf<T>(), bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::round, bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::round, bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(div(bs::round, T(4),T(0)), bs::Inf<r_t>());
  STF_EQUAL(div(bs::round, T(4),T(3)), bs::One<r_t>());
  STF_EQUAL(div(bs::round, bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(div(bs::round, bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(div(bs::round, bs::Mone<T>(),bs::Zero<T>()), bs::Minf<r_t>());
  STF_EQUAL(div(bs::round, bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(div(bs::round, bs::One<T>(),bs::Zero<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(div(bs::round, bs::Zero<T>(),bs::Zero<T>()), bs::Nan<r_t>());
} // end of test for floating_

STF_CASE_TPL (" divunsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));

  STF_EQUAL(div(bs::round, T(4),T(0)), bs::Valmax<r_t>());
  STF_EQUAL(div(bs::round, T(4),T(3)), T(1));
  STF_EQUAL(div(bs::round, T(6),T(4)), T(2));
  STF_EQUAL(div(bs::round, bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(div(bs::round, bs::Valmax<T>(),  bs::Two<T>()), bs::Valmax<r_t>()/bs::Two<T>()+bs::One<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" divsigned_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::div;
  using r_t = decltype(div(T(), T()));
  STF_TYPE_IS(r_t,T);

  // specific values tests
  STF_EQUAL(div(bs::round, T(-4),T(0)), bs::Valmin<r_t>());
  STF_EQUAL(div(bs::round, T(4),T(0)), bs::Valmax<r_t>());
  STF_EQUAL(div(bs::round, T(4),T(3)), T(1));
  STF_EQUAL(div(bs::round, T(-4),T(-3)), T(1));
  STF_EQUAL(div(bs::round, T(4),T(-3)), T(-1));
  STF_EQUAL(div(bs::round, T(-4),T(3)), T(-1));
  STF_EQUAL(div(bs::round, T(5),T(3)), T(2));
  STF_EQUAL(div(bs::round, T(-5),T(-3)), T(2));
  STF_EQUAL(div(bs::round, T(5),T(-3)), T(-2));
  STF_EQUAL(div(bs::round, T(-5),T(3)), T(-2));

  STF_EQUAL(div(bs::round, T(5),T(4)), T(1));
  STF_EQUAL(div(bs::round, T(-5),T(-4)), T(1));
  STF_EQUAL(div(bs::round, T(5),T(-4)), T(-1));
  STF_EQUAL(div(bs::round, T(-5),T(4)), T(-1));
  STF_EQUAL(div(bs::round, T(6),T(4)), T(2));
  STF_EQUAL(div(bs::round, T(-6),T(-4)), T(2));
  STF_EQUAL(div(bs::round, T(6),T(-4)), T(-2));
  STF_EQUAL(div(bs::round, T(-6),T(4)), T(-2));
  STF_EQUAL(div(bs::round, T(8),T(4)), T(2));
  STF_EQUAL(div(bs::round, T(-8),T(-4)), T(2));
  STF_EQUAL(div(bs::round, T(8),T(-4)), T(-2));
  STF_EQUAL(div(bs::round, T(-8),T(4)), T(-2));
  STF_EQUAL(div(bs::round, T(9),T(4)), T(2));
  STF_EQUAL(div(bs::round, T(-9),T(-4)), T(2));
  STF_EQUAL(div(bs::round, T(9),T(-4)), T(-2));
  STF_EQUAL(div(bs::round, T(-9),T(4)), T(-2));
  STF_EQUAL(div(bs::round, T(10),T(4)), T(3));
  STF_EQUAL(div(bs::round, T(-10),T(-4)), T(3));
  STF_EQUAL(div(bs::round, T(10),T(-4)), T(-3));
  STF_EQUAL(div(bs::round, T(-10),T(4)), T(-3));

  STF_EQUAL(div(bs::round, bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(div(bs::round, bs::One<T>(), bs::One<T>()), bs::One<r_t>());
} // end of test for signed_int_
