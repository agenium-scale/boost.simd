//==================================================================================================
/*!
  @file

  Defines the various wrapper around name demangling function

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_TYPE_ID_HPP_INCLUDED
#define NSTEST_COMMON_TYPE_ID_HPP_INCLUDED

#include <boost/core/demangle.hpp>
#include <type_traits>
#include <typeinfo>
#include <string>

namespace nstest
{
  /**
    @brief Portable type name demangling function

    For any given type @c T or any value @c x of type @c T, type_id returns
    a @c std::string containing the fully qualified name of type @c T in a
    human readable format including @c const and reference qualifiers.

    @return a @c std::string containing the type of @c T
  **/
  template<typename T> inline std::string type_id()
  {
    typedef std::is_const<typename std::remove_reference<T>::type>  const_t;
    typedef std::is_lvalue_reference<T>                             lref_t;
    typedef std::is_rvalue_reference<T>                             rref_t;

    std::string s = boost::core::demangle(typeid(T).name());
    s += const_t::value ? " const"  : "";
    s += lref_t::value   ? "&"      : "";
    s += rref_t::value   ? "&&"     : "";

    return s;
  }

  /// @overload
  template<typename T> inline std::string type_id( const T& )
  {
    return type_id<T>();
  }
}

#endif
