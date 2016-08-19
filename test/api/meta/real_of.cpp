//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/meta/real_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check real_of on numeric types", STF_ALL_TYPES )
{
  STF_TYPE_IS( real_of_t<T>, T );
}

STF_CASE_TPL( "Check real_of on already logical types", STF_NUMERIC_TYPES )
{
  STF_TYPE_IS( real_of_t<logical<T>>, logical<T> );
}
