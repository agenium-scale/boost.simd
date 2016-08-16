//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/make.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check make behavior with all types", STF_ALL_TYPES )
{
  namespace bs = boost::simd;
  using bs::make;

  STF_EQUAL(make<T>(42), T(42));
}
