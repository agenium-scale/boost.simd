//==================================================================================================
/*!
  @file

  Defines the native_cardinal meta-function

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_NATIVE_CARDINAL_HPP_INCLUDED
#define BOOST_SIMD_SDK_NATIVE_CARDINAL_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/arch/limits.hpp>
#include <type_traits>

namespace boost { namespace simd
{
  template<typename T> struct logical;

  /*!

  **/
  template< typename T
          , typename Familly = BOOST_SIMD_DEFAULT_SITE
          >
  struct  native_cardinal
        : std::integral_constant<std::size_t, limits<BOOST_SIMD_DEFAULT_SITE>::bytes / sizeof(T) >
  {};

  template<typename T> struct native_cardinal< logical<T> > : native_cardinal<T>  {};
} }

#endif
