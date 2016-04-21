//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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

    @ingroup group-boolean
    Function object implementing if_zero_else_allbits capabilities

    Returns a mask of bits. All ones if the
    input element is @ref Zero else all zeros.

    This is a convenient alias of @ref genmaskc
  **/
  const boost::dispatch::functor<tag::if_zero_else_allbits_> if_zero_else_allbits = {};
} }
#endif

#include <boost/simd/function/scalar/genmaskc.hpp>
#include <boost/simd/function/simd/if_zero_else_allbits.hpp>

#endif
