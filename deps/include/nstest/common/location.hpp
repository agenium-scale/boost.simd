//==================================================================================================
/*!
  @file

  Defines file location wrapper class

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_LOCATION_HPP_INCLUDED
#define NSTEST_COMMON_LOCATION_HPP_INCLUDED

#include <nstest/common/color.hpp>
#include <iostream>
#include <string>

namespace nstest
{
  /*!
    @ingroup group-common

    Simple POD wrapper for the __FILE__/__LINE__ macro pair.
  **/
  struct location
  {
    std::string file;
    std::size_t line;
  };

  /// Insert a location into a stream
  std::ostream& operator<<(std::ostream& os, location const& l)
  {
    return os << darkgray_(l.file) << ":" << darkgray_(l.line);
  }

  /// Constructs a location instance
  inline location at(std::string const& f, std::size_t l) { return {f,l}; }
}

#endif
