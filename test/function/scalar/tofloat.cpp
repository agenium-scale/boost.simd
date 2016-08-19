//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/tofloat.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" tofloat real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tofloat;
  using r_t = decltype(tofloat(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(tofloat(bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(tofloat(bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(tofloat(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(tofloat(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(tofloat(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(tofloat(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" tofloat unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tofloat;
  using r_t = decltype(tofloat(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_floating_t<T>);

  // specific values tests
  STF_EQUAL(tofloat(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(tofloat(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" tofloat signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tofloat;
  using r_t = decltype(tofloat(T()));


  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_floating_t<T>);

  // specific values tests
  STF_EQUAL(tofloat(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(tofloat(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(tofloat(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_

