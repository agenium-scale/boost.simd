//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/idivround.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" idivroundreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::idivround;

  using r_t = decltype(idivround(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(idivround(bs::Inf<T>(), bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(idivround(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>());
  STF_EQUAL(idivround(bs::Nan<T>(), bs::Nan<T>()), bs::Zero<r_t>());
#endif
 STF_EQUAL(idivround(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(idivround(bs::Mone<T>(),bs::Zero<T>()), bs::Minf<r_t>());
  STF_EQUAL(idivround(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(idivround(bs::One<T>(),bs::Zero<T>()), bs::Valmax<r_t>());
  STF_EQUAL(idivround(bs::One<T>(),bs::Mzero<T>()), bs::Valmin<r_t>());
  STF_EQUAL(idivround(bs::Zero<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(idivround(T(4),T(3)), r_t(1));
  STF_EQUAL(idivround(T(-4),T(-3)), r_t(1));
  STF_EQUAL(idivround(T(-4),T(3)), r_t(-1));
  STF_EQUAL(idivround(T(4),T(-3)), r_t(-1));
} // end of test for floating_

STF_CASE_TPL (" idivroundunsigned_int",  STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idivround;
  using r_t = decltype(idivround(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(idivround(T(4),T(3)), T(1));
  STF_EQUAL(idivround(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(idivround(bs::One<T>(), bs::Zero<T>()), bs::Valmax<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" idivroundsigned_int",  STF_SIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idivround;
  using r_t = decltype(idivround(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(idivround(T(4),T(3)), r_t(1));
  STF_EQUAL(idivround(T(-4),T(-3)), r_t(1));
  STF_EQUAL(idivround(T(-4),T(3)), r_t(-1));
  STF_EQUAL(idivround(T(4),T(-3)), r_t(-1));
  STF_EQUAL(idivround(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(idivround(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(idivround(bs::One<T>(), bs::Zero<T>()), bs::Valmax<r_t>());
  STF_EQUAL(idivround(bs::Mone<T>(), bs::Zero<T>()), bs::Valmin<r_t>());
} // end of test for signed_int_

