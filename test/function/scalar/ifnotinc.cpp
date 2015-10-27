//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/ifnotinc.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" ifnotinc signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnotinc;

  // return type conformity test
  STF_EXPR_IS( ifnotinc(T(), T()), T);

  // specific values tests
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::Zero<T>()), bs::One<T>());
  STF_EQUAL(ifnotinc(bs::One<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(ifnotinc(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(ifnotinc(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());
}

STF_CASE_TPL (" ifnotinc unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnotinc;

  // return type conformity test

  // specific values tests
  STF_EXPR_IS( ifnotinc(T(), T()), T);

  // specific values tests
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::Valmax<T>()), bs::Zero<T>());
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::Zero<T>()), bs::One<T>());
  STF_EQUAL(ifnotinc(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(ifnotinc(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());}

STF_CASE_TPL(" ifnotinc _floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnotinc;

  // return type conformity test
  STF_EXPR_IS( ifnotinc(T(), T()), T);

  // specific values tests
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(ifnotinc(bs::Zero<T>(), bs::Zero<T>()), bs::One<T>());
  STF_EQUAL(ifnotinc(bs::One<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(ifnotinc(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(ifnotinc(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());
}
