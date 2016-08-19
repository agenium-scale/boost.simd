//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/cospi.hpp>
#include <boost/simd/function/restricted.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>

STF_CASE_TPL (" cospi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cospi;

  using r_t = decltype(cospi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cospi(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cospi(-bs::Quarter<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::Half<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::Mhalf<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::One<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::Quarter<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::Zero<T>()), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" cospi restricted",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cospi;

  using r_t = decltype(cospi(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::restricted_(cospi)(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cospi)(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cospi)(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::restricted_(cospi)(-bs::Quarter<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cospi)(bs::Half<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cospi)(bs::Mhalf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cospi)(bs::One<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cospi)(bs::Quarter<T>()), bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cospi)(bs::Zero<T>()), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" cospi unsigned",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::cospi;
  using r_t = decltype(cospi(T()));
  using result_t = bd::as_floating_t<T>;

  // return type conformity test
  STF_TYPE_IS(r_t, result_t);

  // specific values tests
  STF_ULP_EQUAL(cospi(bs::One<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::Zero<T>()), bs::One<r_t>(), 0.5);
} // end of test for unsigned_int_

STF_CASE_TPL (" cospi signed",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::cospi;
  using r_t = decltype(cospi(T()));
  using result_t = bd::as_floating_t<T>;

  // return type conformity test
  STF_TYPE_IS(r_t, result_t);

  // specific values tests
  STF_ULP_EQUAL(cospi(bs::Mone<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::One<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cospi(bs::Zero<T>()), bs::One<r_t>(), 0.5);
} // end of test for signed_int_
