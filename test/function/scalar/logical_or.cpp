//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/logical_or.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" logical_or integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_or;
  using r_t = decltype(logical_or(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(logical_or(bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(logical_or(bs::One<T>(),bs::Zero<T>()), r_t(true));
  STF_EQUAL(logical_or(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
} // end of test for integer_

STF_CASE_TPL (" logical_or real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_or;
  using r_t = decltype(logical_or(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(logical_or(bs::Inf<T>(), bs::Inf<T>()), r_t(true));
  STF_EQUAL(logical_or(bs::Minf<T>(), bs::Minf<T>()), r_t(true));
  STF_EQUAL(logical_or(bs::Nan<T>(), bs::Nan<T>()), r_t(true));
  STF_EQUAL(logical_or(bs::One<T>(),bs::Zero<T>()), r_t(true));
  STF_EQUAL(logical_or(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
} // end of test for floating_

STF_CASE ( "logical_or bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_or;
  using r_t = decltype(logical_or(bool(), bool()));

  // return type conformity test
 STF_TYPE_IS(r_t, bool);

  // specific values tests
  STF_EQUAL(logical_or(true, false), true);
  STF_EQUAL(logical_or(false, true), true);
  STF_EQUAL(logical_or(true, true), true);
  STF_EQUAL(logical_or(false, false), false);
}



STF_CASE_TPL ( "logical_or logical", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_or;
  using lT =  bs::logical<T>;
  using r_t = decltype(logical_or(lT(), lT()));

  // return type conformity test
  STF_TYPE_IS(r_t, lT);

  // specific values tests
  STF_EQUAL(logical_or(bs::True<lT>(), bs::False<lT>()), bs::True<lT>());
  STF_EQUAL(logical_or(bs::False<lT>(), bs::True<lT>()), bs::True<lT>());
  STF_EQUAL(logical_or(bs::True<lT>(), bs::True<lT>()), bs::True<lT>());
  STF_EQUAL(logical_or(bs::False<lT>(), bs::False<lT>()), bs::False<lT>());
}


