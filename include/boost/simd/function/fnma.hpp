//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FNMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FNMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing fnma capabilities

    Computes the fused negated add-multiply of three values.

    @par semantic:
    For any given value @c x,  @c y,  @c z of type @c T:

    @code
    T r = fnma(x, y, z);
    @endcode

    The code is similar to:

    @code
    T r = -(x+y*z);
    @endcode

    @par Note:

    fnma can be called with the same modalities as @ref fma
    and can use the decorator conformant_ to ensure the correct
    one rounding, no intermediate overflow  behaviour

    @see fma, fms, fnms

  **/
  const boost::dispatch::functor<tag::fnma_> fnma = {};
} }
#endif

#include <boost/simd/function/scalar/fnma.hpp>
#include <boost/simd/function/simd/fnma.hpp>

#endif
