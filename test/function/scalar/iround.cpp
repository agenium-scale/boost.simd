//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/iround.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/next.hpp>
#include <boost/simd/function/prev.hpp>

STF_CASE_TPL (" iround real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::iround;
  using bs::next;
  using bs::prev;
  using r_t = decltype(iround(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(iround(bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(iround(bs::Minf<T>()), bs::Minf<r_t>());
  STF_EQUAL(iround(bs::Nan<T>()), bs::Zero<r_t>());

  STF_EQUAL(iround(bs::Mhalf<T>()), bs::Mone<r_t>());
  STF_EQUAL(iround(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(iround(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iround(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(iround(T(1.4)), r_t(1));
  STF_EQUAL(iround(T(1.5)), r_t(2));
  STF_EQUAL(iround(T(1.6)), r_t(2));
  STF_EQUAL(iround(T(2.5)), r_t(3));
  STF_EQUAL(iround(T(-1.4)), r_t(-1));
  STF_EQUAL(iround(T(-1.5)), r_t(-2));
  STF_EQUAL(iround(T(-1.6)), r_t(-2));
  STF_EQUAL(iround(T(-2.5)), r_t(-3));
  STF_EQUAL(iround(bs::Half<T>()), bs::One<r_t>());
  STF_EQUAL(iround(prev(prev(bs::Half<T>()))),  bs::Zero<r_t>());
  STF_EQUAL(iround(prev(bs::Half<T>())),  bs::Zero<r_t>());
  STF_EQUAL(iround(     bs::Half<T>()) ,  bs::One <r_t>());
  STF_EQUAL(iround(next(bs::Half<T>())),  bs::One <r_t>());

#endif
  STF_EQUAL(iround(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(iround(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iround(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" iround unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::iround;
  using r_t = decltype(iround(T()));

  // return type conformity test
   STF_TYPE_IS(r_t, bd::as_integer_t<T>);


  // specific values tests
  STF_EQUAL(iround(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iround(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" iround signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::iround;
  using r_t = decltype(iround(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(iround(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(iround(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(iround(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_
