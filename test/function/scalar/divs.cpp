//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/divs.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" divs signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divs;

  // return type conformity test
  STF_EXPR_IS(divs(T(), T()), T);

  // specific values tests
  STF_EQUAL(divs(bs::Mone<T>(), bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(divs(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(divs(bs::Valmax<T>(),bs::Mone<T>()), bs::Valmin<T>()+bs::One<T>());
  STF_EQUAL(divs(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(divs(bs::Valmin<T>(),bs::Mone<T>()), bs::Valmax<T>());
  STF_EQUAL(divs(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(divs(bs::Mone<T>(), bs::Zero<T>()), bs::Valmin<T>());
  STF_EQUAL(divs(bs::Mtwo<T>(), bs::Zero<T>()), bs::Valmin<T>());
  STF_EQUAL(divs(bs::Valmin<T>(), bs::Zero<T>()), bs::Valmin<T>());
  STF_EQUAL(divs(bs::One<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(divs(bs::Two<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(divs(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>());
} // end of test for signed_int_


STF_CASE_TPL (" divs unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divs;

  // return type conformity test
  STF_EXPR_IS(divs(T(), T()), T);

  // specific values tests
  STF_EQUAL(divs(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(divs(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(divs(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(divs(bs::One<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(divs(bs::Two<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(divs(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>());
} // end of test for unsigned_int_
