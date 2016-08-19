//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/significants.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>


STF_CASE_TPL (" significants",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::significants;
  using iT =  bd::as_integer_t<T>;
  using r_t = decltype(significants(T(), iT()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(significants(bs::Inf<T>(), 1), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(significants(bs::Minf<T>(), 1), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(significants(bs::Nan<T>(), 1), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(significants(T(0), 1), T(0), 0.5);
  STF_ULP_EQUAL(significants(T(25.34), 1), T(30), 0.5);
  STF_ULP_EQUAL(significants(T(25.34), 2), T(25), 0.5);
  STF_ULP_EQUAL(significants(T(25.34), 3), T(25.3), 0.5);
  STF_ULP_EQUAL(significants(T(25.34), 4), T(25.34), 0.5);
  STF_ULP_EQUAL(significants(T(-25.34), 1), T(-30), 0.5);
  STF_ULP_EQUAL(significants(T(-25.34), 2), T(-25), 0.5);
  STF_ULP_EQUAL(significants(T(-25.34), 3), T(-25.3), 0.5);
  STF_ULP_EQUAL(significants(T(-25.34), 4), T(-25.34), 0.5);
}

