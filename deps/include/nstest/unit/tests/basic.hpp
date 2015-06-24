//==================================================================================================
/*!
  @file

  Defines basic test macros.

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_TESTS_BASIC_HPP_INCLUDED
#define NSTEST_UNIT_TESTS_BASIC_HPP_INCLUDED

#include <nstest/common/values.hpp>
#include <nstest/common/location.hpp>
#include <nstest/unit/detail/decompose.hpp>

/*!
  @ingroup group-unit
  Automatically successful test

  Register a test which always passes and streams a custom @c MESSAGE.

  @par Usage:

  @snippet test/unit/pass.cpp pass

  @param MESSAGE Values to stream as additional informations
**/
#define NSTEST_PASS( MESSAGE )                                                                      \
do                                                                                                  \
{                                                                                                   \
  $.as_success();                                                                                   \
  $.pass() << MESSAGE << " in: " << ::nstest::at(__FILE__,__LINE__) << std::endl;                   \
} while( ::nstest::is_false() )                                                                     \
/**/

/*!
  @ingroup group-unit
  Automatically failing test

  Register a test which always fails and streams a custom @c MESSAGE.

  @par Usage:

  @snippet test/unit/failure.cpp fail

  @param MESSAGE Values to stream as additional informations
**/
#define NSTEST_FAIL( MESSAGE )                                                                      \
do                                                                                                  \
{                                                                                                   \
  $.as_failure();                                                                                   \
  $.fail() << MESSAGE << " in: " << ::nstest::at(__FILE__,__LINE__) << std::endl;                   \
} while( ::nstest::is_false() )                                                                     \
/**/

/*!
  @ingroup group-unit
  Test if a boolean expression @c EXPR evaluates to @c true.

  @par Usage:

  @snippet test/unit/expect.cpp expect

  @param EXPR Boolean expression to test
**/
#define NSTEST_EXPECT( EXPR )                                                                       \
do                                                                                                  \
{                                                                                                   \
  auto r = NSTEST_DECOMPOSE(EXPR);                                                                  \
  if( r )                                                                                           \
    NSTEST_PASS( "Expecting: " << ::nstest::white_(NSTEST_STRING(EXPR)) );                          \
  else                                                                                              \
  {                                                                                                 \
    NSTEST_FAIL( "Expecting: " << ::nstest::white_(NSTEST_STRING(EXPR)) );                          \
    NSTEST_DUMP( r );                                                                               \
  }                                                                                                 \
} while( ::nstest::is_false() )                                                                     \
/**/

/*!
  @ingroup group-unit
  Test if a boolean expression @c EXPR evaluates to @c false.

  @par Usage:

  @snippet test/unit/expect.cpp expect_not

  @param EXPR Boolean expression to test
**/
#define NSTEST_EXPECT_NOT( EXPR )                                                                   \
do                                                                                                  \
{                                                                                                   \
  auto r = NSTEST_DECOMPOSE(EXPR);                                                                  \
  if( !r )                                                                                          \
    NSTEST_PASS( "Not expecting: " << ::nstest::white_(NSTEST_STRING(EXPR)) );                      \
  else                                                                                              \
  {                                                                                                 \
    NSTEST_FAIL( "Not expecting: " << ::nstest::white_(NSTEST_STRING(EXPR)) );                      \
    NSTEST_DUMP( r );                                                                               \
  }                                                                                                 \
} while( ::nstest::is_false() )                                                                     \
/**/

#endif
