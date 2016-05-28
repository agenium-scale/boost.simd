//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/fmin.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>


STF_CASE_TPL (" fmin real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fmin;

  using r_t = decltype(fmin(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(fmin(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(fmin(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(fmin(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(fmin(bs::Nan<T>(),bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(fmin(bs::One<T>(),bs::Nan<T>()), bs::One<r_t>());
#endif
  STF_EQUAL(fmin(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(fmin(bs::One<T>(),  bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(fmin(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(fmin(bs::Mone<T>(), bs::One <T>()), bs::Mone<r_t>());
  STF_EQUAL(fmin(bs::One <T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(fmin(bs::One <T>(), bs::Two <T>()), bs::One<r_t>());
  STF_EQUAL(fmin(bs::Two <T>(), bs::One <T>()), bs::One<r_t>());
  STF_EQUAL(fmin(bs::Mtwo<T>(), bs::One <T>()), bs::Mtwo<r_t>());
  STF_EQUAL(fmin(bs::One <T>(), bs::Mtwo<T>()), bs::Mtwo<r_t>());
  STF_EQUAL(fmin(bs::Two <T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(fmin(bs::Mone<T>(), bs::Two <T>()), bs::Mone<r_t>());
}

STF_CASE_TPL (" fmin unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fmin;

  using r_t = decltype(fmin(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(fmin(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(fmin(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" fmin signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fmin;

  using r_t = decltype(fmin(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(fmin(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(fmin(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(fmin(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}
