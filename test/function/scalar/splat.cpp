//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/splat.hpp>
#include <stf.hpp>
#include <boost/simd/as.hpp>


STF_CASE_TPL( "Check splat behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::splat;
//  using r_t = decltype(splat(1, bs::as_<T>()));
//  STF_TYPE_IS(r_t, T);

  STF_EQUAL(splat<T>(1),  T(1));
}

