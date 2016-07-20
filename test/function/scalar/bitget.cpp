//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitget.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" bitget uit",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::bitget;
  using iT =  boost::dispatch::as_integer_t<T, unsigned>;

  // return type conformity test
  STF_EXPR_IS( bitget(T(), iT()), iT );

  // specific values tests
  STF_EQUAL(bitget(T(3),1), bs::One<iT>());
  STF_EQUAL(bitget(T(3),2), bs::One<iT>());
  STF_EQUAL(bitget(T(3),3), bs::Zero<iT>());
} // end of test for unsigned_int_

STF_CASE_TPL (" bitget si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::bitget;
  using iT =  boost::dispatch::as_integer_t<T, unsigned>;

  // return type conformity test
  STF_EXPR_IS( bitget(T(), iT()), iT );

  // specific values tests
  STF_EQUAL(bitget(T(2),1), bs::Zero<iT>());
  STF_EQUAL(bitget(T(2),2), bs::One<iT>());
  STF_EQUAL(bitget(T(-1), sizeof(T)*CHAR_BIT), bs::One<iT>());
} // end of test for unsigned_int_
