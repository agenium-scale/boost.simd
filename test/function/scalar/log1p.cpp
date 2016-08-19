//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/log1p.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/log_2.hpp>

STF_CASE_TPL (" log1p",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log1p;

  using r_t =  decltype(log1p(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(log1p(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log1p(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log1p(bs::Mone<T>()), bs::Minf<r_t>(), 0);
#endif
  STF_ULP_EQUAL(log1p(bs::Eps<T>()), bs::Eps<r_t>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::Eps<T>()), bs::Eps<r_t>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::One<T>()), bs::Log_2<r_t>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::Smallestposval<T>()), bs::Smallestposval<T>(), 0.5);
  STF_ULP_EQUAL(log1p(bs::Eps<T>()), bs::Eps<T>(), 0.5);
}
