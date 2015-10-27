//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_UNARY_PLUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_UNARY_PLUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    return the elementwise unary plus of the parameter

    Infix notation can be used with operator '+'
    This is in fact identity.

    @par Semantic:

    For every parameter of type T0

    @code
    T0 r = unary_plus(a0);
    @endcode

    is similar to:

    @code
    T0 r = +a0;
    @endcode

    @par Alias:
    @c identity,  @c id

    @see  plus, unary_minus

    @return a value of the same type as the parameter

**/
  template<typename T> auto unary_plus(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::unary_plus

      @see simd::unary_plus
    **/
    const boost::dispatch::functor<tag::unary_plus_> unary_plus = {};
  }
} }
#endif

#include <boost/simd/function/definition/unary_plus.hpp>
#include <boost/simd/arch/common/scalar/function/unary_plus.hpp>
//#include <boost/simd/arch/common/function/simd/unary_plus.hpp>

#endif
