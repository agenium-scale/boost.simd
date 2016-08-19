//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/expx2.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/exp_1.hpp>

STF_CASE_TPL (" expx2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::expx2;

  using r_t =  decltype(expx2(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(expx2(bs::Inf<T>()), bs::Inf<r_t>(), 1.0);
  STF_ULP_EQUAL(expx2(bs::Minf<T>()), bs::Inf<r_t>(), 1.0);
  STF_ULP_EQUAL(expx2(bs::Nan<T>()), bs::Nan<r_t>(), 1.0);
#endif
  STF_ULP_EQUAL(expx2(bs::Mone<T>()), bs::Exp_1<r_t>(), 1.0);
  STF_ULP_EQUAL(expx2(bs::One<T>()), bs::Exp_1<r_t>(), 1.0);
  STF_ULP_EQUAL(expx2(bs::Zero<T>()), bs::One<r_t>(), 1.0);
  STF_ULP_EQUAL(expx2(T(6)),T(4.311231547115195e+15), 1.0);
}


