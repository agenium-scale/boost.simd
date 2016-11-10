//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/twobits.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

#include <scalar_test.hpp>



STF_CASE_TPL (" twobits real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

   using bs::twobits;
   using r_t = decltype(twobits(T()));
   using iT =  bd::as_integer_t<T>;
   STF_TYPE_IS(r_t, T);

  for(iT i=0; i < 128; i++)
  {
    STF_EQUAL(twobits(T(i)), i&iT(3));
  }
} // end of test for floating_
