//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/any.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

STF_CASE_TPL ( "any", STF_ALL_TYPES)
{
  namespace bs = boost::simd;
  using bs::any;

  STF_EQUAL( any(T(1)) , true  );
  STF_EQUAL( any(T(0)), false );
}

