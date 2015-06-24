//==================================================================================================
/*!
  @file

  Defines the various macro for defining test cases

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_CASE_HPP_INCLUDED
#define NSTEST_UNIT_CASE_HPP_INCLUDED

#include <nstest/common/string.hpp>
#include <nstest/common/unique_id.hpp>
#include <nstest/unit/detail/registration.hpp>
#include <nstest/unit/env.hpp>

#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

/*!
  @ingroup group-unit

  @brief Starts a block defining a test case.

  The following block will contains user defined preparation, actual tests,
  expectations and clean-up for said test case.

  A simple test case is then defined as :

  @snippet example/unit/case.cpp case

  Note that test cases performing no actual tests such as:

  @snippet example/unit/case.cpp fail_case

  will be reported as an automatic failure.

  Most of the time, however, compiling with all warning options will lead to compile-time
  notification of such cases.

  @param DESCRIPTION String literal describing the purpose of the test case
**/
#define NSTEST_CASE(DESCRIPTION)                                                                    \
void NTEST_FUNCTION( ::nstest::env& );                                                              \
namespace                                                                                           \
{                                                                                                   \
  ::nstest::detail::registrar NTEST_REGISTRATION{ ::nstest::test(DESCRIPTION, NTEST_FUNCTION) };    \
}                                                                                                   \
void NTEST_FUNCTION( ::nstest::env& $ )                                                             \
/**/

#define NTEST_RTYPE(z, n, t)                                                                        \
{                                                                                                   \
  using T = BOOST_PP_SEQ_ELEM(n,t);                                                                 \
  $.stream() << std::endl;                                                                          \
  $.stream() <<  "With T = [" << ::nstest::white_(NSTEST_STRING(BOOST_PP_SEQ_ELEM(n,t)))            \
                        << "]" << std::endl;                                                        \
  NTEST_FUNCTION<T>($);                                                                             \
}                                                                                                   \
/**/

/*!
  @ingroup group-unit

  @brief Starts a block defining a template test case.

  The following block will contains user defined preparation, actual tests,
  expectations and clean-up for said test case parametrized by a template type named @c T
  and instantiated for each type in the @c TYPES sequence.

  Such a test case is then defined as :

  @snippet example/unit/case.cpp case_tpl

  Note that, as for @ref NSTEST_CASE , empty tests are reported as automatic failures.

  @param DESCRIPTION  String literal describing the scope of the test case
  @param TYPES        Boost.Preprocessor sequence of types
**/
#define NSTEST_CASE_TPL(DESCRIPTION, TYPES)                                                         \
template<typename T> void NTEST_FUNCTION( nstest::env& );                                           \
namespace                                                                                           \
{                                                                                                   \
  nstest::detail::registrar                                                                         \
  NTEST_REGISTRATION{ nstest::test                                                                  \
                      ( DESCRIPTION                                                                 \
                      , [](::nstest::env& $) -> void                                                \
                        {                                                                           \
                          BOOST_PP_REPEAT(BOOST_PP_SEQ_SIZE(TYPES),NTEST_RTYPE,TYPES)               \
                        }                                                                           \
                      )                                                                             \
                    };                                                                              \
}                                                                                                   \
template<typename T> void NTEST_FUNCTION( nstest::env& $ )                                          \
/**/

#endif
