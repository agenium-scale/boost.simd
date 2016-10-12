//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/logical_andnot.hpp>
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

STF_CASE_TPL (" logical_andnot real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_andnot;
  using bs::logical;
  using r_t = decltype(logical_andnot(T(), T()));

  // return type conformity test
  STF_TYPE_IS( r_t, logical<T>);

  // specific values tests
  STF_EQUAL(logical_andnot(T(0), T(1)), r_t(false));
  STF_EQUAL(logical_andnot(T(1), T(0)), r_t(true));
  STF_EQUAL(logical_andnot(bs::Inf<T>(),  T(0)), r_t(true));
  STF_EQUAL(logical_andnot(bs::Minf<T>(), T(0)), r_t(true));
  STF_EQUAL(logical_andnot(bs::Nan<T>(),  T(0)), r_t(true));
  STF_EQUAL(logical_andnot(bs::Zero<T>(), T(1)), r_t(false));
  STF_EQUAL(logical_andnot(r_t(false), T(1)), r_t(false));
  STF_EQUAL(logical_andnot(r_t(true), T(1)), r_t(false));


} // end of test for floating_

STF_CASE_TPL (" logical_andnot signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::logical_andnot;

  using bs::logical;
  using r_t = decltype(logical_andnot(T(), T()));

  // return type conformity test
  STF_TYPE_IS( r_t, logical<T> );

  // specific values tests
  STF_EQUAL(logical_andnot(T(0), T(1)), r_t(false));
  STF_EQUAL(logical_andnot(T(1), T(0)), r_t(true));
  STF_EQUAL(logical_andnot(r_t(false), T(1)), r_t(false));
  STF_EQUAL(logical_andnot(r_t(true), T(1)), r_t(false));
} // end of test for signed_int_

STF_CASE_TPL (" logical_andnot mix",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_andnot;
  using bs::logical;
  using iT =  bd::as_integer_t<T>;
  using r_t = decltype(logical_andnot(T(), iT()));

  // return type conformity test
  STF_TYPE_IS( r_t, logical<T> );

  // specific values tests
  STF_EQUAL(logical_andnot(T(0), iT(1)), r_t(false));
  STF_EQUAL(logical_andnot(T(1), iT(0)), r_t(true));
  STF_EQUAL(logical_andnot(bs::Inf<T>(),  iT(0)), r_t(true));
  STF_EQUAL(logical_andnot(bs::Minf<T>(), iT(0)), r_t(true));
  STF_EQUAL(logical_andnot(bs::Nan<T>(),  iT(0)), r_t(true));
  STF_EQUAL(logical_andnot(bs::Zero<T>(), iT(1)), r_t(false));
  STF_EQUAL(logical_andnot(r_t(false), iT(1)), r_t(false));
  STF_EQUAL(logical_andnot(r_t(true), iT(1)), r_t(false));


} // end of test for floating_STF_CASE

STF_CASE_TPL ( "logical_andnot logical", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_andnot;
  using lT =  bs::logical<T>;
  using r_t = decltype(logical_andnot(lT(), lT()));

  // return type conformity test
  STF_TYPE_IS(r_t, lT);

  // specific values tests
  STF_EQUAL(logical_andnot(bs::True<lT>(), bs::False<lT>()), bs::True<lT>());
  STF_EQUAL(logical_andnot(bs::False<lT>(), bs::True<lT>()), bs::False<lT>());
  STF_EQUAL(logical_andnot(bs::True<lT>(), bs::True<lT>()), bs::False<lT>());
  STF_EQUAL(logical_andnot(bs::False<lT>(), bs::False<lT>()), bs::False<lT>());
}


