//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_allbits_else_zero.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/allbits.hpp>

STF_CASE_TPL (" if_allbits_else_zero real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_allbits_else_zero;
  using r_t = decltype(if_allbits_else_zero(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(if_allbits_else_zero(bs::Inf<T>()), bs::Allbits<r_t>());
  STF_IEEE_EQUAL(if_allbits_else_zero(bs::Minf<T>()), bs::Allbits<r_t>());
  STF_IEEE_EQUAL(if_allbits_else_zero(bs::Nan<T>()), bs::Allbits<r_t>());
#endif
  STF_EQUAL(if_allbits_else_zero(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" if_allbits_else_zero integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_allbits_else_zero;
  using r_t = decltype(if_allbits_else_zero(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
  STF_EQUAL(if_allbits_else_zero(bs::One<T>()), bs::Allbits<r_t>());
  STF_EQUAL(if_allbits_else_zero(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_
