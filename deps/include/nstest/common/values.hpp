//==================================================================================================
/*!
  @file

  Defines the is_false and is_true functions

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_VALUES_HPP_INCLUDED
#define NSTEST_COMMON_VALUES_HPP_INCLUDED

namespace nstest
{
  /*!
    @ingroup group-common
    Return the constant @c false
  **/
  inline bool is_false()  { return false; }

  /*!
    @ingroup group-common
    Return the constant @c true
  **/
  inline bool is_true()   { return true; }
}

#endif
