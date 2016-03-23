//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MODULO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MODULO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing modulo capabilities

    return the elementwise modulo of the two parameters
    Infix notation can be used with operator '\%'.

    Does not work for floating point entries.

    @par Semantic:

    For every parameters of type T:

    @code
    T r = modulo(x,y);
    @endcode

    is similar to:

    @code
    T r = x % y;
    @endcode

    @see  rem, remainder, mod,

  **/
  const boost::dispatch::functor<tag::modulo_> modulo = {};
} }
#endif

#include <boost/simd/function/scalar/modulo.hpp>
#include <boost/simd/function/simd/modulo.hpp>

#endif
