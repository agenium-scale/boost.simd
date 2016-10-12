//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/frac.hpp>
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

STF_CASE_TPL (" frac real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::frac;
  using r_t = decltype(frac(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(frac(bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(frac(bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(frac(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(frac(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(frac(T(1.5)),  bs::Half<r_t>());
  STF_EQUAL(frac(T(-1.5)),  bs::Mhalf<r_t>());
}

STF_CASE_TPL (" frac unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::frac;
  using r_t = decltype(frac(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(frac(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" frac signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::frac;
  using r_t = decltype(frac(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(frac(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::Zero<T>()), bs::Zero<r_t>());
}


