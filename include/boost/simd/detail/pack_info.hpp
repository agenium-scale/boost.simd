//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_PACK_INFO_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_PACK_INFO_HPP_INCLUDED

#include <boost/simd/cardinal_of.hpp>

namespace boost { namespace simd
{
  // Overload for cardinal_of
  template<typename T, std::size_t N, typename ABI>
  struct cardinal_of<pack<T,N,ABI>> : std::integral_constant<std::size_t,N>
  {};
} }

#endif
