//==================================================================================================
/*!
  @file

  Defines test macros for test on types

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_TESTS_TYPES_HPP_INCLUDED
#define NSTEST_UNIT_TESTS_TYPES_HPP_INCLUDED

#include <type_traits>
#include <nstest/common/color.hpp>
#include <nstest/common/string.hpp>
#include <nstest/common/type_id.hpp>
#include <nstest/unit/tests/basic.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/mpl/apply.hpp>

/*!
  @ingroup group-unit
  @brief Check for type equality

  For a given types @c T and  @c Type, consider the test successful if and only if
  @c std::is_same<T,Type> evaluates to @true_.

  @par Usage:

  @snippet test/unit/types.cpp type_is

  @param T    First type to compare
  @param Type Second type to compare
**/
#define NSTEST_TYPE_IS(T, Type)                                                                     \
do                                                                                                  \
{                                                                                                   \
  volatile bool b = std::is_same<BOOST_PP_REMOVE_PARENS(Type), BOOST_PP_REMOVE_PARENS(T)>::value;   \
  if( b )                                                                                           \
    NSTEST_PASS (   "Expecting " << ::nstest::white_ << NSTEST_STRING(BOOST_PP_REMOVE_PARENS(T))    \
                <<  " == " << nstest::type_id<BOOST_PP_REMOVE_PARENS(Type)>() << ::nstest::default_ \
                );                                                                                  \
  else                                                                                              \
    NSTEST_FAIL (   "Expecting " << ::nstest::white_(NSTEST_STRING(BOOST_PP_REMOVE_PARENS(T)))      \
                <<  " == " << ::nstest::white_(nstest::type_id<BOOST_PP_REMOVE_PARENS(Type)>())     \
                <<  " found " << ::nstest::white_(nstest::type_id<BOOST_PP_REMOVE_PARENS(T)>())     \
                <<  " instead"                                                                      \
                );                                                                                  \
} while( ::nstest::is_false() )                                                                     \
/**/

/*!
  @ingroup group-unit
  @brief Check for type equality

  For a given expression @c Expression and a given type @c Type, consider the test successful if
  and only if @c std::is_same<decltype(Expression),Type> evaluates to @true_ .

  @par Usage:

  @snippet test/unit/types.cpp expr_is

  @param Expression Expression to test type
  @param Type       Second type to compare
**/
#define NSTEST_EXPR_IS(Expression, Type)                                                            \
NSTEST_TYPE_IS(decltype( BOOST_PP_REMOVE_PARENS(Expression)), Type)                                 \
/**/

/*!
  @ingroup group-unit
  @brief Check for type equality on meta-lambda application

  For a given expression @c Expression and any type @c Lambda and  @c Type, consider the test
  successful if and only if @c std::is_same<mpl::apply<Lambda,decltype(Expression)>::type,Type>
  evaluates to @true_ .

  @par Usage:

  @snippet test/unit/types.cpp type_expr

  @param Expression Expression to pass to the meta-lambda
  @param Lambda     Meta-lambda function following MPL protocol to apply
  @param Type       Expected result of the application of Lambda on the type of Expression
**/
#define NSTEST_EXPR_TYPE(Expression, Lambda, Type)                                                  \
do                                                                                                  \
{                                                                                                   \
  using other = boost::mpl::apply < BOOST_PP_REMOVE_PARENS(Lambda)                                  \
                                  , decltype(BOOST_PP_REMOVE_PARENS(Expression))                    \
                                  >::type;                                                          \
                                                                                                    \
  volatile bool b = std::is_same<BOOST_PP_REMOVE_PARENS(Type), other>::value;                       \
  if( b )                                                                                           \
    NSTEST_PASS (   "Expecting "                                                                    \
                << ::nstest::white_(NSTEST_STRING(BOOST_PP_REMOVE_PARENS(Lambda)))                  \
                << " applied on "                                                                   \
                << ::nstest::white_(nstest::type_id(BOOST_PP_REMOVE_PARENS(Expression)))            \
                <<  " to be "                                                                       \
                << ::nstest::white_(nstest::type_id<BOOST_PP_REMOVE_PARENS(Type)>())                \
                );                                                                                  \
  else                                                                                              \
    NSTEST_FAIL(   "Expecting "                                                                     \
                << ::nstest::white_(NSTEST_STRING(BOOST_PP_REMOVE_PARENS(Lambda)))                  \
                << " applied on "                                                                   \
                << ::nstest::white_(nstest::type_id(BOOST_PP_REMOVE_PARENS(Expression)))            \
                <<  " to be "                                                                       \
                << ::nstest::white_(nstest::type_id<BOOST_PP_REMOVE_PARENS(Type)>())                \
                << " but found " << ::nstest::white_(nstest::type_id<other>()) << " instead"        \
                );                                                                                  \
} while( ::nstest::is_false() )                                                                     \
/**/

#endif
