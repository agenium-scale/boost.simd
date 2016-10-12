//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ctz.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/signmask.hpp>

STF_CASE_TPL (" ctz real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ctz;
  using r_t = decltype(ctz(T()));
  // return type conformity test
  STF_EXPR_IS(ctz(T()), bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ctz(bs::Inf<T>()), r_t(bs::Nbmantissabits<T>()));
  STF_EQUAL(ctz(bs::Minf<T>()), r_t(bs::Nbmantissabits<T>()));
#endif
  STF_EQUAL(ctz(bs::Zero<T>()), r_t(sizeof(T)*8));
  STF_EQUAL(ctz(bs::Signmask<T>()), r_t(sizeof(T)*8-1));
} // end of test for real_

STF_CASE_TPL (" ctz signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::ctz;
  using bs::Nbmantissabits;
  using bs::Signmask;

  using r_t = decltype(ctz(T()));

  for(std::size_t j=0; j< (sizeof(T)*CHAR_BIT-1); j++)
  {
  namespace bs = boost::simd;
    // Test 01111 ... 10000b
    T value = ~T(0) & ~((T(1)<<j)-1);
    STF_EQUAL(ctz( value ), r_t(j));
    STF_EQUAL(ctz( T(-value) ), r_t(j));
  }

  STF_EQUAL(ctz(Signmask<T>()) , r_t(sizeof(T)*CHAR_BIT-1) );
}

STF_CASE_TPL(" ctz unsigned_integer", STF_UNSIGNED_INTEGRAL_TYPES )
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ctz;
  using r_t = decltype(ctz(T()));

  // return type conformity test
  STF_EXPR_IS(ctz(T()), bd::as_integer_t<T>);

  // specific values tests
  for(std::size_t j=0; j< sizeof(T)*CHAR_BIT; j++)
  {
  namespace bs = boost::simd;
    // Test 1111 ... 10000b
    T value = ~T(0) & ~((T(1)<<j)-1);
    STF_EQUAL(ctz( value ), r_t(j));
  }
 }
