//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/cosh.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>


STF_CASE_TPL (" cosh",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cosh;
  using r_t = decltype(cosh(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cosh(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(cosh(bs::Minf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(cosh(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(cosh(bs::Zero<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(cosh(bs::One<T>()), T(1.54308063481524377847790562076), 0.5);
  STF_ULP_EQUAL(cosh(bs::Mone<T>()), T(1.54308063481524377847790562076), 0.5);
}
