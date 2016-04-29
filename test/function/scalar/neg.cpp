//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/neg.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/saturated.hpp>

STF_CASE_TPL (" neg real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::neg;

  using r_t = decltype(neg(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(neg(bs::Inf<T>()), bs::Minf<r_t>());
  STF_EQUAL(neg(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(neg(bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(neg(bs::One<T>()), bs::Mone<r_t>());
  STF_EQUAL(neg(bs::Zero<T>()), bs::Mzero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" neg signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::neg;
  using r_t = decltype(neg(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(neg(bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(neg(bs::One<T>()), bs::Mone<r_t>());
  STF_EQUAL(neg(bs::Two<T>()), -bs::Two<r_t>());
  STF_EQUAL(neg(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_STF_CASE("neg TO DO")


STF_CASE_TPL( "Check saturated neg behavior ", STF_SIGNED_INTEGRAL_TYPES )
{
  namespace bs = boost::simd;
  using bs::neg;
  using r_t = decltype(bs::saturated_(neg)(T()));
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(bs::saturated_(neg)(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(bs::saturated_(neg)(bs::One<T>()),  bs::Mone<r_t>());
  STF_EQUAL(bs::saturated_(neg)(bs::Mone<T>()), bs::One<r_t>());
}
