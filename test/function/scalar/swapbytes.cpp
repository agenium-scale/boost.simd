//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/swapbytes.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/shift_left.hpp>


STF_CASE_TPL (" swapbytes uit",   STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::swapbytes;

  // return type conformity test
  STF_EXPR_IS( swapbytes(T()), T );

  // specific values tests
  T a =  T(0xFF);
  for(std::size_t i=0; i < sizeof(T) ; i++)
  {
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
    T za =  bs::shift_left(a, 8*i);
    STF_EQUAL(swapbytes(za), T(bs::shift_left(a,(sizeof(T)-i-1)*8)));
  }
}


