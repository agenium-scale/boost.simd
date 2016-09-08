//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/rol.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/bitwise_cast.hpp>

STF_CASE_TPL (" rol integer", STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rol;
  STF_EXPR_IS( rol(T(), T()), T);

  T w = sizeof(T)*CHAR_BIT;

  for(T i=0;i<w;++i)
  {
    STF_EQUAL(rol(T(1),T(i)), T(T(1)<<i) );
  }

/*
  STF_ASSERT(rol(T(1),T(-1)));
  STF_ASSERT(rol(T(1),T(w+1)));
*/
}

STF_CASE_TPL (" rolreal", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rol;
  using bs::bitwise_cast;
  using iT = bd::as_integer_t<T> ;

  STF_EXPR_IS( rol(T(), iT()), T);

  iT w = sizeof(T)*CHAR_BIT;

  for(iT i=0;i<w;++i)
    STF_EQUAL( rol(bitwise_cast<T>(iT(1)),iT(i))
                  , bitwise_cast<T>(iT(1)<<i)
                  );
/*
  STF_ASSERT(rol(T(1),iT(-1)));
  STF_ASSERT(rol(T(1),iT(w+1)));
*/
}


