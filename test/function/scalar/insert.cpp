//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/insert.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>


STF_CASE_TPL( "Check insert behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::insert;
  T a = T(2);
  STF_EXPR_IS(insert(a, 0, T(1)), void);
  insert(a, 0, T(1));
  STF_EQUAL(a,  T(1));
  a = T(2);
  insert(a, 1, T(1));
  STF_EQUAL(a,  T(1));
  a = T(2);
 insert<0>(a, T(1));
  STF_EQUAL(a,  T(1));
  a = T(2);
  insert<1>(a, T(1));
  STF_EQUAL(a,  T(1));

}

