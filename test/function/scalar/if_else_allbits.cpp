//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_else_allbits.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/allbits.hpp>

STF_CASE_TPL (" if_else allbitsreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_else_allbits;
  using bs::logical;
  using bs::Allbits;

  // return type conformity test
  STF_EXPR_IS( if_else_allbits(T(), T()), T );

  // specific values tests
  STF_IEEE_EQUAL(if_else_allbits(T(0), T(1)), Allbits<T>());
  STF_EQUAL(if_else_allbits(T(1), T(1)), T(1));
  STF_EQUAL(if_else_allbits(bs::Inf<T>(),  T(1)), T(1));
  STF_EQUAL(if_else_allbits(bs::Minf<T>(), T(1)), T(1));
  STF_EQUAL(if_else_allbits(bs::Nan<T>(),  T(1)), T(1));
  STF_IEEE_EQUAL(if_else_allbits(bs::Zero<T>(), T(1)), Allbits<T>());


} // end of test for floating_

STF_CASE_TPL (" if_else_allbitssigned_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::if_else_allbits;

  using bs::logical;
  using bs::Allbits;

  // return type conformity test
  STF_EXPR_IS( if_else_allbits(T(), T()), T );

  // specific values tests
  STF_IEEE_EQUAL(if_else_allbits(T(0), T(1)), Allbits<T>());
  STF_EQUAL(if_else_allbits(T(1), T(1)),  T(1));
  STF_IEEE_EQUAL(if_else_allbits(bs::Zero<T>(), T(1)),  Allbits<T>());
} // end of test for signed_int_
