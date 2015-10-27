//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/divceil.hpp>
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
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" divceil real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::divceil;
  using r_t = decltype(divceil(T(), T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(divceil(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divceil(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divceil(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(divceil(T(4),T(0)), bs::Inf<r_t>());
  STF_EQUAL(divceil(T(4),T(3)), 2);
  STF_EQUAL(divceil(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(divceil(bs::Mone<T>(),bs::Zero<T>()), bs::Minf<r_t>());
  STF_EQUAL(divceil(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(divceil(bs::One<T>(),bs::Zero<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(divceil(bs::Zero<T>(),bs::Zero<T>()), bs::Nan<r_t>());
} // end of test for floating_

STF_CASE_TPL (" divceil unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divceil;
  using r_t = decltype(divceil(T(), T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(divceil(T(4),T(0)), bs::Valmax<r_t>());
  STF_EQUAL(divceil(T(4),T(3)), T(2));
  STF_EQUAL(divceil(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(divceil(bs::Valmax<T>(),  bs::Two<T>()), bs::Valmax<r_t>()/bs::Two<T>()+bs::One<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" divceil signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divceil;
  using r_t = decltype(divceil(T(), T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(divceil(T(-4),T(0)), bs::Valmin<r_t>());
  STF_EQUAL(divceil(T(4),T(0)), bs::Valmax<r_t>());
  STF_EQUAL(divceil(T(4),T(3)), T(2));
  STF_EQUAL(divceil(T(-4),T(-3)), T(2));
  STF_EQUAL(divceil(T(4),T(-3)), T(-1));
  STF_EQUAL(divceil(T(-4),T(3)), T(-1));
  STF_EQUAL(divceil(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(divceil(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
} // end of test for signed_int_


