//==================================================================================================
/*!
  @file

  Defines the to_string utility function

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_TO_STRING_HPP_INCLUDED
#define NSTEST_COMMON_TO_STRING_HPP_INCLUDED

#include <nstest/common/detail/is_container.hpp>
#include <nstest/common/detail/is_streamable.hpp>
#include <boost/core/demangle.hpp>
#include <sstream>
#include <cstddef>
#include <string>
#include <iomanip>

namespace nstest
{
  inline std::string to_string( std::nullptr_t )        { return "nullptr";             }
  inline std::string to_string( bool v )                { return v ? "true" : "false";  }
  inline std::string to_string( std::string const& v )  { return v;                     }
  inline std::string to_string( char const* v )         { return std::string(v);        }
  inline std::string to_string( char v )                { return std::string(1, v);     }

  /*!
    @ingroup group-common

    Converts a value to a descriptive string.
    Supported type include all fundamental types, string and container of said types.

    @param value Value to convert
    @return A textual representation of value
  **/
  template <typename T>
  inline detail::if_streamable<T,std::string> to_string( T const& value)
  {
    std::ostringstream os;
    os << std::setprecision(20) << value;
    return os.str();
  }

  template <typename T>
  inline detail::if_container<T,std::string> make_string( T const& value)
  {
    auto b = value.begin(), e = value.end();
    std::ostringstream os;

    os << "{ ";
    if(b!=e)      os << to_string(*b++);
    while(b != e) os << ", " << to_string(*b++);
    os << " }";

    return os.str();
  }

  template <typename T>
  inline detail::if_not_container<T,std::string> make_string( T const& value)
  {
    std::ostringstream os;

    os << "[ ";
    os << boost::core::demangle(typeid(T).name());
    os << " ] @" << (void*)(&value);

    return os.str();
  }

  template <typename T>
  inline detail::if_not_streamable<T,std::string> to_string( T const& value)
  {
    return make_string(value);
  }

  /*!
    @ingroup group-common

    Adds new line to a string used to display container types

    Displaying container may require large amount of console space so it's usually better
    to split lines around containers using new line. This function returns a potentially new-line
    enabled string for such a purpose.

    @param op Base string to augment
  **/
  template<typename LHS, typename RHS>
  inline std::string split_line(LHS const&, RHS const&, std::string const& op)
  {
    auto lb = detail::is_container<LHS>::type::value;
    auto rb = detail::is_container<RHS>::type::value;

    return (lb?"\n":"") + op + (rb?"\n":"");
  }
}

#endif
