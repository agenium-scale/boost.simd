//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMBINE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMBINE_HPP_INCLUDED

namespace boost { namespace simd
{
#if defined(DOXYGEN_ONLY)
  /*!
    @ingroup group-swar
    Type-preserving pack concatenation

    This function object concatenates two values of the same type to build a simd::pack of the
    same type but twice as large.

    @par Semantic:

    For any value @c a and @c b of type @c T , the following code:

    @code
    auto c = combine(a,b);
    @endcode

    is equivalent to :

    @code
    pack<T, 2> c(a,b);
    @endcode

    if @c T is a scalar type.

    Otherwise, it's equivalent to:

    @code
    pack<T,2*N> c(a[0],....,a[N-1],b[0],....,b[N-1]);
    @endcode

    where @c N is equal to the simd::cardinal of @c a.

    @see slice
    @see group
    @see groups
  **/
  const boost::dispatch::functor<tag::combine_> combine = {};
#endif
} }

#include <boost/simd/function/simd/combine.hpp>

#endif
