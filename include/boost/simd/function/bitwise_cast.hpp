//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_CAST_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_CAST_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
/*!
      @ingroup group-bitwise

      Performs a bit-preserving cast of its parameters into an arbitrary
      type @c Target.


      @par Semantic

      For any value @c x of type @c T and for  type @c Target,
      of same bit size as T


      @code
      Target r = bitwise_cast<Target>(x);
      @endcode

      @pre
      @code
      sizeof(T) == sizeof(Target)
      @endcode

      @tparam Target Target type to cast toward
      @param  x Value to cast

      @return A value of type @c Target which is bit-equivalent to @c x.
    **/
  template<typename Target, typename T> auto bitwise_cast(T const& x);

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

        Performs a bit-preserving cast of its parameters into an arbitrary
        type @c Target.


      Function object tied to boost::simd::bitwise_cast

      @see boost::simd::bitwise_cast
    **/
    const boost::dispatch::functor<tag::bitwise_cast_> bitwise_cast = {};
  }
} }
#endif

#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/simd/arch/common/generic/function/bitwise_cast.hpp>

#endif
