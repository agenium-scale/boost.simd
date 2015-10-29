//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/divtrunc.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" divtrunc real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::divtrunc;
  using r_t = decltype(divtrunc(T(), T()));
  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(divtrunc(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divtrunc(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divtrunc(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(divtrunc(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(divtrunc(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(divtrunc(bs::Mone<T>(),bs::Zero<T>()), bs::Minf<r_t>());
  STF_EQUAL(divtrunc(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(divtrunc(bs::One<T>(),bs::Zero<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(divtrunc(bs::Zero<T>(),bs::Zero<T>()), bs::Nan<r_t>());
  STF_EQUAL(divtrunc(T(4),T(3)), T(1));
  STF_EQUAL(divtrunc(T(-4),T(3)), T(-1));
} // end of test for floating_

STF_CASE_TPL (" divtrunc unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divtrunc;
  using r_t = decltype(divtrunc(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(divtrunc(T(4),T(0)), bs::Valmax<r_t>());
  STF_EQUAL(divtrunc(T(4),T(3)), T(1));
  STF_EQUAL(divtrunc(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(divtrunc(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(divtrunc(bs::One<T>(), bs::Zero<T>()), bs::Valmax<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" divtrunc signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divtrunc;
  using r_t = decltype(divtrunc(T(), T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(divtrunc(T(-4),T(0)), bs::Valmin<r_t>());
  STF_EQUAL(divtrunc(T(4),T(0)), bs::Valmax<r_t>());
  STF_EQUAL(divtrunc(T(4),T(3)), T(1));
  STF_EQUAL(divtrunc(T(-4),T(-3)), T(1));
  STF_EQUAL(divtrunc(T(4),T(-3)), T(-1));
  STF_EQUAL(divtrunc(T(-4),T(3)), T(-1));
  STF_EQUAL(divtrunc(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(divtrunc(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(divtrunc(bs::Mone<T>(), bs::Zero<T>()), bs::Valmin<r_t>());
  STF_EQUAL(divtrunc(bs::One<T>(), bs::Zero<T>()), bs::Valmax<r_t>());
  STF_EQUAL(divtrunc(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
} // end of test for signed_int_


