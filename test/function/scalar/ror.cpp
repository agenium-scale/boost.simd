//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ror.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/bitwise_cast.hpp>

STF_CASE_TPL (" rorinteger", STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ror;
  STF_EXPR_IS( ror(T(), T()), T);

  T w = sizeof(T)*CHAR_BIT;

  for(T i=0;i<w;++i)
  {
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
    STF_EQUAL(ror(T(1),i), T(T(1)<<((w-i) & (w-1))));
  }

/*
  STF_ASSERT(ror(T(1),T(-1)));
  STF_ASSERT(ror(T(1),T(w+1)));
*/
}

STF_CASE_TPL (" rorreal", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ror;
  using bs::bitwise_cast;
  using iT = bd::as_integer_t<T> ;

  STF_EXPR_IS( ror(T(), iT()), T);

  iT w = sizeof(T)*CHAR_BIT;

  for(iT i=0;i<w;++i)
    STF_EQUAL( ror(bitwise_cast<T>(iT(1)),i)
                  , bitwise_cast<T>(iT(1)<<((w-i) & (w-1)))
                  );
/*
  STF_ASSERT(ror(T(1),iT(-1)));
  STF_ASSERT(ror(T(1),iT(w+1)));
*/
}
