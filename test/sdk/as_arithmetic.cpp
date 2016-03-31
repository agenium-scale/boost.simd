//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/meta/as_arithmetic.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check as_arithmetic on numeric types", STF_NUMERIC_TYPES )
{
  STF_TYPE_IS( as_arithmetic_t<T>, T );
}

STF_CASE_TPL( "Check as_arithmetic on pack types", STF_NUMERIC_TYPES )
{
  STF_TYPE_IS( as_arithmetic_t<pack<T>>, pack<T> );
}

STF_CASE( "Check as_arithmetic on bool" )
{
  STF_TYPE_IS( as_arithmetic_t<bool>, bool );
}

STF_CASE_TPL( "Check as_arithmetic on logical types", STF_NUMERIC_TYPES )
{
  STF_TYPE_IS( as_arithmetic_t<logical<T>>, T );
}

STF_CASE_TPL( "Check as_arithmetic on pack of logical types", STF_NUMERIC_TYPES )
{
  STF_TYPE_IS( as_arithmetic_t<pack<logical<T>>>, pack<T> );
}
