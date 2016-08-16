//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COSD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COSD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing cosd capabilities

    cosine of the input in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = cosd(x);
    @endcode

    is similar to:

    @code
    T r = cos(inrad(x));
    @endcode

    As other cosine functions cosd can be used with two parameters as
    @code
    T r = cos(x,  range_);
    @endcode

    see @ref cos for further details

    @see sincosd, cos, cospi

  **/
  Value cosd(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/cosd.hpp>
#include <boost/simd/function/simd/cosd.hpp>

#endif
