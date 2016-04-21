//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic
    Function object function implementing fma capabilities

    Computes the (fused) multiply add of the three parameters.

    @par semantic:
    For any given value @c x,  @c y,  @c z of type @c T:

    @code
    T r = fma(x, y, z);
    @endcode

    The code is similar to:

    @code
    T r = x*y+z;
    @endcode

    @par Note
    Correct fused multiply/add implies

    - only one rounding

    - no "intermediate" overflow

    fma provides this each time it is reasonable
    in terms of performance (mainly if the system has the hard
    wired capability).

    If you need "real" fma capabilities in all circumstances in your own
    code you can use correct_fma (although it can be expansive).

    Also :


    - fma(x, y, z, nooverflow_) provides a "only one rounding" mode but does not care for possible
    intermediate overflow.

    @par Decorators

    std_ for floating entries

    @par Alias

    @c madd

    @see  correct_fma, fms, fnma, fnms
  **/
    const boost::dispatch::functor<tag::fma_> fma = {};
  }
} }
#endif

#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/function/simd/fma.hpp>

#endif
