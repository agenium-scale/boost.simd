//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/arg.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" arg real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::arg;
  using r_t = decltype(arg(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(arg(bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(arg(bs::Minf<T>()), bs::Pi<r_t>());
  STF_IEEE_EQUAL(bs::pedantic_(arg)(bs::Nan<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(arg(bs::Nan<T>()), bs::Pi<r_t>());
#endif
  STF_EQUAL(arg(bs::Mone<T>()), bs::Pi<r_t>());
  STF_EQUAL(arg(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(arg(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(arg(bs::Mzero<T>()), bs::Pi<r_t>());
} // end of test for floating_


