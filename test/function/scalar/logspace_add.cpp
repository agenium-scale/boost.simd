//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/logspace_add.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/log_2.hpp>

STF_CASE_TPL (" logspace_add",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logspace_add;

  using r_t = decltype(logspace_add(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(logspace_add(bs::Inf<T>(),bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(logspace_add(bs::Inf<T>(),bs::Zero<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(logspace_add(bs::Minf<T>(),bs::Zero<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(logspace_add(bs::Inf<T>(),bs::Nan <T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(logspace_add(bs::Minf<T>(),bs::Minf<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(logspace_add(bs::Nan<T>(),bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(logspace_add(bs::Mone<T>(),bs::Mone<T>()), bs::Mone<r_t>()+bs::Log_2<r_t>(), 0);
  STF_ULP_EQUAL(logspace_add(bs::One<T>(),bs::One<T>()), bs::One<r_t>()+bs::Log_2<r_t>(), 0);
  STF_ULP_EQUAL(logspace_add(bs::Two <T>(), bs::Two <T>()), bs::Two <r_t>()+bs::Log_2<r_t>(), 0);
  STF_ULP_EQUAL(logspace_add(bs::Zero<T>(),bs::Zero<T>()), bs::Log_2<r_t>(), 0);
}

