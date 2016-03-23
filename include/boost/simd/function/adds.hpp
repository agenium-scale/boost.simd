//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ADDS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ADDS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-arithmetic
    Function object implementing adds capabilities

    Computes the saturated sum of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = adds(x, y);
    @endcode

    The function coincide with plus for floating point parameters.
    For integers is similar to:

    @code
    T r = (x+y > Valmax) ? Valmax : (x+y < Valmin ? Valmin : x+y);
    @endcode

    @par Alias pluss

    @see  plus, oneplus, inc

  **/
  const boost::dispatch::functor<tag::adds_> adds = {};
} }
#endif

#include <boost/simd/function/scalar/adds.hpp>
#include <boost/simd/function/simd/adds.hpp>

#endif
