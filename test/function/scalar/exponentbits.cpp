//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/exponentbits.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" exponentbits float",  (float))
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::exponentbits;
  using r_t = decltype(exponentbits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  for(int i=1, k = 0; i < 10; i*= 2, ++k)
  {
  namespace bs = boost::simd;
    STF_EQUAL(1065353216+k*8388608, exponentbits(T(i)));
  }
}

STF_CASE_TPL (" exponentbits double",  (double))
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  using bs::exponentbits;
  using r_t = decltype(exponentbits(T()));

  // return type conformity test
  using r_t = decltype(exponentbits(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  for(int i=1, k = 0; i < 10; i*= 2, ++k)
   {
  namespace bs = boost::simd;
     STF_EQUAL(4607182418800017408ll+k*4503599627370496ll, exponentbits(T(i)));
   }
}


