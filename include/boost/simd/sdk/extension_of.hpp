//==================================================================================================
/*!
  @file

  Defines the extension_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_EXTENSION_OF_HPP_INCLUDED
#define BOOST_SIMD_SDK_EXTENSION_OF_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/arch/spec.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup  group-api
    @brief    Type to Extension mapping

    For a given @c Type, returns the hierarchy of the current hardware supporting
    such a type as wide register storage.

    @tparam Type Type
  **/
  template<typename Type>
  struct extension_of : ext::extension_of<Type>
  {};

  /// @brief Eager short-cut to extension_of
  template<typename Type>
  using extension_of_t = typename ext::extension_of<Type>::type;
} }

#endif
