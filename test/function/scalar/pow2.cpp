//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/pow2.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/four.hpp>


STF_CASE_TPL (" pow2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow2;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(pow2(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(pow2(bs::Inf<T>(),  2), bs::Inf<r_t>());
  STF_EQUAL(pow2(bs::Minf<T>(), 2), bs::Minf<r_t>());
  STF_IEEE_EQUAL(pow2(bs::Nan<T>(),  2), bs::Nan<r_t>());
  STF_EQUAL(pow2(bs::Inf<T>(),  T(2.5)), bs::Inf<r_t>());
  STF_EQUAL(pow2(bs::Minf<T>(), T(2.5)), bs::Minf<r_t>());
  STF_IEEE_EQUAL(pow2(bs::Nan<T>(),  T(2.5)), bs::Nan<r_t>());
  STF_EQUAL(pow2(bs::Mone<T>(), 2), -bs::Four<r_t>());
  STF_EQUAL(pow2(bs::One<T>(),  2), bs::Four<r_t>());
  STF_EQUAL(pow2(bs::Zero<T>(), 2), bs::Zero<r_t>());
  STF_EQUAL(pow2(bs::Mone<T>(), T(2.5)), -bs::Four<r_t>());
  STF_EQUAL(pow2(bs::One<T>(),  T(2.5)), bs::Four<r_t>());
  STF_EQUAL(pow2(bs::Zero<T>(), T(2.5)), bs::Zero<r_t>());
}
