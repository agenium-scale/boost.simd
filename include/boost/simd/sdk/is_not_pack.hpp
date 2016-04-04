//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_IS_NOT_PACK_HPP_INCLUDED
#define BOOST_SIMD_SDK_IS_NOT_PACK_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/sdk/is_pack.hpp>

namespace boost { namespace simd
{
  namespace bd = boost::dispatch;

  /*!
    @ingroup  group-api
    @brief    Checks if type is not a pack

    For a given type @c Type, checks if said type is not a pack type

    @tparam Type      Type to check
  **/
  template <typename T>
  struct is_not_pack : brigand::not_<is_pack<T>> {};

  template <typename T>
  using is_not_pack_t = typename is_not_pack<T>::type;
} }

#endif
