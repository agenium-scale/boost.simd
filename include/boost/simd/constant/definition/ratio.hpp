//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_RATIO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_RATIO_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <cstdint>

namespace boost { namespace simd
{
  template<typename Type, std::uintmax_t Num, std::uintmax_t Denum>
  BOOST_FORCEINLINE   auto Ratio() BOOST_NOEXCEPT
                  ->  decltype(detail::constant(detail::ratio<Type,Num,Denum>{}))
  {
    return detail::constant( detail::ratio<Type,Num,Denum>{} );
  }

  template<typename Type, std::uintmax_t Num>
  BOOST_FORCEINLINE   auto Ratio() BOOST_NOEXCEPT
                  ->  decltype(detail::constant(detail::ratio<Type,Num,1>{}))
  {
    return detail::constant( detail::ratio<Type,Num,1>{} );
  }
} }

#endif
