//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/mask2logical.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/false.hpp>

STF_CASE_TPL (" mask2logical real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::mask2logical;

  using bs::logical;
  using lT = logical<T>;

  // return type conformity test
  STF_EXPR_IS( mask2logical(T()), lT );

  // specific values tests
  STF_EQUAL(mask2logical(T(0)), bs::False<lT>());
  STF_EQUAL(mask2logical(bs::Nan<T>()) , bs::True<lT>());
} // end of test for floating_

STF_CASE_TPL (" mask2logical signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::mask2logical;
  using bs::logical;
  using lT = logical<T>;

  // return type conformity test
  STF_EXPR_IS( mask2logical(T()), lT );

  // specific values tests
  STF_EQUAL(mask2logical(T(0)), bs::False<lT>());
  STF_EQUAL(mask2logical(T(-1)), bs::True<lT>());
} // end of test for signed_int_
