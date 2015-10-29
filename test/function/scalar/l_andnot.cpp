//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/l_andnot.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" l_andnot real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::l_andnot;
  using bs::logical;
  using r_t = decltype(l_andnot(T(), T()));

  // return type conformity test
  STF_TYPE_IS( r_t, logical<T>);

  // specific values tests
  STF_EQUAL(l_andnot(T(0), T(1)), r_t(false));
  STF_EQUAL(l_andnot(T(1), T(0)), r_t(true));
  STF_EQUAL(l_andnot(bs::Inf<T>(),  T(0)), r_t(true));
  STF_EQUAL(l_andnot(bs::Minf<T>(), T(0)), r_t(true));
  STF_EQUAL(l_andnot(bs::Nan<T>(),  T(0)), r_t(true));
  STF_EQUAL(l_andnot(bs::Zero<T>(), T(1)), r_t(false));
  STF_EQUAL(l_andnot(r_t(false), T(1)), r_t(false));
  STF_EQUAL(l_andnot(r_t(true), T(1)), r_t(false));


} // end of test for floating_

STF_CASE_TPL (" l_andnot signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::l_andnot;

  using bs::logical;
  using r_t = decltype(l_andnot(T(), T()));

  // return type conformity test
  STF_TYPE_IS( r_t, logical<T> );

  // specific values tests
  STF_EQUAL(l_andnot(T(0), T(1)), r_t(false));
  STF_EQUAL(l_andnot(T(1), T(0)), r_t(true));
  STF_EQUAL(l_andnot(r_t(false), T(1)), r_t(false));
  STF_EQUAL(l_andnot(r_t(true), T(1)), r_t(false));
} // end of test for signed_int_

STF_CASE_TPL (" l_andnot mix",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::l_andnot;
  using bs::logical;
  using iT =  bd::as_integer_t<T>;
  using r_t = decltype(l_andnot(T(), iT()));

  // return type conformity test
  STF_TYPE_IS( r_t, logical<T> );

  // specific values tests
  STF_EQUAL(l_andnot(T(0), iT(1)), r_t(false));
  STF_EQUAL(l_andnot(T(1), iT(0)), r_t(true));
  STF_EQUAL(l_andnot(bs::Inf<T>(),  iT(0)), r_t(true));
  STF_EQUAL(l_andnot(bs::Minf<T>(), iT(0)), r_t(true));
  STF_EQUAL(l_andnot(bs::Nan<T>(),  iT(0)), r_t(true));
  STF_EQUAL(l_andnot(bs::Zero<T>(), iT(1)), r_t(false));
  STF_EQUAL(l_andnot(r_t(false), iT(1)), r_t(false));
  STF_EQUAL(l_andnot(r_t(true), iT(1)), r_t(false));


} // end of test for floating_STF_CASE
