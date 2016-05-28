//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/iround2even.hpp>
#include <boost/simd/function/fast.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" iround2even real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::iround2even;
  using r_t = decltype(iround2even(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,  bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(iround2even(bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(iround2even(bs::Minf<T>()), bs::Minf<r_t>());
  STF_EQUAL(iround2even(bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(iround2even(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(iround2even(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iround2even(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(iround2even(T(1.4)), T(1));
  STF_EQUAL(iround2even(T(1.5)), T(2));
  STF_EQUAL(iround2even(T(1.6)), T(2));
  STF_EQUAL(iround2even(T(2.5)), T(2));
  STF_EQUAL(iround2even(T(-1.4)), T(-1));
  STF_EQUAL(iround2even(T(-1.5)), T(-2));
  STF_EQUAL(iround2even(T(-1.6)), T(-2));
  STF_EQUAL(iround2even(T(-2.5)), T(-2));
} // end of test for floating_

STF_CASE_TPL (" iround2even unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::iround2even;
  using r_t = decltype(iround2even(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,  bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(iround2even(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iround2even(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" iround2even signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::iround2even;
  using r_t = decltype(iround2even(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,  bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(iround2even(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(iround2even(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iround2even(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

STF_CASE_TPL (" iround2even real fast",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::iround2even;
  using bs::fast_;
  using r_t = decltype(iround2even(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,  bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::fast_(iround2even)(bs::Minf<T>()), bs::Minf<r_t>());
#endif
  STF_EQUAL(bs::fast_(iround2even)(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(bs::fast_(iround2even)(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(bs::fast_(iround2even)(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(bs::fast_(iround2even)(T(1.4)), T(1));
  STF_EQUAL(bs::fast_(iround2even)(T(1.5)), T(2));
  STF_EQUAL(bs::fast_(iround2even)(T(1.6)), T(2));
  STF_EQUAL(bs::fast_(iround2even)(T(2.5)), T(2));
  STF_EQUAL(bs::fast_(iround2even)(T(-1.4)), T(-1));
  STF_EQUAL(bs::fast_(iround2even)(T(-1.5)), T(-2));
  STF_EQUAL(bs::fast_(iround2even)(T(-1.6)), T(-2));
  STF_EQUAL(bs::fast_(iround2even)(T(-2.5)), T(-2));} // end of test for floating_
