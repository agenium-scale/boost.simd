//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sqrt1pm1.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/halfeps.hpp>

STF_CASE_TPL (" sqrt1pm1",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrt1pm1;

  using r_t = decltype(sqrt1pm1(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sqrt1pm1(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(sqrt1pm1(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(sqrt1pm1(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(sqrt1pm1(bs::Mone<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(sqrt1pm1(bs::One<T>()), bs::Sqrt_2<r_t>()-bs::One<r_t>(), 2);
  STF_ULP_EQUAL(sqrt1pm1(bs::Zero<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(sqrt1pm1(bs::Eps<T>()), bs::Halfeps<r_t>(), 0.5);
}
