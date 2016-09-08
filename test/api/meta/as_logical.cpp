//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::dispatch;

STF_CASE_TPL( "Check as_logical on numeric types", STF_NUMERIC_TYPES )
{
  STF_TYPE_IS( as_logical_t<T>, logical<T> );
}

STF_CASE_TPL( "Check as_logical on pack types", STF_NUMERIC_TYPES )
{
  STF_TYPE_IS( as_logical_t<pack<T>>          , pack<logical<T>> );
  STF_TYPE_IS( as_logical_t<pack<logical<T>>> , pack<logical<T>> );
}

STF_CASE_TPL( "Check as_logical on already logical types", STF_NUMERIC_TYPES )
{
  STF_TYPE_IS( as_logical_t<logical<T>>, logical<T> );
}

STF_CASE( "Check as_logical on already bool" )
{
  STF_TYPE_IS( as_logical_t<bool>, bool );
}
