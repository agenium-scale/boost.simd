//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/hi.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/function/bitwise_cast.hpp>

STF_CASE_TPL (" return_type",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::hi;

  STF_EXPR_IS( hi(T()), (bd::as_integer_t<T,unsigned>));
}





STF_CASE_TPL (" real_hi",  (float))
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::hi;

  using iT = bd::as_integer_t<T,unsigned>;

  T  val = bs::splat<T>(bs::bitwise_cast<T>(0x1234FFFF));
  T  res = bs::splat<T>(bs::bitwise_cast<T>(0x00001234));
  iT ref = bs::bitwise_cast<iT>(res);

  STF_EQUAL( hi(val), ref );
}

STF_CASE_TPL (" real_hi",  (double))
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::hi;

  using iT = bd::as_integer_t<T,unsigned>;

  T  val = bs::splat<T>(bs::bitwise_cast<T>(0x12345678FFFFFFFFLL));
  T  res = bs::splat<T>(bs::bitwise_cast<T>(0x0000000012345678LL));
  iT ref = bs::bitwise_cast<iT>(res);

  STF_EQUAL( hi(val), ref );
}

STF_CASE_TPL(" integer_hi", STF_INTEGRAL_TYPES )
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::hi;
  using bs::splat;

  using iT = bd::as_integer_t<T,unsigned>;

  T  val = splat<T>(~0);
  iT ref = splat<T>( (T(1)<< (sizeof(T)*(CHAR_BIT/2))) - 1);

  STF_EQUAL( hi(val), ref );
}
