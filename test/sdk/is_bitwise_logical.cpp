//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/sdk/is_bitwise_logical.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/logical.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check is_bitwise_logical", STF_NUMERIC_TYPES )
{
  STF_EXPECT( is_bitwise_logical_t<pack<T>>::value );
  STF_EXPECT( is_bitwise_logical_t<pack<logical<T>>>::value );
}
