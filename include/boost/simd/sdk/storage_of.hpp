//==================================================================================================
/*!
  @file

  Defines the storage_of meta-function

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_STORAGE_OF_HPP_INCLUDED
#define BOOST_SIMD_SDK_STORAGE_OF_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/sdk/is_power_of_2.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup  group-api
    @brief    Type to SIMD register mapping

    For a given @c Type and width @c N, returns the proper type able to hold a @c N elements of
    type @c Type with maximal efficiency.

    @tparam Type Type to store
    @tparam N    Number of elements to store
  **/
  template<typename Type, std::size_t N> struct storage_of
  {
    using type = typename detail::storage_of<Type, N>::type;
  };

  /// @brief Eager short-cut to storage_of
  template<typename Type, std::size_t N>
  using storage_of_t = typename storage_of<Type,N>::type;
} }

#endif
