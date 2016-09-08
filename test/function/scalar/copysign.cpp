//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/copysign.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" copysign real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::copysign;
  using r_t = decltype(copysign(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(copysign(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(copysign(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(copysign(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(copysign(bs::Inf<T>(), bs::Minf<T>()), bs::Minf<r_t>());
  STF_EQUAL(copysign(bs::Minf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(copysign(bs::Nan<T>(), bs::Inf<T>()), bs::Nan<r_t>());
  STF_EQUAL(copysign(bs::One<T>(), bs::Nan<T>()), bs::Mone<r_t>());
#endif
  STF_EQUAL(copysign(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(copysign(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(copysign(bs::One<T>(), bs::Mzero<T>()), bs::Mone<r_t>());
  STF_EQUAL(copysign(bs::One<T>(), bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(copysign(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" copysign signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::copysign;
  using r_t = decltype(copysign(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(copysign(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(copysign(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(copysign(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(copysign(bs::Mone<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(copysign(bs::One<T>(), bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(copysign(bs::Mone<T>(), bs::Zero<T>()), bs::One<r_t>());
}

