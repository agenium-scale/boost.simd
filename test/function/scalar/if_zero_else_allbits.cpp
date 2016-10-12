//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_zero_else_allbits.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/function/plus.hpp>

STF_CASE_TPL (" if_zero_else_allbits real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_zero_else_allbits;
  using r_t = decltype(if_zero_else_allbits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(if_zero_else_allbits(bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(if_zero_else_allbits(bs::Minf<T>()), bs::Zero<r_t>());
  STF_EQUAL(if_zero_else_allbits(bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_IEEE_EQUAL(if_zero_else_allbits(bs::Zero<T>()), bs::Allbits<r_t>());
} // end of test for floating_

STF_CASE_TPL (" if_zero_else_allbits integer",  (int16_t)(int32_t)(int64_t)(uint32_t)(uint64_t))//STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::if_zero_else_allbits;

  using r_t = decltype(if_zero_else_allbits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(if_zero_else_allbits(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(if_zero_else_allbits(bs::Valmax<T>()), bs::Zero<r_t>());
  STF_EQUAL(if_zero_else_allbits(bs::plus(bs::Valmin<T>(), bs::One<T>())), bs::Zero<r_t>());
  STF_EQUAL(if_zero_else_allbits(bs::Zero<T>()), bs::Allbits<r_t>());
} // end of test for integer_
