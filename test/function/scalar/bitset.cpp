//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitset.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" bitset uit",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using iT =  boost::dispatch::as_integer_t<T, unsigned>;
  using bs::bitset;

  // return type conformity test
  STF_EXPR_IS( bitset(T(), iT()), T );

  // specific values tests
  STF_EQUAL(bitset(T(2),1), T(3));
  STF_EQUAL(bitset(T(3),2), T(3));
  STF_EQUAL(bitset(T(3),3), T(7));
} // end of test for unsigned_int_

STF_CASE_TPL (" bitset si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using iT =  boost::dispatch::as_integer_t<T, unsigned>;
  using bs::bitset;

  // return type conformity test
  STF_EXPR_IS( bitset(T(), iT()), T );


  // specific values tests
  STF_EQUAL(bitset(T(2),1),T(3));
  STF_EQUAL(bitset(T(2),2), T(2));
  STF_EQUAL(bitset(T(-1), 1), T(-1));
} // end of test for unsigned_int_
