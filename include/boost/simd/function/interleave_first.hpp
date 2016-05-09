//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED

namespace boost { namespace simd
{
#if defined(DOXYGEN_ONLY)
  /*!
    @ingroup group-swar
    Function object implementing interleave_first capabilities

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of types respectively T, the following code:

    @code
    T r = interleave_first(a,b);
    @endcode

    is equivalent to :

    @code
    r = [ a[0] b[0] a[1] b[1] ... a[n/2-1] b[n/2-1] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>

  **/
  const boost::dispatch::functor<tag::interleave_first_> interleave_first = {};
#endif
} }

#include <boost/simd/function/simd/interleave_first.hpp>

#endif
