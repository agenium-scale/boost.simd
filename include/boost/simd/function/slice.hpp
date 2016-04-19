//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SLICE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SLICE_HPP_INCLUDED

namespace boost { namespace simd
{
#if defined(DOXYGEN_ONLY)
  /*!
    @ingroup group-swar
    Type-preserving pack slicing

    This function object slices a simd::pack into two simd::pack of same type but twice as small.

    @par Semantic:

    For any value @c a of type @c T , the following code:

    @code
    auto c = slice(a);
    @endcode

    returns an array type which behaves so that:

    @code
    compare_equal(a, combine(c[0],c[1]));
    @endcode

    evaluates to @c true.

    @see combine
    @see slice_low
    @see slice_high
  **/
  const boost::dispatch::functor<tag::slice_> slice = {};
#endif
} }

#include <boost/simd/function/simd/slice.hpp>

#endif
