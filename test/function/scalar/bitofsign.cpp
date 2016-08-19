//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitofsign.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" bitofsign real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::bitofsign;
  using r_t = decltype(bitofsign(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bitofsign(bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitofsign(bs::Minf<T>()), bs::Mzero<r_t>());
  STF_IEEE_EQUAL(bitofsign(bs::Nan<T>()), bs::Mzero<r_t>());
#endif
  STF_EQUAL(bitofsign(bs::Mzero<T>()), bs::Mzero<r_t>());
  STF_EQUAL(bitofsign(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitofsign(bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" bitofsign unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::bitofsign;
  using r_t = decltype(bitofsign(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bitofsign(bs::One<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" bitofsign signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::bitofsign;
  using r_t = decltype(bitofsign(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(bitofsign(bs::Mone<T>()), T(1ull << (sizeof(T)*8-1)));
  STF_EQUAL(bitofsign(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(bitofsign(bs::Zero<T>()), bs::Zero<r_t>());
}


