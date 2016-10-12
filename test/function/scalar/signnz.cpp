//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/signnz.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" signnz real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::signnz;
  using r_t = decltype(signnz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(signnz(bs::Inf<T>()), bs::One<r_t>());
  STF_EQUAL(signnz(bs::Minf<T>()), bs::Mone<r_t>());
  STF_IEEE_EQUAL(signnz(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(signnz(bs::Mzero<T>()), bs::Mone<r_t>());
  STF_EQUAL(signnz(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(signnz(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(signnz(bs::Zero<T>()), bs::One<r_t>());
}

STF_CASE_TPL (" signnz unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::signnz;
  using r_t = decltype(signnz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(signnz(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(signnz(bs::Zero<T>()), bs::One<r_t>());
}

STF_CASE_TPL (" signnz signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::signnz;
  using r_t = decltype(signnz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
  STF_EQUAL(signnz(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(signnz(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(signnz(bs::Zero<T>()), bs::One<r_t>());
}


