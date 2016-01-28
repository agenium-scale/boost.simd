//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RSHR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RSHR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the first entry shifted right or left
    by the absolute value of the second entry,
    according to its sign.

    @par semantic:
    For any given value @c x of type @c T, n  of type @c I:

    @code
    T r = rshr(x, n);
    @endcode

    @see  rshl, shr, shl

    @return      a value of the same type as the first input.


**/
  template<typename , template NT> auto rshr(T const& x,  N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns the first entry shifted right or left
      by the absolute value of the second entry,
      according to its sign.


      Function object tied to simd::rshr

      @see simd::rshr
    **/
    const boost::dispatch::functor<tag::rshr_> rshr = {};
  }
} }
#endif

#include <boost/simd/function/scalar/rshr.hpp>
#include <boost/simd/function/simd/rshr.hpp>

#endif
