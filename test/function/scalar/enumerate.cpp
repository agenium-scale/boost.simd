//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/scalar/enumerate.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check enumerate behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::enumerate;

  STF_EQUAL(enumerate<T>()      ,  T(0) );
  STF_EQUAL(enumerate<T>(42)    ,  T(42));
  STF_EQUAL(enumerate<T>(69, 23),  T(69));
}
