//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/round.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/detail/constant/maxflint.hpp>
#include <boost/simd/function/next.hpp>
#include <boost/simd/function/prev.hpp>

STF_CASE_TPL ( "round std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::round;
  using r_t = decltype(bs::std_(round)(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_IEEE_EQUAL(bs::std_(round)(T(-1.4)), -1);
  STF_IEEE_EQUAL(bs::std_(round)(T(-1.5)), -2);
  STF_IEEE_EQUAL(bs::std_(round)(T(-1.6)), -2);
  STF_IEEE_EQUAL(bs::std_(round)(T(-2.5)), -3);
   STF_IEEE_EQUAL(bs::std_(round)(T(1.4)), 1);
  STF_IEEE_EQUAL(bs::std_(round)(T(1.5)), 2);
  STF_IEEE_EQUAL(bs::std_(round)(T(1.6)), 2);
  STF_IEEE_EQUAL(bs::std_(round)(T(2.5)), 3);
  STF_IEEE_EQUAL(bs::std_(round)(bs::Half<T>()), bs::One<r_t>());
  STF_IEEE_EQUAL(bs::std_(round)(bs::Inf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(bs::std_(round)(bs::Mhalf<T>()), bs::Mone<r_t>());
  STF_IEEE_EQUAL(bs::std_(round)(bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(bs::std_(round)(bs::Mone<T>()), bs::Mone<r_t>());
  STF_IEEE_EQUAL(bs::std_(round)(bs::Nan<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(bs::std_(round)(bs::One<T>()), bs::One<r_t>());
  STF_IEEE_EQUAL(bs::std_(round)(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_
