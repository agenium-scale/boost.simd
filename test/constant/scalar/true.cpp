//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/true.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check true behavior", STF_NUMERIC_TYPES )
{
  using boost::simd::as;
  using boost::simd::detail::true_;
  using boost::simd::logical;
  using boost::simd::True;

  STF_TYPE_IS(decltype(True<logical<T>>()), logical<T> );

  STF_EQUAL(  True<logical<T>>()          , true);
  STF_EQUAL(  true_( as(logical<T>{}) )   , true);
}
