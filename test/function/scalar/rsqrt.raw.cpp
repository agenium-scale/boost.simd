//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/rsqrt.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/sqrt_2.hpp>

STF_CASE_TPL( "raw rsqrt", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rsqrt;
  using r_t = decltype(bs::raw_(rsqrt)(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_ULP_EQUAL(bs::raw_(rsqrt)(bs::Mone<T>()), bs::Nan<T>(), 0);
  STF_ULP_EQUAL(bs::raw_(rsqrt)(bs::Nan<T>()), bs::Nan<T>(), 0);
  STF_RELATIVE_EQUAL(bs::raw_(rsqrt)(bs::One<T>()), bs::One<T>(), 0.5);
  STF_RELATIVE_EQUAL(bs::raw_(rsqrt)(bs::Four<T>()), bs::Half<T>(), 0.5);
  STF_RELATIVE_EQUAL(bs::raw_(rsqrt)(bs::Half<T>()), bs::Sqrt_2<T>(), 0.5);
  STF_RELATIVE_EQUAL(bs::raw_(rsqrt)(T(0.01)), T(10), 0.5);
  STF_RELATIVE_EQUAL(bs::raw_(rsqrt)(T(0.0001)), T(100), 0.5);
}
