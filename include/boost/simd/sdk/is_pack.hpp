//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_IS_PACK_HPP_INCLUDED
#define BOOST_SIMD_SDK_IS_PACK_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd
{
  namespace bd = boost::dispatch;

  /*!
    @ingroup  group-api
    @brief    Checks if type is a pack

    For a given type @c Type, checks if said type is a pack type

    @tparam Type      Type to check
  **/
  template <typename T>
  struct is_pack : brigand::bool_<false> {};

  template <typename T, std::size_t N, typename ABI>
  struct is_pack<pack<T, N, ABI>> : brigand::bool_<true> {};

  template <typename T>
  using is_pack_t = typename is_pack<T>::type;
} }

#endif
