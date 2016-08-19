//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check logical<T> conversion from/to bool", STF_NUMERIC_TYPES )
{
  logical<T> bool_true(true);
  STF_EQUAL( bool(bool_true)  , true );
  STF_EQUAL( bool_true.value(), true );

  logical<T> bool_false(false);
  STF_EQUAL( bool(bool_false)     , false );
  STF_EQUAL( bool_false.value()   , false );

  logical<T> val_true( T(42) );
  STF_EQUAL( bool(val_true)   , true );
  STF_EQUAL( val_true.value() , true );

  logical<T> val_false( T(0) );
  STF_EQUAL( bool(val_false)  , false );
  STF_EQUAL( val_false.value(), false );

  if(val_false) STF_ERROR("logical<T> dont behave well in if()");
  if((val_true  ? false  : true)) STF_ERROR("logical<T> dont behave well in ?:");
}

STF_CASE_TPL( "Check logical<T> complement operator", STF_NUMERIC_TYPES )
{
  logical<T> bool_true(true);
  STF_EQUAL( (!bool_true).value(), false );
  STF_EQUAL( (~bool_true).value(), false );

  logical<T> bool_false(false);
  STF_EQUAL( (!bool_false).value(), true  );
  STF_EQUAL( (~bool_false).value(), true  );

  logical<T> val_true( T(42) );
  STF_EQUAL( (!val_true).value(), false );
  STF_EQUAL( (~val_true).value(), false );

  logical<T> val_false( T(0) );
  STF_EQUAL( (!val_false).value(), true  );
  STF_EQUAL( (~val_false).value(), true  );
}

STF_CASE_TPL( "Check logical<T> comparison operators", STF_NUMERIC_TYPES )
{
  logical<T> bool_true(true);
  logical<T> bool_false(false);
  logical<T> val_true( T(42) );
  logical<T> val_false( T(0) );

  STF_EQUAL( bool_true  , val_true  );
  STF_EQUAL( bool_false , val_false );
  STF_NOT_EQUAL( bool_true  , val_false );
  STF_NOT_EQUAL( bool_false , val_true  );
}

STF_CASE_TPL( "Check logical<T> logical and operator", STF_NUMERIC_TYPES )
{
  logical<T> val_true( T(42) );
  logical<T> val_false( T(0) );

  STF_EQUAL( val_true  && val_true  , val_true  );
  STF_EQUAL( val_true  && val_false , val_false );
  STF_EQUAL( val_false && val_true  , val_false );
  STF_EQUAL( val_false && val_false , val_false );
}

STF_CASE_TPL( "Check logical<T> logical or operator", STF_NUMERIC_TYPES )
{
  logical<T> val_true( T(42) );
  logical<T> val_false( T(0) );

  STF_EQUAL( val_true  || val_true  , val_true  );
  STF_EQUAL( val_true  || val_false , val_true  );
  STF_EQUAL( val_false || val_true  , val_true  );
  STF_EQUAL( val_false || val_false , val_false );
}
