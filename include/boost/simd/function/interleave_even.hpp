//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED

namespace boost { namespace simd
{
#if defined(DOXYGEN_ONLY)
  /*!
    @ingroup group-swar
    Function object implementing interleave_even capabilities

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of types respectively T0:

    @code
    T0 r = interleave_even(a,b);
    @endcode

    is equivalent to :

    @code
    r = [ a[0] b[0] a[2] b[2] ... a[n/2] b[n/2] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>

  **/
  const boost::dispatch::functor<tag::interleave_even_> interleave_even = {};
#endif
} }

#include <boost/simd/function/simd/interleave_even.hpp>

#endif
