//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/meta/is_scalar.hpp>
#include <boost/simd/detail/dispatch/adapted/std/array.hpp>
#include <array>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check is_scalar for scalar types", STF_ALL_TYPES )
{
  STF_EXPECT( is_scalar<T>::value );
}

STF_CASE( "Check is_scalar for non-scalar types" )
{
  STF_EXPECT_NOT( (is_scalar<std::array<int,9>>::value) );
}

