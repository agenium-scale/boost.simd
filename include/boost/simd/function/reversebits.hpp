//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REVERSEBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REVERSEBITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the bits of the entry in reverse order.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = reversebits(x);
    @endcode


    @return      a value of the same type as the input.


**/
  template<typename T> auto reversebits(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns the bits of the entry in reverse order.


      Function object tied to simd::reversebits

      @see simd::reversebits
    **/
    const boost::dispatch::functor<tag::reversebits_> reversebits = {};
  }
} }
#endif

#include <boost/simd/function/definition/reversebits.hpp>
#include <boost/simd/arch/common/scalar/function/reversebits.hpp>
#include <boost/simd/function/simd/reversebits.hpp>

#endif
