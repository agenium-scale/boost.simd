//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/false.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check false behavior", STF_NUMERIC_TYPES )
{
  using boost::simd::as;
  using boost::simd::detail::false_;
  using boost::simd::logical;
  using boost::simd::False;

  STF_TYPE_IS(decltype(False<logical<T>>()), logical<T> );

  STF_EQUAL(  False<logical<T>>()          , false);
  STF_EQUAL(  false_( as(logical<T>{}) )   , false);
}
