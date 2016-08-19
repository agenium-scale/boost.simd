//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/nthroot.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/half.hpp>

STF_CASE_TPL (" nthroot",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::nthroot;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(nthroot(T(), iT()));

  // return type conformity test
 STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(nthroot(bs::Inf<T>(),iT(3)), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Inf<T>(),iT(4)), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Minf<T>(),iT(3)), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Minf<T>(),iT(4)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Nan<T>(),iT(3)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Nan<T>(),iT(4)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Mone<T>(),iT(4)), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(nthroot(bs::Mone<T>(),iT(0)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::One <T>(),iT(0)), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Half<T>(),iT(0)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Two <T>(),iT(0)), bs::Inf <r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Zero<T>(),iT(0)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Two <T>(),iT(0)), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Half<T>(),iT(0)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Mone<T>(),iT(3)), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::One<T>(),iT(3)), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::One<T>(),iT(4)), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Zero<T>(),iT(3)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(bs::Zero<T>(),iT(4)), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(nthroot(T(-8),iT(3)), r_t(-2), 0.5);
  STF_ULP_EQUAL(nthroot(T(256),iT(4)), r_t(4), 0.5);
  STF_ULP_EQUAL(nthroot(T(8),iT(3)), r_t(2), 0.5);
  STF_ULP_EQUAL(nthroot(T(0.5), iT(4)), r_t(0.84089641525371454303112547623321), 0.5);
}



