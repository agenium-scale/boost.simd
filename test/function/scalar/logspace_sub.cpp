//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/logspace_sub.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" logspace_sub",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logspace_sub;

  using r_t = decltype(logspace_sub(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(logspace_sub(bs::Inf<T>(),bs::Inf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(logspace_sub(bs::Minf<T>(),bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(logspace_sub(bs::Nan<T>(),bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(logspace_sub(bs::Mone<T>(),bs::Mone<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(logspace_sub(bs::One<T>(),bs::One<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(logspace_sub(bs::Two <T>(),bs::Two <T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(logspace_sub(bs::Zero<T>(),bs::Zero<T>()), bs::Minf<r_t>(), 0);
#endif
}

