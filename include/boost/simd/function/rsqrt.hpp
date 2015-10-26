//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RSQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RSQRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Returns the inverse of the square root of the input.

    @par semantic:

    For any given value @c x of floating type @c T:

    @code
    T r = rsqrt(x);
    @endcode

    For signed type is similar to:

    @code
    T r = T(1)/sqrt(x)
    @endcode



    @return      a value of the type of the input.

**/
  template<typename T> auto rsqrt(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::rsqrt

      @see simd::rsqrt
    **/
    const boost::dispatch::functor<tag::rsqrt_> rsqrt = {};
  }
} }
#endif

#include <boost/simd/function/definition/rsqrt.hpp>
#include <boost/simd/arch/common/scalar/function/rsqrt.hpp>
#include <boost/simd/arch/common/generic/function/rsqrt.hpp>
//#include <boost/simd/arch/common/function/simd/rsqrt.hpp>

#endif
