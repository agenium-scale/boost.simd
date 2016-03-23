//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CONJ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CONJ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing conj capabilities

    Computes the conjugate value of its parameter (identity for reals).

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = conj(x);
    @endcode

    for real parameters is equivalent to:

    @code
    T r = x
    @endcode

    This function is the restriction to real numbers of the complex
    conj(ugate) function.

  **/
  const boost::dispatch::functor<tag::conj_> conj = {};
} }
#endif

#include <boost/simd/function/scalar/conj.hpp>

#include <boost/simd/function/simd/conj.hpp>

#endif
