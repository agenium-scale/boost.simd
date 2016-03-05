//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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


    @return a value of the same type as the parameters

**/
  template<typename T> auto modulo(T const& x, T const & y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      return the elementwise modulo of the two parameters
      Infix notation can be used with operator '\%'
      Does not work for floating point entries.


      Function object tied to simd::modulo

      @see simd::modulo
    **/
    const boost::dispatch::functor<tag::modulo_> modulo = {};
  }
} }
#endif

#include <boost/simd/function/scalar/modulo.hpp>
#include <boost/simd/function/simd/modulo.hpp>

#endif
