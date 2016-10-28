//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/nearbyint.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>

STF_CASE_TPL ( "nearbyint real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nearbyint;
  using r_t = decltype(nearbyint(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_IEEE_EQUAL(nearbyint(T(1.4)), 1);
  STF_IEEE_EQUAL(nearbyint(T(1.5)), 2);
  STF_IEEE_EQUAL(nearbyint(T(1.6)), 2);
  STF_IEEE_EQUAL(nearbyint(T(2.5)), 2);
  STF_IEEE_EQUAL(nearbyint(bs::Half<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(nearbyint(bs::Inf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(nearbyint(bs::Mhalf<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(nearbyint(bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(nearbyint(bs::Mone<T>()), bs::Mone<r_t>());
  STF_IEEE_EQUAL(nearbyint(bs::Nan<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(nearbyint(bs::One<T>()), bs::One<r_t>());
  STF_IEEE_EQUAL(nearbyint(bs::Zero<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(nearbyint(bs::Nan<T>()), bs::Nan<r_t>());
  STF_EXPECT(bs::is_negative(nearbyint(bs::Mzero<T>())));
  STF_EXPECT(bs::is_positive(nearbyint(bs::Zero<T>())));
} // end of test for floating_

STF_CASE_TPL (" nearbyintunsigned_int__1_0",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nearbyint;
  using r_t = decltype(nearbyint(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(nearbyint(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(nearbyint(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" nearbyintsigned_ int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nearbyint;
  using r_t = decltype(nearbyint(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(nearbyint(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(nearbyint(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(nearbyint(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

