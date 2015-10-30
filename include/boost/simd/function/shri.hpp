//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHRI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHRI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the first entry logically shifted right
    by value of the second entry. If the second entry is negative
    the result is not defined.

    This is a convenient alias of @ref shr
**/
  template<typename T, template N> auto shri(T const& x,  N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns the first entry logically shifted right
      by value of the second entry. If the second entry is negative
      the result is not defined.


      Function object tied to simd::shri

      @see simd::shri
    **/
    const boost::dispatch::functor<tag::shri_> shri = {};
  }
} }
#endif

#include <boost/simd/function/definition/shri.hpp>
#include <boost/simd/arch/common/scalar/function/shr.hpp>
#include <boost/simd/function/simd/shri.hpp>

#endif
