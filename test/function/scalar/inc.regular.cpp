//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/inc.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" inc signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::inc;

  // return type conformity test
  STF_EXPR_IS(inc(T()), T);

  // specific values tests
  STF_EQUAL(inc(bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(inc(bs::One<T>()), bs::Two<T>());
  STF_EQUAL(inc(bs::Zero<T>()), bs::One<T>());
}

STF_CASE_TPL (" inc unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::inc;

  // return type conformity test
  STF_EXPR_IS(inc(T()), T);

  // specific values tests
  STF_EQUAL(inc(bs::One<T>()), bs::Two<T>());
  STF_EQUAL(inc(bs::Two<T>()), bs::Three<T>());
  STF_EQUAL(inc(bs::Zero<T>()), bs::One<T>());
  STF_EQUAL(inc(bs::Valmax<T>()), bs::Zero<T>());
}

STF_CASE_TPL(" inc floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::inc;

  STF_EXPR_IS(inc(T()), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(inc(bs::Inf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(inc(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(inc(bs::Minf<T>()), bs::Minf<T>());
#endif
  STF_EQUAL(inc(bs::One<T>()), bs::Two<T>());
  STF_EQUAL(inc(bs::Two<T>()), bs::Three<T>());
  STF_EQUAL(inc(bs::Zero<T>()), bs::One<T>());
  STF_EQUAL(inc(bs::Valmax<T>()), bs::Valmax<T>());
}
