//==================================================================================================
/*!
  @file

  Defines test macros for test on exceptions and assertions trigger

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_TESTS_EXCEPTIONS_HPP_INCLUDED
#define NSTEST_UNIT_TESTS_EXCEPTIONS_HPP_INCLUDED

#include <nstest/common/warning.hpp>
#include <nstest/unit/tests/basic.hpp>
#include <nstest/unit/detail/assertion_failure.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>

/*!
  @ingroup group-unit
  Test if an expression @c X throws an exception of type @c T.

  @par Usage:

  @snippet test/unit/exceptions.cpp throw

  where @c foo is defined as :

  @snippet test/unit/exceptions.cpp throwing_foo

  @param X Expression to test
  @param T Exception type expected to be thrown
**/
#define NSTEST_THROW( X, T )                                                                        \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try                                 { NSTEST_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                 \
  catch( BOOST_PP_REMOVE_PARENS(T)& ) { caught = true; }                                            \
                                                                                                    \
  if(caught)                                                                                        \
    NSTEST_PASS (   ::nstest::white_(NSTEST_STRING(X))                                              \
                <<  " throws "                                                                      \
                <<  ::nstest::white_(NSTEST_STRING(T))                                              \
                );                                                                                  \
  else                                                                                              \
    NSTEST_FAIL(   ::nstest::white_(NSTEST_STRING(X))                                               \
                <<  " does not throw "                                                              \
                <<  ::nstest::white_(NSTEST_STRING(T))                                              \
                );                                                                                  \
} while( ::nstest::is_false() )                                                                     \
/**/

/*!
  @ingroup group-unit
  Test if an expression @c X does not throw any exception.

  @par Usage:

  @snippet test/unit/exceptions.cpp no_throw

  where @c foo is defined as :

  @snippet test/unit/exceptions.cpp throwing_foo

  @param X Expression to test
**/
#define NSTEST_NO_THROW( X )                                                                        \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try          { NSTEST_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                                        \
  catch( ... ) { caught = true; }                                                                   \
                                                                                                    \
  if(caught)                                                                                        \
    NSTEST_FAIL( ::nstest::white_(NSTEST_STRING(X)) << " throws while not expected to" );           \
  else                                                                                              \
    NSTEST_PASS( ::nstest::white_(NSTEST_STRING(X)) << " doesn't throw" );                          \
} while( ::nstest::is_false() )                                                                     \
/**/

/*!
  @ingroup group-unit
  Test if an expression @c X does trigger an assertion failure defined using @c BOOST_ASSERT or
  @c BOOST_ASSERT_MSG macro.

  @par Usage:

  @snippet test/unit/assert.cpp assert

  where @c foo is defined as :

  @snippet test/unit/assert.cpp assert_foo

  @param X Expression to test
**/
#define NSTEST_ASSERT(X)                                                                            \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try  { NSTEST_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                                                \
  catch( ::nstest::detail::assertion_failure& e)                                                    \
  {                                                                                                 \
    caught = true;                                                                                  \
    NSTEST_PASS( ::nstest::white_(NSTEST_STRING(X)) << " triggered: \n" << e << "\n" );             \
  }                                                                                                 \
                                                                                                    \
  if(!caught)                                                                                       \
    NSTEST_FAIL( ::nstest::white_(NSTEST_STRING(X)) << " didn't trigger any assertion." );          \
} while( ::nstest::is_false() )                                                                     \
/**/

/*!
  @ingroup group-unit
  Test if an expression @c X does not trigger any assertion failure defined using @c BOOST_ASSERT
  or @c BOOST_ASSERT_MSG macro.

  @par Usage:

  @snippet test/unit/assert.cpp no_assert

  where @c foo is defined as :

  @snippet test/unit/assert.cpp assert_foo

  @param X Expression to test
**/
#define NSTEST_NO_ASSERT(X)                                                                         \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try  { NSTEST_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                                                \
  catch( ::nstest::detail::assertion_failure& e)                                                    \
  {                                                                                                 \
    caught = true;                                                                                  \
    NSTEST_FAIL( ::nstest::white_(NSTEST_STRING(X)) << " triggered: \n" << e << "\n" );             \
  }                                                                                                 \
                                                                                                    \
  if(!caught)                                                                                       \
    NSTEST_PASS( ::nstest::white_(NSTEST_STRING(X)) << " didn't trigger any assertion." );          \
} while( ::nstest::is_false() )                                                                     \
/**/

#endif
