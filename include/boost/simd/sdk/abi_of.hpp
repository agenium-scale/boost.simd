//==================================================================================================
/*!
  @file

  Defines the abi_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_ABI_OF_HPP_INCLUDED
#define BOOST_SIMD_SDK_ABI_OF_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/sdk/storage_of.hpp>
#include <boost/simd/sdk/extension_of.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup  group-api
    @brief    Type/Size to ABI mapping

    For a given @c Type and width @c N, returns a type uniquely identifying the SIMD ABI used to
    handle such type/size combination.

    @tparam Type Type to store
    @tparam N    Number of elements to store
  **/
  template<typename Type, std::size_t N> struct abi_of : extension_of< storage_of_t<Type,N> > {};

  /// @brief Eager short-cut to extension_of
  template<typename Type, std::size_t N> using abi_of_t = typename abi_of<Type,N>::type;
} }

#endif


