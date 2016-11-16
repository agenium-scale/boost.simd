//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/quadrant.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

#include <scalar_test.hpp>



STF_CASE_TPL (" quadrant real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

   using bs::quadrant;
   using r_t = decltype(quadrant(T()));
   using iT =  bd::as_integer_t<T>;
   STF_TYPE_IS(r_t, T);

  for(iT i=0; i < 128; i++)
  {
    STF_EQUAL(quadrant(T(i)), i&iT(3));
  }
} // end of test for floating_
