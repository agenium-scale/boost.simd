//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_ZERO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bolean

    Returns a mask of bits. All ones if the
    input element is non @ref Zero else all zeros.

    This is a convenient alias of @ref genmask
**/
  template<typename T> auto if_allbits_else_zero(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      Returns a mask of bits. All ones if the
      input element is non @ref Zero else all zeros.


      Function object tied to simd::if_allbits_else_zero

      @see simd::if_allbits_else_zero
    **/
    const boost::dispatch::functor<tag::if_allbits_else_zero_> if_allbits_else_zero = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_allbits_else_zero.hpp>
#include <boost/simd/arch/common/scalar/function/genmask.hpp>
#include <boost/simd/function/simd/if_allbits_else_zero.hpp>

#endif
