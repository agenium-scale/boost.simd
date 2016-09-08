//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/extract.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>


STF_CASE_TPL( "Check extract behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::extract;
  STF_EXPR_IS(extract(T(1), 0), T);

  STF_EQUAL(extract(T(1), 0),  T(1));
}

