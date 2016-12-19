//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATANH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATANH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-hyperbolic
    Function object implementing atanh capabilities

    Returns the hyperbolic tangent argument \f$\frac12\log\frac{1+x}{1-x}\f$

    @par Semantic:

    For every parameter of floating type @c T

    @code
    T r = atanh(x);
    @endcode

    @par Decorators

    - raw_  is faster but inaccurate near Zero


    @see log, Half, oneminus, inc

  **/
  Value atanh(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/atanh.hpp>
#include <boost/simd/function/simd/atanh.hpp>

#endif
