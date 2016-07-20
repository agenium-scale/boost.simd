//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/meta/is_logical_mask.hpp>
#include <boost/simd/detail/dispatch/adapted/std/array.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <array>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check is_logical_mask for scalar and pack types", STF_NUMERIC_TYPES)
{
  STF_EXPECT( is_logical_mask<pack<T>>::value );
//  STF_EXPECT( is_logical_mask<pack<logical<T>>::value );
//  STF_EXPECT( is_logical_mask<bs::as_logical_t<pack<T>>>::value );
}
