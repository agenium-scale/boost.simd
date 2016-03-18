//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_DEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_DEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing if_dec capabilities

    Decrements a value by @ref One if a predicate is true.

    This is a convenient alias of @ref seldec
  **/
  const boost::dispatch::functor<tag::if_dec_> if_dec = {};
} }
#endif

#include <boost/simd/function/scalar/seldec.hpp>
#include <boost/simd/function/simd/if_dec.hpp>

#endif
