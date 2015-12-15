//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_REAL_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_REAL_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <cstdint>

namespace boost { namespace simd
{
  template<typename Type, detail::bits_t<double> Double, detail::bits_t<float> Single>
  BOOST_FORCEINLINE   auto Real() BOOST_NOEXCEPT
        ->  decltype( detail::constant(typename detail::constantify<Type,Double,Single>::type{}) )
  {
    return detail::constant( typename detail::constantify<Type,Double,Single>::type{} );
  }
} }

#endif
