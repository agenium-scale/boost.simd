//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_nan_else.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" if_nan_else real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_nan_else;
  using bs::logical;
  using bs::Nan;

  // return type conformity test
  STF_EXPR_IS( if_nan_else(T(), T()), T );

  // specific values tests
  STF_EQUAL(if_nan_else(T(0), T(1)), T(1));
  STF_IEEE_EQUAL(if_nan_else(T(1), T(1)), Nan<T>());
  STF_IEEE_EQUAL(if_nan_else(bs::Inf<T>(), T(1)) , Nan<T>());
  STF_IEEE_EQUAL(if_nan_else(bs::Minf<T>(), T(1)), Nan<T>());
  STF_IEEE_EQUAL(if_nan_else(bs::Nan<T>(), T(1)) , Nan<T>());
  STF_EQUAL(if_nan_else(bs::Zero<T>(), T(1)), T(1));


} // end of test for floating_

STF_CASE_TPL (" if_allbits_elsesigned_ int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_nan_else;
  using bs::logical;
  using bs::Allbits;

  // return type conformity test
  STF_EXPR_IS( if_nan_else(T(), T()), T );

  // specific values tests
  STF_EQUAL(if_nan_else(T(0), T(1)), T(1));
  STF_EQUAL(if_nan_else(T(1), T(1)), Allbits<T>());
} // end of test for signed_int_
