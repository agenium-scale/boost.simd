//==================================================================================================
/*
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/cardinal_of.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check cardinal_of for scalar types", STF_ALL_TYPES )
{
  STF_EQUAL( cardinal_of<T>::value        , 1ULL );
  STF_EQUAL( cardinal_of<T&&>::value      , 1ULL );
  STF_EQUAL( cardinal_of<T&>::value       , 1ULL );
  STF_EQUAL( cardinal_of<T const>::value  , 1ULL );
  STF_EQUAL( cardinal_of<T const&>::value , 1ULL );

  STF_EQUAL( cardinal_of<volatile T>::value        , 1ULL );
  STF_EQUAL( cardinal_of<volatile T&&>::value      , 1ULL );
  STF_EQUAL( cardinal_of<volatile T&>::value       , 1ULL );
  STF_EQUAL( cardinal_of<volatile T const>::value  , 1ULL );
  STF_EQUAL( cardinal_of<volatile T const&>::value , 1ULL );

  STF_EQUAL( cardinal_of_t<T>::value        , 1ULL );
  STF_EQUAL( cardinal_of_t<T&&>::value      , 1ULL );
  STF_EQUAL( cardinal_of_t<T&>::value       , 1ULL );
  STF_EQUAL( cardinal_of_t<T const>::value  , 1ULL );
  STF_EQUAL( cardinal_of_t<T const&>::value , 1ULL );

  STF_EQUAL( cardinal_of_t<volatile T>::value        , 1ULL );
  STF_EQUAL( cardinal_of_t<volatile T&&>::value      , 1ULL );
  STF_EQUAL( cardinal_of_t<volatile T&>::value       , 1ULL );
  STF_EQUAL( cardinal_of_t<volatile T const>::value  , 1ULL );
  STF_EQUAL( cardinal_of_t<volatile T const&>::value , 1ULL );

  STF_EXPR_IS( cardinal(T{}), cardinal_of_t<T> );
  STF_EQUAL( cardinal(T{}), 1ULL );
}

