//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/divround2even.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" divround2even real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::divround2even;
  using r_t = decltype(divround2even(T(), T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_IEEE_EQUAL(divround2even(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divround2even(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_EQUAL(divround2even(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_IEEE_EQUAL(divround2even(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(divround2even(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
} // end of test for floating_

STF_CASE_TPL (" divround2even unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::divround2even;
  using r_t = decltype(divround2even(T(), T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(divround2even(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(divround2even(T(5), T(2)), T(2));
  STF_EQUAL(divround2even(T(7), T(2)), T(4));
  STF_EQUAL(divround2even(T(9), T(3)), T(3));
  STF_EQUAL(divround2even(T(10), T(3)), T(3));
  STF_EQUAL(divround2even(T(11), T(3)), T(4));
  STF_EQUAL(divround2even(T(12), T(3)), T(4));
  STF_EQUAL(divround2even(T(18), T(6)), T(3));
  STF_EQUAL(divround2even(T(20), T(6)), T(3));
  STF_EQUAL(divround2even(T(22), T(6)), T(4));
  STF_EQUAL(divround2even(T(24), T(6)), T(4));
  STF_EQUAL(divround2even(bs::Valmax<T>(),bs::Two<T>()), bs::Valmax<T>()/bs::Two<T>()+bs::One<T>());

} // end of test for unsigned_int_

STF_CASE_TPL (" divround2even signed_int", STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divround2even;
  using r_t = decltype(divround2even(T(), T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(divround2even(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(divround2even(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(divround2even(T(5), T(2)), T(2));
  STF_EQUAL(divround2even(T(7), T(2)), T(4));
  STF_EQUAL(divround2even(T(-5), T(2)), T(-2));
  STF_EQUAL(divround2even(T(-7), T(2)), T(-4));
  STF_EQUAL(divround2even(T(-4),T(0)), bs::Valmin<r_t>());
  STF_EQUAL(divround2even(T(4),T(0)), bs::Valmax<r_t>());
  STF_EQUAL(divround2even(T(4),T(3)), T(1));
  STF_EQUAL(divround2even(T(-4),T(-3)), T(1));
  STF_EQUAL(divround2even(T(4),T(-3)), T(-1));
  STF_EQUAL(divround2even(T(-4),T(3)), T(-1));
  STF_EQUAL(divround2even(T(5),T(3)), T(2));
  STF_EQUAL(divround2even(T(-5),T(-3)), T(2));
  STF_EQUAL(divround2even(T(5),T(-3)), T(-2));
  STF_EQUAL(divround2even(T(-5),T(3)), T(-2));

  STF_EQUAL(divround2even(T(5),T(4)), T(1));
  STF_EQUAL(divround2even(T(-5),T(-4)), T(1));
  STF_EQUAL(divround2even(T(5),T(-4)), T(-1));
  STF_EQUAL(divround2even(T(-5),T(4)), T(-1));
  STF_EQUAL(divround2even(T(6),T(4)), T(2));
  STF_EQUAL(divround2even(T(-6),T(-4)), T(2));
  STF_EQUAL(divround2even(T(6),T(-4)), T(-2));
  STF_EQUAL(divround2even(T(-6),T(4)), T(-2));
  STF_EQUAL(divround2even(T(8),T(4)), T(2));
  STF_EQUAL(divround2even(T(-8),T(-4)), T(2));
  STF_EQUAL(divround2even(T(8),T(-4)), T(-2));
  STF_EQUAL(divround2even(T(-8),T(4)), T(-2));
  STF_EQUAL(divround2even(T(9),T(4)), T(2));
  STF_EQUAL(divround2even(T(-9),T(-4)), T(2));
  STF_EQUAL(divround2even(T(9),T(-4)), T(-2));
  STF_EQUAL(divround2even(T(-9),T(4)), T(-2));
  STF_EQUAL(divround2even(T(10),T(4)), T(2));
  STF_EQUAL(divround2even(T(-10),T(-4)), T(2));
  STF_EQUAL(divround2even(T(10),T(-4)), T(-2));
  STF_EQUAL(divround2even(T(-10),T(4)), T(-2));

} // end of test for signed_int_

