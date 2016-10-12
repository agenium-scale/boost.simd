//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ulp.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/mindenormal.hpp>

STF_CASE_TPL (" ulp real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ulp;
  using r_t = decltype(ulp(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(ulp(bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(ulp(bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(ulp(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(ulp(bs::Mone<T>()), bs::Eps<r_t>()/2);
  STF_EQUAL(ulp(bs::One<T>()), bs::Eps<r_t>()/2);
  STF_EQUAL(ulp(bs::Zero<T>()), bs::Mindenormal<r_t>());
}

STF_CASE_TPL (" ulp unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ulp;
  using r_t = decltype(ulp(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(ulp(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(ulp(bs::Zero<T>()), bs::One<r_t>());
}

STF_CASE_TPL (" ulp signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ulp;
  using r_t = decltype(ulp(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(ulp(bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(ulp(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(ulp(bs::Zero<T>()), bs::One<r_t>());
}
