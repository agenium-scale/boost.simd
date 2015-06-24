//==================================================================================================
/*!
  @file

  Defines macros generating line-based unique identifiers

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_UNIQUE_ID_HPP_INCLUDED
#define NSTEST_COMMON_UNIQUE_ID_HPP_INCLUDED

#define NSTEST_UNIQUE3( ID, LINE )  ID ## LINE
#define NSTEST_UNIQUE2( ID, LINE )  NSTEST_UNIQUE3( ID, LINE )

#if defined(DOXYGEN_ONLY)
/*!
  @brief Generate an unique ID for based on line

  Generates an unique symbol from a root identifier and `__LINE__`

  @param Identifier Base identifier used by the generator

**/
#define NSTEST_UNIQUE( Identifier )

/// @brief Generate an unique function ID
#define NTEST_FUNCTION

/// @brief Generate an unique test registration ID
#define NTEST_REGISTRATION
#else

#define NSTEST_UNIQUE( Identifier ) NSTEST_UNIQUE2( Identifier, __LINE__ )
#define NTEST_FUNCTION      NSTEST_UNIQUE(nstest_function)
#define NTEST_REGISTRATION  NSTEST_UNIQUE(nstest_registration)

#endif

#endif
