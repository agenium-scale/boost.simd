//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/l_notor.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" l_notor real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::l_notor;
  using bs::logical;
  using r_t = decltype(l_notor(T(), T()));

  // return type conformity test
  STF_TYPE_IS( r_t, logical<T>);

  // specific values tests
  STF_EQUAL(l_notor(T(0), T(1)), r_t(true));
  STF_EQUAL(l_notor(T(1), T(0)), r_t(false));
  STF_EQUAL(l_notor(bs::Inf<T>(),  T(0)), r_t(false));
  STF_EQUAL(l_notor(bs::Minf<T>(), T(0)), r_t(false));
  STF_EQUAL(l_notor(bs::Nan<T>(),  T(0)), r_t(false));
  STF_EQUAL(l_notor(bs::Zero<T>(), T(1)), r_t(true));
  STF_EQUAL(l_notor(r_t(false), T(1)), r_t(true));
  STF_EQUAL(l_notor(r_t(true), T(1)), r_t(true));


} // end of test for floating_

STF_CASE_TPL (" l_notor signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::l_notor;
  using bs::logical;
  using r_t = decltype(l_notor(T(), T()));

  // return type conformity test
  STF_TYPE_IS( r_t, logical<T>);

  // specific values tests
  STF_EQUAL(l_notor(T(0), T(1)), r_t(true));
  STF_EQUAL(l_notor(T(1), T(0)), r_t(false));
  STF_EQUAL(l_notor(r_t(false), T(1)), r_t(true));
  STF_EQUAL(l_notor(r_t(true), T(1)), r_t(true));
} // end of test for signed_int_

STF_CASE_TPL (" l_notor mix",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::l_notor;
  using bs::logical;
  using iT =  bd::as_integer_t<T>;
  using r_t = decltype(l_notor(T(),iT()));

  // return type conformity test
  STF_TYPE_IS( r_t, logical<T>);

  // specific values tests
  STF_EQUAL(l_notor(T(0), iT(1)), r_t(true));
  STF_EQUAL(l_notor(T(1), iT(0)), r_t(false));
  STF_EQUAL(l_notor(bs::Inf<T>(),  iT(0)), r_t(false));
  STF_EQUAL(l_notor(bs::Minf<T>(), iT(0)), r_t(false));
  STF_EQUAL(l_notor(bs::Nan<T>(),  iT(0)), r_t(false));
  STF_EQUAL(l_notor(bs::Zero<T>(), iT(1)), r_t(true));
  STF_EQUAL(l_notor(r_t(false), iT(1)), r_t(true));
  STF_EQUAL(l_notor(r_t(true), iT(1)), r_t(true));


} // end of test for floating_
