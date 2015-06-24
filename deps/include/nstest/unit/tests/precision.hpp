//==================================================================================================
/*!
  @file

  Defines test macros for precision tests

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_TESTS_PRECISION_HPP_INCLUDED
#define NSTEST_UNIT_TESTS_PRECISION_HPP_INCLUDED

#include <nstest/unit/detail/ulp.hpp>
#include <nstest/unit/detail/decompose.hpp>
#include <nstest/unit/tests/basic.hpp>

/*!
  @ingroup group-unit

  @brief Check for equality within ULP distance

  Evaluates @c A and @c B and checks if their respective value(s) are withing @c X each ULPs of
  each other. This test is performed by calling the default @c nstest::ulpdist function or any
  ADL-accessible overload on each values from @c A and @c B.

  @par Example:

  @snippet test/unit/ulp.cpp ulp

  @param A First expression to compare
  @param B Second expression to compare
  @param X ULP distance threshold
**/
#define NSTEST_ULP_EQUAL(A,B,X)                                                                     \
do                                                                                                  \
{                                                                                                   \
  auto r = NSTEST_DECOMPOSE((A) == ::nstest::ulp(B,X));                                             \
  if( r )                                                                                           \
    NSTEST_PASS ( "Expecting: " << ::nstest::white_(NSTEST_STRING(A) " == " NSTEST_STRING(B))       \
                                << " within " << ::nstest::white_(X) << " ULPs."                    \
                );                                                                                  \
  else                                                                                              \
    NSTEST_FAIL ( "Expecting: " << ::nstest::white_(NSTEST_STRING(A) " == " NSTEST_STRING(B))       \
                                << " within " << ::nstest::white_(X) << " ULPs "                    \
                                << "but found:\n" << ::nstest::white_(r.rhs)                        \
                );                                                                                  \
} while( ::nstest::is_false() )                                                                     \
/**/

#endif
