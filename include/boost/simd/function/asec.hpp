//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing asec capabilities

    inverse secant.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asec(x);
    @endcode

    is similar to:

    @code
    T r =  acos(rec(x));
    @endcode

    @see asecd

  **/
  Value asec(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/asec.hpp>
#include <boost/simd/function/simd/asec.hpp>

#endif
