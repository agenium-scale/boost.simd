//==================================================================================================
/*!
  @file

  Defines the NSTEST_STRING macro

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_STRING_HPP_INCLUDED
#define NSTEST_COMMON_STRING_HPP_INCLUDED

#define NSTEST_STRING__(...) #__VA_ARGS__
#define NSTEST_STRING_(text) NSTEST_STRING__ text

/*!
  @ingroup group-common

  Turn a variadic macro calls into a string containing properly placed commas.
**/
#define NSTEST_STRING(...) NSTEST_STRING_((__VA_ARGS__))

#endif
