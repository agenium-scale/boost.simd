//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/mantissa.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" mantissareal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::mantissa;

  using r_t = decltype(mantissa(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(mantissa(bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(mantissa(bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(mantissa(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(mantissa(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(mantissa(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(mantissa(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(mantissa(bs::Two <T>()), bs::One<r_t>());
  STF_EQUAL(mantissa(T(1.5)), T(1.5));
  STF_EQUAL(mantissa(T(2.5)), T(1.25));
}
