//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/exp.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/exp_1.hpp>


STF_CASE_TPL ( "exp std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::exp;
  using r_t = decltype(exp(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::std_(exp)(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(exp)(bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(exp)(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(bs::std_(exp)(bs::Mone<T>()), bs::One<r_t>()/bs::Exp_1<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::std_(exp)(bs::One<T>()), bs::Exp_1<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::std_(exp)(bs::Zero<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(bs::std_(exp)(bs::Mzero<T>()), bs::One<r_t>(), 0);
}

