//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/twopower.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" twopower ui",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::twopower;
  using r_t = decltype(twopower(T()));

  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(twopower(bs::Zero<T>()), bs::One<r_t>());

  for(unsigned int i=0; i < sizeof(T)*8 ; i++)
 {
   STF_EQUAL(twopower(T(i)), T(1) << i);
 }
} // end of test for unsigned_int_

STF_CASE_TPL (" twopowersi",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::twopower;
  using r_t = decltype(twopower(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(twopower(bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(twopower(bs::Mone<T>()), bs::Zero<r_t>());

  for(unsigned int i=0; i < sizeof(T)*8-1 ; i++)
  {
    STF_EQUAL(twopower(T(i)), T(1) << i);
  }

} // end of test for unsigned_int_

