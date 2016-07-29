//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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

    @ingroup group-operator
    Function object implementing unary_plus capabilities

    return the elementwise unary plus of the parameter

    Infix notation can be used with operator '+'

    @par Semantic:

    For every parameter of type T

    @code
    T r = unary_plus(x);
    @endcode

    is similar to:

    @code
    T r = x;
    @endcode

    @par Note:

    It's the identity operator. take care that the infix notation in scalar integral mode encurs
    a possible promotion of the type as C++ rules state.

    @see  plus, unary_minus

  **/
  Value unary_plus(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/unary_plus.hpp>
#include <boost/simd/function/simd/unary_plus.hpp>

#endif
