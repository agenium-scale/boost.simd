//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/minnum.hpp>
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


STF_CASE_TPL (" minnum real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minnum;

  using r_t = decltype(minnum(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(minnum(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(minnum(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(minnum(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(minnum(bs::Nan<T>(),bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(minnum(bs::One<T>(),bs::Nan<T>()), bs::One<r_t>());
#endif
  STF_EQUAL(minnum(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(minnum(bs::One<T>(),  bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(minnum(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(minnum(bs::Mone<T>(), bs::One <T>()), bs::Mone<r_t>());
  STF_EQUAL(minnum(bs::One <T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(minnum(bs::One <T>(), bs::Two <T>()), bs::One<r_t>());
  STF_EQUAL(minnum(bs::Two <T>(), bs::One <T>()), bs::One<r_t>());
  STF_EQUAL(minnum(bs::Mtwo<T>(), bs::One <T>()), bs::Mtwo<r_t>());
  STF_EQUAL(minnum(bs::One <T>(), bs::Mtwo<T>()), bs::Mtwo<r_t>());
  STF_EQUAL(minnum(bs::Two <T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(minnum(bs::Mone<T>(), bs::Two <T>()), bs::Mone<r_t>());
}

STF_CASE_TPL (" minnum unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minnum;

  using r_t = decltype(minnum(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(minnum(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(minnum(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" minnum signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minnum;

  using r_t = decltype(minnum(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(minnum(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(minnum(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(minnum(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}
