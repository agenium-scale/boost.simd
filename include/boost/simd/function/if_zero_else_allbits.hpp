//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ALLBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ALLBITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns a mask of bits. All ones if the
    input element is @ref Zero else all zeros.

    This is a convenient alias of @ref genmaskc
**/
  template<typename T> auto if_zero_else_allbits(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns a mask of bits. All ones if the
      input element is @ref Zero else all zeros.


      Function object tied to simd::if_zero_else_allbits

      @see simd::if_zero_else_allbits
    **/
    const boost::dispatch::functor<tag::if_zero_else_allbits_> if_zero_else_allbits = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_zero_else_allbits.hpp>
#include <boost/simd/arch/common/scalar/function/genmaskc.hpp>
#include <boost/simd/function/simd/if_zero_else_allbits.hpp>

#endif
